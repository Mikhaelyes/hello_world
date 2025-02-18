#include <iostream>
#include <pthread.h>
#include <assert.h>

void* Mutex(void* dummy);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;
int delta = 0;

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("You need to enter the number of threads! \n");
		return 0;
    }

    unsigned number_of_threads = unsigned(atoi(argv[1]));

    std::cout << "Введите переменную с клавиатуры: ";
    std::cin >> counter;

    std::cout << "Введите разницу, которую будем прибавлять: ";
    std::cin >> delta;

    pthread_t* thread_id = (pthread_t*)calloc(number_of_threads, sizeof(thread_id[0]));
	unsigned* arg = (unsigned*)calloc(number_of_threads, sizeof(arg[0]));


    for (unsigned i = 0; i < number_of_threads; i++) {
        printf("Creating thread %d\n", i);
		arg[i] = i;
		int res = pthread_create(&(thread_id[i]), NULL, Mutex, (void*)&(arg[i]));
        if (res) {
            printf("ERROR; return code from pthread_create() is %d\n", res);
            exit(-1);
        }
	}

	for (unsigned i = 0; i < number_of_threads; i++) {
		int res = pthread_join(thread_id[i], NULL);
        if (res) {
            printf("ERROR; return code from pthread_join() is %d\n", res);
            exit(-1);
        }
	}

    return 0;
}

void* Mutex(void* dummy) {
    pthread_mutex_lock(&mutex);
    std::cout << "Number is: " << counter << "\n";
    counter = counter + delta;
    pthread_mutex_unlock(&mutex);
    return NULL;
}
