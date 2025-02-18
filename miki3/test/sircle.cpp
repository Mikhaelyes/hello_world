#include <SFML/Graphics.hpp>
 
using namespace sf; // подключаем пространство имен sf
 
int main()
{	
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(200, 200), "SFML Works!");
 
	// Главный цикл приложения: выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				window.close(); // тогда закрываем его
		}
		// Установка цвета фона
		window.clear(Color(250, 220, 100, 0));
 
		// Создаем фигуру - круг радиусом 50
		CircleShape circle(50.f, 30);
		
		// Закрашиваем наш круг 
		circle.setFillColor(Color(230, 0, 230));
 
		// Отрисовка круга
		window.draw(circle);
		
		// Отрисовка окна
		window.display();
	}
 
	return 0;
}
