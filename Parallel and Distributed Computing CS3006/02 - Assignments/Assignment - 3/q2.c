#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

// //////////////////////////////////////////
// IMPORTANT: due to the way MPI handles STDIN, please input the row and column values with newline
// 1. m
// 2. n
// 3. matrix elements
// //////////////////////////////////////////
// to compile and run:
// mpicc q2.c -o q2 && mpirun -np 4 ./q2
// a test driver is given, which can be used to test the program
// the test driver can be run using:
// ./q2 < TEST


// Function to find the minimum value in an array
int findMin(int *array, int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Function to find the maximum value in an array
int findMax(int *array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Function to perform Quick Sort on an array
void quickSort(int *array, int low, int high) {
    if (low < high) {
        int pivot = array[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (array[j] < pivot) {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        int pi = i + 1;

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Function to sort an array using Quick Sort
void sortArray(int *array, int size) {
    quickSort(array, 0, size - 1);
}

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // eat empty line
    int m, n;
    if (rank == 0) {
        printf("Enter the number of rows (m): ");
        fflush(stdout); // flush the output buffer
        scanf("%d", &m);
        printf("Enter the number of columns (n): ");
        fflush(stdout); // flush the output buffer
        scanf("%d", &n);
    }

    // broadcast the row and column values
    // so that all processes know the size of the matrix
    // reason for this is that the matrix is broadcasted later
    // and all processes need to know the size of the matrix
    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int *matrix = (int *)malloc(m * n * sizeof(int));

    if (rank == 0) {
        printf("Enter the matrix elements:\n");
        fflush(stdout); // flush the output buffer
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &matrix[i * n + j]);
            }
        }
    }

    // broadcast the matrix elements
    MPI_Bcast(matrix, m * n, MPI_INT, 0, MPI_COMM_WORLD);

    // Sort each row using Quick Sort
    for (int i = 0; i < m; i++) {
        if (rank == i % size) {
            // quick sort the matrix row
            sortArray(&matrix[i * n], n);
            if (rank != 0) {
                MPI_Send(&matrix[i * n], n, MPI_INT, 0, 0, MPI_COMM_WORLD);
            }
        }
        // Wait for all processes to finish sorting
        MPI_Barrier(MPI_COMM_WORLD);
    }

    if (rank == 0) {
        for (int i = 0; i < m; i++) {
            if (i % size != 0) { // If the row is not sorted by the process
                // Receive the sorted row from the corresponding process
                MPI_Recv(&matrix[i * n], n, MPI_INT, i % size, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            }
        }
    }

    if (rank == 0) {
        printf("Sorted matrix:\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", matrix[i * n + j]);
            }
            printf("\n");
        }

        // Find the minimum and maximum values in the matrix
        int min = findMin(matrix, m * n);
        int max = findMax(matrix, m * n);

        printf("Minimum value: %d\n", min);
        printf("Maximum value: %d\n", max);
    }

    free(matrix);

    MPI_Finalize();
    return 0;
}