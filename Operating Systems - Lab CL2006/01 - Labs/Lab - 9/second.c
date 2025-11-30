#include <stdio.h>
#include <stdlib.h>
# include <pthread.h>

int n;
int num_threads;

void *sumFunc(void *arg) {
    int thread_num = *(int *)arg;
    int sum = 0;
    for (int i = thread_num; i <= n; i += num_threads) {
        sum += i;
    }
    int *result = malloc(sizeof(int));
    *result = sum;
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    n = atoi(argv[1]);
    // specify the number of threads for multithreading
    num_threads = 1;
    pthread_t threads[num_threads];
    int thread_nums[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_nums[i] = i + 1;
        if (pthread_create(&threads[i], NULL, sumFunc, &thread_nums[i]) != 0) {
            fprintf(stderr, "Error creating thread\n");
            exit(EXIT_FAILURE);
        }
    }

    int total_sum = 0;
    for (int i = 0; i < num_threads; i++) {
        int *result;
        if (pthread_join(threads[i], (void **)&result) != 0) {
            fprintf(stderr, "Error joining thread\n");
            exit(EXIT_FAILURE);
        }
        total_sum += *result;
        free(result);
    }

    printf("Sum: %d\n", total_sum);

    return 0;
}