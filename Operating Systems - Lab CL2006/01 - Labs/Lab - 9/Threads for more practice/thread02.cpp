#include <iostream>
#include <pthread.h>

using namespace std;

void *add(void *arg) {
  int *arr = (int *)arg;
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += arr[i];
  }
  int *result = new int(sum);
  pthread_exit(result);
}

int main() {
  pthread_t tid;
  int arr[5] = {1, 2, 3, 4, 5};
  int *result;
  pthread_create(&tid, NULL, add, (void *)arr);
  pthread_join(tid, (void **)&result);
  cout << "The sum is " << *result << endl;
  delete result;
  return 0;
}
