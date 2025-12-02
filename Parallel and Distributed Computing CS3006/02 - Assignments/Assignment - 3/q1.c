#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

// to compile and run:
// mpicc q1.c -o q1 && mpirun -np 4 ./q1

#define MATRIX_SIZE 4

int main(int argc, char* argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Initialize local row (each process holds one row)
    int local_row[MATRIX_SIZE];
    // individual row values are hardcoded for each process
    if (rank == 0) {
        int temp_row[MATRIX_SIZE] = {1, 3, 5, 7};
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            local_row[i] = temp_row[i];
        }
    } else if (rank == 1) {
        int temp_row[MATRIX_SIZE] = {2, 4, 6, 8};
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            local_row[i] = temp_row[i];
        }
    } else if (rank == 2) {
        int temp_row[MATRIX_SIZE] = {11, 13, 15, 17};
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            local_row[i] = temp_row[i];
        }
    } else if (rank == 3) {
        int temp_row[MATRIX_SIZE] = {12, 14, 16, 18};
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            local_row[i] = temp_row[i];
        }
    }
    // Compute local transposed row
    int local_transposed_row[MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        local_transposed_row[i] = local_row[i];
    }

    // Exchange rows
    for (int i = 0; i < size; ++i) {
        int target_rank = (rank + i) % size; // target rank to send to calculated as (rank + i) % size
        // mpi sendrecv replace is used to send and receive data in a single call
        MPI_Sendrecv_replace(local_transposed_row, MATRIX_SIZE, MPI_INT, target_rank, 0, (rank - i + size) % size, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    // Print the transposed row
    printf("Process %d: Transposed row = ", rank);
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        printf("%d ", local_transposed_row[i]);
    }
    printf("\n");

    MPI_Finalize();
    return 0;
}