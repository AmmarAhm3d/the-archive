#include <mpi.h>
#include <stdio.h>

// to compile: mpicc -o sendReceive_simult sendReceive_simult.c -lm -std=c99 -Wall && mpirun -n 4 ./sendReceive_simult && rm sendReceive_simult

// here we have 4 processes, and each process sends a message to the next process and receives a message from the previous process
// the message sent is the rank of the sending process
// and next and previous are calculated using the formula next=(my_rank+1)%p and previous=((my_rank-1+p)%p) (which simulate a ring topology)
// the rank 0 will reveive from rank 3 and send to rank 1 its rank (0)
// the rank 1 will reveive from rank 0 and send to rank 2 its rank (1)
// the rank 2 will reveive from rank 1 and send to rank 3 its rank (2)
// the rank 3 will reveive from rank 2 and send to rank 0 its rank (3)

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc,&argv);
    
 MPI_Status status;	
    // Get the number of processes -> how many processes are to be created
    int p;
	int i;
	//MPI_COMM_WORLD is an communicator object that contains all the processes
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	
	int a=my_rank;
	int b;	
	int sendTag=1;
	int recvTag=1;
	
		int next=(my_rank+1)%p; //determine my right node
		int previous=((my_rank-1+p)%p); //determine my left node	
		MPI_Sendrecv(&a,1,MPI_INT,next,sendTag,
					 &b,1,MPI_INT,previous,recvTag, MPI_COMM_WORLD, &status );
			
		printf("I\'m %d: Received:%d from %d and Sent:%d to %d\n ",my_rank ,b,previous, a,next);
    // Finalize the MPI environment.
    MPI_Finalize();
}
