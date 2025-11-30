#include <chrono>
#include <iostream>
#include <pthread.h>

using namespace std;
#define ROWS 5
#define COLS 5

int matrix1[ROWS][COLS] = {{2, 2, 2, 2, 2},
                           {2, 1, 2, 2, 2},
                           {2, 2, 2, 2, 2},
                           {2, 2, 2, 2, 2},
                           {2, 2, 2, 2, 2}};
int matrix2[ROWS][COLS] = {{1, 2, 2, 2, 2},
                           {1, 2, 1, 2, 2},
                           {1, 2, 2, 3, 3},
                           {2, 2, 2, 2, 2},
                           {2, 2, 2, 2, 2}};
int result[ROWS][COLS];

struct args {
  int row_start;
  int row_end;
  int col_start;
  int col_end;
};

void *multiply(void *arg) {
  struct args *a = (struct args *)arg;
  pthread_t thread_id = pthread_self();

  cout << "Thread ID: " << thread_id << endl;

  int i, j, k, sum;
  for (i = a->row_start; i <= a->row_end; ++i) {
    for (j = a->col_start; j <= a->col_end; ++j) {
      sum = 0;
      for (k = 0; k < COLS; ++k) {
        sum += matrix1[i][k] * matrix2[k][j];
      }
      result[i][j] = sum;
    }
  }

  pthread_exit(NULL);
}

int main() {
  pthread_t threads[2];
  int i;
  cout << "I AM USING 2 THREADS" << endl;
  auto start_time = chrono::high_resolution_clock::now(); // start time

  struct args *a1 = new args;
  a1->row_start = 0;
  a1->row_end = ROWS - 1;
  a1->col_start = 0;
  a1->col_end = 1;
  pthread_create(&threads[0], NULL, multiply, a1);

  struct args *a2 = new args;
  a2->row_start = 0;
  a2->row_end = ROWS - 1;
  a2->col_start = 2;
  a2->col_end = COLS - 1;
  pthread_create(&threads[1], NULL, multiply, a2);

  for (i = 0; i < 2; ++i) {
    pthread_join(threads[i], NULL);
  }

  auto end_time = chrono::high_resolution_clock::now(); // end time
  auto duration = chrono::duration_cast<chrono::microseconds>(
      end_time - start_time); // duration in microseconds

  cout << "Matrix 1:\n";
  for (i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      cout << matrix1[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Matrix 2:\n";
  for (i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      cout << matrix2[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Result:\n";
  for (i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Time taken: " << duration.count() << " microseconds" << endl;
}