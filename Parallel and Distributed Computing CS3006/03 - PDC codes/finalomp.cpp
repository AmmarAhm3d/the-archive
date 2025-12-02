#include <mpi.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    MPI_Init(NULL, NULL);
    MPI_Status status;
    int p, recVal, my_rank, neighbor;
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    int *d_val = new int[p];
    int myVal = pow(2, my_rank + 1); // 2^(my_rank+1)
    int sTag = my_rank;
    if (my_rank % 2 == 0)
        neighbor = (my_rank + 1) % p;
    else
        neighbor = (my_rank - 1) % p;
    MPI_Sendrecv(&myVal, 1, MPI_INT, neighbor, sTag, &recVal, 1, MPI_INT, neighbor, neighbor,
                 MPI_COMM_WORLD, &status);
    int diff = abs(myVal - recVal); // absolute value
    if (my_rank > 0 && my_rank < (p - 1))
    {
        if (my_rank % 2 == 1)
            neighbor = (my_rank + 1) % p;
        else
            neighbor = (my_rank - 1) % p;
        MPI_Sendrecv(&myVal, 1, MPI_INT, neighbor, sTag, &recVal, 1, MPI_INT, neighbor, neighbor,
                     MPI_COMM_WORLD, &status);
        if (abs(myVal - recVal) > diff)
            diff = abs(myVal - recVal);
    }
    MPI_Gather(&diff, 1, MPI_INT, d_val, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (my_rank == 0)
    {
        int dmax = d_val[0];
        for (int i = 1; i < p; i++)
        {
            printf("d_val[%d] = %d \n", i, d_val[i]);
            if (d_val[i] > dmax)
                dmax = d_val[i];
        }
        printf("\n Max = %d\n", dmax);
    }
    MPI_Finalize(); // Finalize the MPI environment.
}
