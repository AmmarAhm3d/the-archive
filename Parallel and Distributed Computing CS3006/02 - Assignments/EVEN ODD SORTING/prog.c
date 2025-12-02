#include <stdlib.h>
#include <mpi/mpi.h> /* Include MPI header file */

// TO COMPILE AND RUN:
// mpicc -o prog prog.c && mpirun -np 4 ./prog 100
// variables have been renamed as per submission guidelines

int IncOrder(const void *e1, const void *e2);
void CompareSplit(int nlocal, int *elmnts_0961, int *relmnts_0961, int *wspace, int keepsmall);

int main (int argc, char *argv[]) {
    int n_0961; /* The total number of elements to be sorted */
    int npes_0961; /* The total number of processes */
    int myrank_0961; /* The rank of the calling process */
    int nlocal_0961; /* The local number of elements, and the array that stores them */
    int *elmnts_0961; /* The array that stores the local elements */
    int *relmnts_0961; /* The array that stores the received elements */
    int oddrank_0961; /* The rank of the partner during odd-phase communication */
    int evenrank_0961; /* The rank of the partner during even-phase communication */
    int *wspace_0961; /* Working space during the compare-split operation */
    MPI_Status status_0961; /* Status of the communication */
    int i; /* Loop index */

    /* Initialize MPI and get system information */
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &npes_0961);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank_0961);

    n_0961 = atoi(argv[1]);
    nlocal_0961 = n_0961 /npes_0961; /* Compute the number of elements to be stored locally. */

    /* Allocate memory for the various arrays */
    elmnts_0961 = (int *) malloc(nlocal_0961 * sizeof(int));
    relmnts_0961 = (int *) malloc(nlocal_0961 * sizeof(int));
    wspace_0961 = (int *) malloc(nlocal_0961 * sizeof(int));

    /* Fill in the elemnts array with random values */
    srandom(myrank_0961);
    for (i = 0; i < nlocal_0961; i++){
        elmnts_0961[i] = random();
    }

    /* Sort the local elements using built-in quicksort */
    qsort(elmnts_0961, nlocal_0961, sizeof(int), IncOrder);

/*  Determining communication partner during Even and odd steps of
    the algorithm.

    If my partner is out of bounds, then set it to NULL process.*/
    if (myrank_0961 % 2 != 0) {
        oddrank_0961 = myrank_0961 - 1;
        evenrank_0961 = myrank_0961 + 1;
    } else {
        oddrank_0961 = myrank_0961 + 1;
        evenrank_0961 = myrank_0961 - 1;
    }

    /* Set the ranks of the processors at the end of the linear */
    if (oddrank_0961 == -1 || oddrank_0961 == npes_0961) oddrank_0961 = MPI_PROC_NULL;
    if (evenrank_0961 == -1 || evenrank_0961 == npes_0961) evenrank_0961 = MPI_PROC_NULL;

/*  P steps for the actual algorithm
*/ 
    /* Get into the main loop of the odd-even sorting algorithm */
    for (i = 0; i < npes_0961 - 1; i++) {
        if (i % 2 == 1) { /* Odd phase */
            MPI_Sendrecv(elmnts_0961, nlocal_0961, MPI_INT, oddrank_0961, 1, relmnts_0961, nlocal_0961, MPI_INT, oddrank_0961, 1, MPI_COMM_WORLD, &status_0961);
        } else { /* Even phase */
            MPI_Sendrecv(elmnts_0961, nlocal_0961, MPI_INT, evenrank_0961, 1, relmnts_0961, nlocal_0961, MPI_INT, evenrank_0961, 1, MPI_COMM_WORLD, &status_0961);
        }

        /* Perform the compare-split operation */
        CompareSplit(nlocal_0961, elmnts_0961, relmnts_0961, wspace_0961, myrank_0961 < status_0961.MPI_SOURCE);
    }
    free(elmnts_0961); free(relmnts_0961); free(wspace_0961);
    MPI_Finalize();
}

/* The CompareSplit function that is used by the odd-even sorting algorithm */
void CompareSplit(int nlocal, int *elmnts, int *relmnts, int *wspace, int keepsmall) {
    int i, j, k;
    for (i = 0; i < nlocal; i++) {
        wspace[i] = elmnts[i]; /* Copy the local elmnts array into the working space array */
    }
    if (keepsmall) { /* Keep the nlocal smaller elements */
        for (i = j = k = 0; k < nlocal; k++) {
            if (j == nlocal || (i < nlocal && wspace[i] < relmnts[j])) {
                elmnts[k] = wspace[i++];
            } else {
                elmnts[k] = relmnts[j++];
            }
        }
    } else { /* Keep the nlocal larger elements */
        for (i = j = k = nlocal - 1; k >= 0; k--) {
            if (j == 0 || (i >= 0 && wspace[i] >= relmnts[j])) {
                elmnts[k] = wspace[i--];
            } else {
                elmnts[k] = relmnts[j--];
            }
        }
    }
}
/* the IncOrder function that is used by the built-in quicksort */
int IncOrder(const void *e1, const void *e2) {
    return (*((int *) e1) - *((int *) e2));
}