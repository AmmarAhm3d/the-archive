#include <iostream>
#include <omp.h>
using namespace std;

// to compile and run, then delete the executable
// g++ lec10.cpp -fopenmp -o lec10 && ./lec10 && rm lec10

int main()
{
	double area, pi, x;
	int i, n = 5;
	area = 0.0;
#pragma omp parallel for private(x)
	for (i = 0; i < n; i++) {
		x = (i + 0.5) / n;
#pragma omp critical
		area += 4.0 / (1.0 + x * x);
	}
	pi = area / n;

	cout << "pi is " << pi << " in main thread" << endl;

	int workers = omp_get_max_threads(); //can use num_procs
	cout << workers << " maximum allowed threads\n" << endl;

	cout << "total number of allocated cores are:" << omp_get_num_procs() << endl;
	//////////////////////////////////////////
	///// omp_set_dynamic();

	omp_set_dynamic(0);
	omp_set_num_threads(n);
	cout << "total number of requested when dynamic is true are:" << n << endl;

	x = 0;
#pragma omp parallel 
	{
#pragma omp single nowait
		cout << "total threads in parallel region1=" << omp_get_num_threads() << endl;
#pragma omp for 
		for (i = 0; i < n; i++)
		{
			x += i;
		}
	}

	cout << "value of x when dnamic is true: " << x << endl;

	//////////////////////////////////////////
	///// omp_set_nested();

	cout << "\n\n\n value of x when omp_set_nested is true: " << endl;
	omp_set_dynamic(0);
	omp_set_nested(1); // depricated
	
#pragma omp parallel num_threads(2)
	{
#pragma omp single
		printf("Level 1: number of threads in the team : %d\n", omp_get_num_threads());

#pragma omp parallel num_threads(4)
		{
#pragma omp single
			printf("Level 2: number of threads in the team : %d\n", omp_get_num_threads());
		}
	}


	///////////////////////////////////////////////
	// Monte carlo estimation
	int num_threads, chunk_size, count, niter;
	niter = 1000000;
	double x1, y1, z1;
#pragma omp parallel shared(niter) private(i, x1, y1, z1, chunk_size) reduction(+ : count)
	{
		num_threads = omp_get_num_threads();
		chunk_size = niter / num_threads;
		
#pragma omp master
		{ 
			printf("chunk_size=%ld\n", chunk_size); 
		}

		count = 0;
		for (i = 0; i < chunk_size; i++)
		{
			//get random points
			x1 = (double)rand() / (double)RAND_MAX;
			y1 = (double)rand() / (double)RAND_MAX;
			z1 = ((x1 - 0.5) * (x1 - 0.5)) + ((y1 - 0.5) * (y1 - 0.5));
			//check to see if point is in unit circle
			if (z1 < 0.25)
			{
				++count;
			}
		}
	}
	double pie = ((double)count / (double)niter) * 4.0;

	cout << " \n value of pi afer Monte carlo estimation is: " << pie << endl;


}