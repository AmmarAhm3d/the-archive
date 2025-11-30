#include <chrono>
#include <iostream>
#include <pthread.h>
using namespace std;
#define ROWS 3
#define COLS 3

int matrix1[ROWS][COLS] = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
int matrix2[ROWS][COLS] = {{1, 2, 2}, {1, 2, 1}, {1, 2, 2}};
int result[ROWS][COLS];

struct args {
  int row;
  int col;
};

void *multiply(void *arg) {
  struct args *a = (struct args *)arg;
  pthread_t thread_id = pthread_self();

  cout << "Thread ID: " << thread_id << endl;
  int row = a->row;
  int col = a->col;

  int i, sum = 0;
  for (i = 0; i < COLS; ++i) {
    sum += matrix1[row][i] * matrix2[i][col];
  }

  result[row][col] = sum;
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[ROWS][COLS];
  int i, j;

  auto start_time = chrono::high_resolution_clock::now(); // start time

  for (i = 0; i < ROWS; ++i) {
    for (j = 0; j < COLS; ++j) {
      struct args *a = new args;
      a->row = i;
      a->col = j;
      pthread_create(&threads[i][j], NULL, multiply, a);
    }
  }

  for (i = 0; i < ROWS; ++i) {
    for (j = 0; j < COLS; ++j) {
      pthread_join(threads[i][j], NULL);
    }
  }

  auto end_time = chrono::high_resolution_clock::now(); // end time
  auto duration = chrono::duration_cast<chrono::microseconds>(
      end_time - start_time); // duration in microseconds

  cout << "Matrix 1:\n";
  for (i = 0; i < ROWS; ++i) {
    for (j = 0; j < COLS; ++j) {
      cout << matrix1[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Matrix 2:\n";
  for (i = 0; i < ROWS; ++i) {
    for (j = 0; j < COLS; ++j) {
      cout << matrix2[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Result:\n";
  for (i = 0; i < ROWS; ++i) {
    for (j = 0; j < COLS; ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  cout << "Time taken: " << duration.count() << " microseconds" << endl;

  return 0;
}
