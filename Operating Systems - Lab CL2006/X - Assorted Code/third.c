#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *fibseries=NULL;
int n;

void *fibonacciGenerator(void *param) {
    int n = *(int *)param;
    fibseries = (int *)malloc(n * sizeof(int));
    fibseries[0] = 0;
    fibseries[1] = 1;
    for (int i = 2; i < n; i++) {
        fibseries[i] = fibseries[i - 1] + fibseries[i - 2];
    }
    printf("ID = %ld, Series: ", pthread_self());
    for (int i = 0; i < n; i++) {
        printf("%d ", fibseries[i]);
    }
    printf("\n");
    pthread_exit(0);
}

void *evenCounter(void *param) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (fibseries[i] % 2 == 0) {
            count++;
        }
    }
    printf("ID = %ld, Even Numbers: %d\n", pthread_self(), count);
    pthread_exit(0);
}

void *oddCounter(void *param) {
    int count = 0;
    for (int i = 0; i < n; i++) 
        if (fibseries[i] % 2 != 0) 
            count++;

    printf("ID = %ld, Odd Numbers: %d\n", pthread_self(), count);
    pthread_exit(0);
}

void *sumCalculator(void *param) {
    int sum = 0;
    for (int i = 0; i < n; i++) 
        sum += fibseries[i];
    
    FILE *file = fopen("sum.txt", "w");
    fprintf(file, "%d", sum);
    fclose(file);
    printf("ID = %ld, Sum: %d\n", pthread_self(), sum);
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: ./third <integer value>\n");
        return -1;
    }

    n = atoi(argv[1]);

    if (n < 0) {
        fprintf(stderr, "Argument %d must be non-negative\n", n);
        return -1;
    }

    pthread_t tid1, tid2, tid3, tid4;
    // pthread_attr is a data structure to contain the thread attributes
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid1, &attr, fibonacciGenerator, &n);
    pthread_join(tid1, NULL);

    pthread_create(&tid2, &attr, evenCounter, NULL);
    pthread_join(tid2, NULL);

    pthread_create(&tid3, &attr, oddCounter, NULL);
    pthread_join(tid3, NULL);

    pthread_create(&tid4, &attr, sumCalculator, NULL);
    pthread_join(tid4, NULL);

    free(fibseries);

    return 0;
}