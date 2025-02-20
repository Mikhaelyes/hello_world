#include "../headers/header.h"
double zoom = 1;


int main() {

    //window - объект главного окна приложения типа RenderWindow
    sf::RenderWindow window(sf::VideoMode(1680, 1050), "Space adventure");
    sf::View windowView = window.getView();

    std::vector<Planet> planets;
    Ship ship;
    Velocity shipV;
    Point shipP;

    bool isViewMove = false;
    bool viewFlag = true;
    sf::Vector2f mousePos;

    float wantFps = 600;

    sf::Clock loopTimer;

    //Индикаторы посадки dockInd = 0 - свободный полёт, 1 - посадка
    int dockInd = 0;
    int dockPlanet = -1;
    //Главный цикл приложения который выпоняется пока открыто окно
    bool isMenu = true;
    bool newGame = true;
    while (window.isOpen()) {
        if (isMenu) {
            isMenu = mainMenu(window, planets, ship, newGame);
        } else {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                } else if (event.type == sf::Event::MouseWheelScrolled) {
                    sf::Vector2f viewMove = window.mapPixelToCoords(sf::Mouse::getPosition(window), windowView) -
                                            windowView.getCenter();
                    viewMove.x *= 0.05 * event.mouseWheelScroll.delta;
                    viewMove.y *= 0.05 * event.mouseWheelScroll.delta;
                    windowView.zoom(event.mouseWheelScroll.delta > 0 ? 0.95 : 1 / 0.95);
                    zoom *= event.mouseWheelScroll.delta > 0 ? 0.95 : 1 / 0.95;
                    windowView.move(viewMove);
                } else if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left && !isViewMove) {
                        mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), windowView);
                        isViewMove = true;
                    }
                } else if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        isViewMove = false;
                    }
                } else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        isMenu = true;
                    }
                } else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S) {
                    viewFlag = !viewFlag;
                }
            }

            //Управление кораблем
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                shipV.setX(ship.getVel().getX() - 5.1);
                shipV.setY(ship.getVel().getY());
                ship.setVel(shipV);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                shipV.setX(ship.getVel().getX() + 5.1);
                shipV.setY(ship.getVel().getY());
                ship.setVel(shipV);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                shipV.setX(ship.getVel().getX());
                shipV.setY(ship.getVel().getY() - 5.1);
                ship.setVel(shipV);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                shipV.setX(ship.getVel().getX());
                shipV.setY(ship.getVel().getY() + 5.1);
                ship.setVel(shipV);
            }

            if (dockInd == 1) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    //          shipV = ship.getVel() + 1 * radVelocity(planets[dockPlanet], ship);
                    //          ship.setVel(shipV);
                    shipP = ship.getCoord() + 3 * radVelocity(planets[dockPlanet], ship);
                    ship.setCoord(shipP);
                    dockInd = 0;
                    dockPlanet = -1;
                }
            }

            //Упраление камерой
            if (isViewMove) {
                windowView.move(mousePos - window.mapPixelToCoords(sf::Mouse::getPosition(window), windowView));
                mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), windowView);
            }
            if (viewFlag) {
                windowView.setCenter(ship.getCoord().getX(), ship.getCoord().getY());
            }

            //Отрисовка окна
            window.clear(sf::Color(0x0e, 0x0e, 0x57));
            for (int i = 0; i < planets.size(); ++i) {
                window.draw(planets[i].getCircle());
            }
            window.draw(ship.getShape());

            window.setView(windowView);
            window.display();
            //Обработка столкновений

            for (int i = 0; i < planets.size(); ++i) {
                if (high(planets[i], ship) <= 5 && relVelocity(planets[i], ship).mod() > 50) {
                    isMenu = newGame = true;
                }
                if (high(planets[i], ship) <= 5 && relVelocity(planets[i], ship).mod() <= 50) {
                    dockInd = 1;
                    dockPlanet = i;
                    ship.setVel(planets[i].getVel());
                    ship.setCoord(dockPoint(planets[i], ship));
                }
            }
            //Измеение положений тел
            for (int i = 0; i < planets.size(); ++i) {
                for (int j = i + 1; j < planets.size(); ++j) {
                    changeVelocity(planets[i], planets[j]);
                    if (dockInd == 0) {
                        changeVelocity(planets[i], ship);
                    } else {
                        ship.setVel(planets[dockPlanet].getVel());
                    }
                }
            }

            ship.setCoord({ship.getCoord().getX() + ship.getVel().getX() * DT,
                           ship.getCoord().getY() + ship.getVel().getY() * DT});
            for (int i = 0; i < planets.size(); ++i) {
                planets[i].setCoord({planets[i].getCoord().getX() + planets[i].getVel().getX() * DT,
                                     planets[i].getCoord().getY() + planets[i].getVel().getY() * DT});
            }
        }

        sf::Int32 frameDuration = loopTimer.getElapsedTime().asMilliseconds();
        sf::Int32 timeToSleep = int(1000.f/wantFps) - frameDuration;
        if (timeToSleep > 0) {
            sf::sleep(sf::milliseconds(timeToSleep));
        }
        loopTimer.restart();
    }
    return 0;
}
