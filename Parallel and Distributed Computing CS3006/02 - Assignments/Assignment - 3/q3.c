#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
// to compile and run:
// mpicc q3.c -o q3 && mpirun -np {m} ./q3 {m} {n}
// IMPORTANT: m should be equal to the number of processes
// the reason being that m will be distributed over m processes

// shell command to zip all files in directory: zip -r <zipfile> ./*

// Function to sort an array using merge sort
void mergeSort(int* arr, int l, int r);
void merge(int* arr, int l, int m, int r);

int main(int argc, char** argv) {
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // or set the m and n values from command line arguments
    int m = argc > 1 ? atoi(argv[1]) : 5; // set the number of rows else default to 5
    int n = argc > 2 ? atoi(argv[2]) : 5; // set the number of columns else default to 5
    // int m = 5; // number of rows
    // int n = 5; // number of columns
    int matrix[m][n];
    int product[m];

    if (rank == 0) {
        // Initialize the matrix with random values, limit to 1-10
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = rand() % 10 + 1;
            }
        }
        // Print the matrix
        printf("Matrix:\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }

    // Distribute the rows to all processes
    int row[n];
    // Scatter the matrix to all processes
    MPI_Scatter(matrix, n, MPI_INT, row, n, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process sorts the assigned row
    mergeSort(row, 0, n - 1);

    // Collect sorted rows from all processes to process 0
    MPI_Gather(row, n, MPI_INT, matrix, n, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process calculates the product of its row
    long long row_product = 1; // long long to store the product of all elements and avoid overflow
    for (int i = 0; i < n; i++) {
        row_product *= row[i];
    }

    // Reduce at process 0 to find the product of the complete matrix
    long long total_product; // long long to store the product of all elements and avoid overflow
    // MPI reduce will multiply all the row products to get the total product
    MPI_Reduce(&row_product, &total_product, 1, MPI_LONG_LONG_INT, MPI_PROD, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Product of the complete matrix: %lld\n", total_product);
    }

    MPI_Finalize();
    return 0;
}

void mergeSort(int* arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
