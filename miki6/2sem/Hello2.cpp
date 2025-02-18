#include <iostream>
#include <pthread.h>
#include <assert.h>

void* print(void* ptr);

int main (int argc, char** argv) {

    unsigned number_of_threads = unsigned(atoi(argv[1]));

    if (number_of_threads == 1) {
        std::cout << "Not interesting with a single thread :) \n";
		return 0;
    }

    pthread_t* thread_id = (pthread_t*)calloc(number_of_threads, sizeof(thread_id[0]));
	unsigned* arg = (unsigned*)calloc(number_of_threads, sizeof(arg[0]));

    for (unsigned i = 0; i < number_of_threads; i++) {
        printf("Creating thread %d\n", i);
		arg[i] = i;
		int res = pthread_create(&(thread_id[i]), NULL, print, (void*)&(arg[i]));
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
	
	free(thread_id);
	free(arg);
	return 0;
}

void* print(void* ptr) {
    unsigned number = *((unsigned*)ptr);
    printf("Hello from thread %u; number = %lu \n", number, pthread_self());
    return NULL;
}
