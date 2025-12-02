// To compile: gcc -fopenmp openmp.c -o omp && ./omp

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// int main() {
//     int i;
//     #pragma omp parallel for
//     for (i = 0; i < 10; i++) {
//         printf("Thread %d: %d\n", omp_get_thread_num(), i);
//     }
//     return 0;
// }

// int main(int argc, char *argv[]) {
//     int b[3];
//     char* cptr;
//     int i;

//     cptr = malloc(1);
//     #pragma omp parallel for
//     for (i = 0; i < 3; i++) {
//         b[i] = i;
//         cptr[0] = i;
//         printf("Thread %d: %d\n", omp_get_thread_num(), i);
//     }
// }

// int main(){;

// int procs,i,a,b,c,t,m;

// // Determine the number of physical processors

// procs = omp_get_num_procs();

// printf("%d processors/cores\n",procs);

// /* Determine max threads defined by default

// through the OMP_NUM_THREADS environment variable */

// printf("OMP_NUM_THREADS = %d\n",omp_get_max_threads());

// #pragma omp parallel

// printf("Hello from thread id %d\n",omp_get_thread_num());

// }

// #define MIN(a, b) ((a) < (b) ? (a) : (b))

// int main()
// {
//     // a clause is an optional , additional component to a pragma
//     // Privat: the private clause directs the compiler to make one or more variables private to each thread
//     int i, j, n = 100;
//     int a[n][n];
//     int tmp = 0;

//     int k = 3;

// #pragma omp parallel for default(shared) private(j) shared(k)

//     for (i = 0; i < n; i++)

//         for (j = 0; j < n; j++)

//             a[i][j] = MIN(a[i][j], a[i][k] + tmp);

//             // problem in code: k is shared by default, but it is modified by the threads
//             // solution: add k to the private clause
// }