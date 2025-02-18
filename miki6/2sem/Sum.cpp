#include <iostream>
#include <pthread.h>

void* result(void* ptr);

using pair = int[2];

int main (int argc, char* argv[]) {

    if (argc != 3) {
        std::cout << "You need to enter 2 arguments! \n";
        return 1;
    }

    int number_of_threads = int(atoi(argv[1]));
    unsigned* arg = (unsigned*)calloc(number_of_threads, sizeof(arg[0]));
    int N = int(atoi(argv[2]));
    int for_each = N / number_of_threads;
    double sum = 0;
    double offset = N % number_of_threads;

    pair sizes;
    sizes[0] = 0;
    sizes[1] = for_each + offset;
    pthread_t thread;
    pthread_create(&thread, NULL, result, (void*)&sizes);
    double* new_sum = 0;
    pthread_join(thread, (void**)&new_sum);
    sum += *new_sum;
    free(new_sum);

    for (int i = 1; i < number_of_threads; i++) {
        pair sizes;
        sizes[0] = for_each * i + offset;
        sizes[1] = sizes[0] + for_each;
        pthread_t thread;
        //printf("Thread %d makes sum = %f\n", i, sum);

		int res_1 = pthread_create(&thread, NULL, result, (void*)&sizes);
        if (res_1) {
            printf("ERROR; return code from pthread_create() is %d\n", res_1);
            exit(-1);
        }
        
        double* new_sum = 0;

        int res_2 = pthread_join(thread, (void**)&new_sum);
        if (res_2) {
            printf("ERROR; return code from pthread_join() is %d\n", res_2);
            exit(-1);
        }
        sum += *new_sum;
        free(new_sum);
    }

    std::cout << "Sum is = " << sum << "\n";
    return 0;
}

void* result(void* ptr) {
    int* sizes = (int*)ptr;
    double* sum = new double;
    for (int i = sizes[0] + 1; i <= sizes[1]; i++) {
            *sum += 1.0 / (double)i;
    }
    
    pthread_exit((void*)sum);
}
