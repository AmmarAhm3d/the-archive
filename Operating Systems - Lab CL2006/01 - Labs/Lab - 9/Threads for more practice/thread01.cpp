#include <iostream>
#include <pthread.h>

using namespace std;

struct ThreadArgs {
  int a;
  int b;
};

void *add(void *arg) {
  ThreadArgs *args = (ThreadArgs *)arg;
  int sum = args->a + args->b;
  int *result = new int(sum);
  pthread_exit(result);
}

int main() {
  pthread_t tid;
  ThreadArgs args = {2, 3};
  int *result;
  pthread_create(&tid, NULL, add, (void *)&args);
  pthread_join(tid, (void **)&result);
  cout << "The sum is " << *result << endl;
  delete result;
  return 0;
}
