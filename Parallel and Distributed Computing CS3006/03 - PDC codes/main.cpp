#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h> 

// to compile this program use the following command
// gcc -fopenmp main.cpp -o omp && ./omp

// this is our assignment 1 for the parallel and distributed computing course

#define SIZE 1000

// Function prototypes
double matrixProduct(int** matrix, int m, int n, int numThreads, int scheduleType, int chunkSize);

int main() {
    int m, n, i, j;
    double startTime, endTime;

    // Step 1: Take input for matrix size
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

// Allocate memory for the matrix
int** matrix = (int**)malloc(m * sizeof(int*));
for (i = 0; i < m; i++) {
    matrix[i] = (int*)malloc(n * sizeof(int));
}
    // Step 1: Initialize the matrix with random values
    srand(time(NULL)); // Seed for random number generator
    printf("Randomly initialized matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10; // Generates random number between 0 and 9
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Experiment 1: Static scheduling
    printf("\nExperiment 1: Static scheduling\n");
    printf("Number of Threads\tChunk Size\tElapsed Time (s)\n");
    for (int numThreads = 2; numThreads <= 4; numThreads++) {
        for (int chunkSize = 1; chunkSize <= 4; chunkSize++) {
            startTime = omp_get_wtime();
            matrixProduct(matrix, m, n, numThreads, 0, chunkSize);
            endTime = omp_get_wtime();
            printf("%d\t\t\t%d\t\t%.6f\n", numThreads, chunkSize, endTime - startTime);
        }
    }

    // Experiment 2: Dynamic scheduling
    printf("\nExperiment 2: Dynamic scheduling\n");
    printf("Number of Threads\tChunk Size\tElapsed Time (s)\n");
    for (int numThreads = 2; numThreads <= 4; numThreads++) {
        for (int chunkSize = 1; chunkSize <= 4; chunkSize++) {
            startTime = omp_get_wtime();
            matrixProduct(matrix, m, n, numThreads, 1, chunkSize);
            endTime = omp_get_wtime();
            printf("%d\t\t\t%d\t\t%.6f\n", numThreads, chunkSize, endTime - startTime);
        }
    }

    // Experiment 3: Guided scheduling
    printf("\nExperiment 3: Guided scheduling\n");
    printf("Number of Threads\tChunk Size\tElapsed Time (s)\n");
    for (int numThreads = 2; numThreads <= 4; numThreads++) {
        for (int chunkSize = 1; chunkSize <= 4; chunkSize++) {
            startTime = omp_get_wtime();
            matrixProduct(matrix, m, n, numThreads, 2, chunkSize);
            endTime = omp_get_wtime();
            printf("%d\t\t\t%d\t\t%.6f\n", numThreads, chunkSize, endTime - startTime);
        }
    }

    // Free allocated memory
    for (i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

// Function to calculate matrix product
double matrixProduct(int** matrix, int m, int n, int numThreads, int scheduleType, int chunkSize) {
    int product = 1;
    int i, j;

    omp_set_num_threads(numThreads);
    const char* schedules[] = {"static", "dynamic", "guided"};

if (strcmp(schedules[scheduleType], "static") == 0) {
        #pragma omp parallel for schedule(static, chunkSize) reduction(*:product)
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                product *= matrix[i][j];
            }
        }
        return product;
    } else if (strcmp(schedules[scheduleType], "dynamic") == 0) {
        #pragma omp parallel for schedule(dynamic, chunkSize) reduction(*:product)
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                product *= matrix[i][j];
            }
        }
        return product;
    } else if (strcmp(schedules[scheduleType], "guided") == 0) {
        #pragma omp parallel for schedule(guided, chunkSize) reduction(*:product)
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                product *= matrix[i][j];
            }
        }
        return product;
    }    
    return product;
}