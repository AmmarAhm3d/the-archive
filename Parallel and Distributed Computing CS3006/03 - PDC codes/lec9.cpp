#include <iostream>
#include <omp.h>
using namespace std; 

// to compile and run, then delete the executable
// g++ lec9.cpp -fopenmp -o lec9 && ./lec9 && rm lec9

// what is the code doing generally?
// we are doing the monte carlo approximation of pi using openmp

int alpha()
{
	return 5 * 5 * 5;
}

int beta()
{
	return 4 * 4 * 4;
}
int gamma(int a, int b)
{
	return a*b;
}
int delta()
{
	return 6 * 6 * 6;
}
int epsilon(int x, int b)
{
	return x * b;
}

int main()
{
	cout << "number of processors: " << omp_get_num_procs() << endl;
	cout << "number of threads: " << omp_get_num_threads() << endl;

	omp_set_num_threads(4);
//#pragma omp parallel

	{
		//cout << "number of threads: " << omp_get_num_threads() << endl;
	}

	int k = 3, i, j;
	int n = 4;
	int arr[4][4] = { 1234, 56,42,34,12, 1212, 33,31,30,29, 1434, 80,32,11,5, 1312 };
	int arr1[4][4] = {};

	/////////////////////////////////////////////
		//         default   private   shared 
	cout << "\n\n default   private   shared " << endl;
#pragma omp parallel for default(shared) private(j) shared(k)
	
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				arr[i][j] = i + j + k;
	
#pragma omp parallel for default(shared) private(j) shared(k)
	
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				cout << arr[i][j] << "   ";
			cout << endl;
		}
	
		/////////////////////////////////////////////
		//      firstprivate  num_threads   lastprivate
		cout << "\n\n firstprivate  num_threads   lastprivate " << endl;

		int s = 352;
#pragma omp parallel for firstprivate(s) num_threads(n) lastprivate(s)
		for (i = 0; i < n; i++)
		{
			s = s * omp_get_thread_num();
			cout << "S is " << s << " at thread# " << omp_get_thread_num() << endl;
		}

		cout << "S is " << s << " in main thread" << endl;
		
		////////////////////////////////////////////
		///        REDUCtION
		cout << "\n\n REDUCtION " << endl;

		double area, pi, x;
		area = 0.0;
#pragma omp parallel for private(x) reduction(+:area)
		for (i = 0; i < n; i++) {
			x = (i + 0.5) / n;
			area += 4.0 / (1.0 + x * x);
		}
		pi = area / n;

		cout << "pi is " << pi << " in main thread" << endl;

		/////////////////////////////////////////////
		//         scheduling  
		cout << "\n\n scheduling static " << endl;
#pragma omp parallel for private (j) schedule(static)
		for (i = 0; i < n; i++)
		{
			cout << "print by :" << omp_get_thread_num() << endl;
			for (j = 0; j < n; j++)
				cout << arr[i][j] << "   ";
			cout << endl;
		}

		cout << "\n\n scheduling dynamic " << endl;
#pragma omp parallel for private (j) schedule(dynamic)

		for (i = 0; i < n; i++)
		{
			cout<<"print by :"<< omp_get_thread_num()<<endl;
			for (j = 0; j < n; j++)
				cout << arr[i][j] << "   ";
			cout << endl;
		}

		////////////////////////////////////////////
		///         sections
		cout << "\n\n parallel sections " << endl;
		int v, w, y;
#pragma omp parallel num_threads(2)
		{

#pragma omp sections
			{
#pragma omp section //optional
				 v = alpha();
#pragma omp section
				w = beta();
			}
			// here an implicit barrier exists

#pragma omp sections

			{
#pragma omp section
				x = gamma(v, w);
#pragma omp section
				y = delta();
			}
		}

		cout << "epsilon(x,y) = " << epsilon(x, y) << endl;
		
	return 0;
}