#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>

// to compile and run: gcc -fopenmp main.c -o main && ./main

void quicksort(int *a, int n) {
    if (n <= 1) return;
    int p = a[n / 2];
    int *l = a;
    int *r = a + n - 1;
    while (l <= r) {
        if (*l < p) {
            l++;
            continue;
        }
        if (*r > p) {
            r--;
            continue;
        }
        int t = *l;
        *l = *r;
        *r = t;
        l++;
        r--;
    }
    quicksort(a, r - a + 1);
    quicksort(l, a + n - l);
}

int main() {
    int i, j, n = 100;
    int a[n][n];
    int tmp = 0;
    int m;
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);
    
    srand(time(NULL));
    // initialize matrix with random values
    for (i = 0; i < m; i++){
        
        for (j = 0; j < n; j++){
            a[i][j] = rand() % 10;
            printf("%d ",a[i][j]);    
        }
        printf("\n");
    }

    int numThreads = m;
    // Sort rows in ascending order
    #pragma omp parallel for num_threads(numThreads)
    for (i = 0; i < m; i++) {
        quicksort(a[i], n);
    }

    // Part B: Matrix multiplication

    int _num_threads = omp_get_max_threads(); // 8 from the system
    int num_threads[] = {2, 4, 8, 16};
    int chunk_sizes[] = {1, n/_num_threads, n, rand()%n};
    char* schedules[] = {"static", "dynamic", "guided"};

    printf("Chunk sizes used are: 1, n/num of threads(max threads), n(from mxn), and random mod n \n");
    printf("Schedule Threads Chunk Size Time\n");

    for (int s = 0; s < sizeof(schedules) / sizeof(char*); s++) {
        for (int t = 0; t < sizeof(num_threads) / sizeof(int); t++) {
            for (int c = 0; c < sizeof(chunk_sizes) / sizeof(int); c++) {
                omp_set_num_threads(num_threads[t]);

                double start = omp_get_wtime();
                int product = 1;
                if (strcmp(schedules[s], "static") == 0) {
                    #pragma omp parallel for schedule(static, chunk_sizes[c]) reduction(*:product)
                    for (i = 0; i < m; i++) {
                        for (j = 0; j < n; j++) {
                            product *= a[i][j];
                        }
                    }
                } else if (strcmp(schedules[s], "dynamic") == 0) {
                    #pragma omp parallel for schedule(dynamic, chunk_sizes[c]) reduction(*:product)
                    for (i = 0; i < m; i++) {
                        for (j = 0; j < n; j++) {
                            product *= a[i][j];
                        }
                    }
                } else if (strcmp(schedules[s], "guided") == 0) {
                    #pragma omp parallel for schedule(guided, chunk_sizes[c]) reduction(*:product)
                    for (i = 0; i < m; i++) {
                        for (j = 0; j < n; j++) {
                            product *= a[i][j];
                        }
                    }
                }
                double end = omp_get_wtime();

                printf("%s   %d\t %d\t    %f\n", schedules[s], num_threads[t], chunk_sizes[c], end - start);
            }
        }
    }

    return 0;
}
