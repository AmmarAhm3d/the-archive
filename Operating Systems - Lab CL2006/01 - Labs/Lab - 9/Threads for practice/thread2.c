#include <pthread.h>
#include <stdio.h>

void *thread_func(void *arg) {
  int i;
  for (i = 0; i < 5; i++) {
    printf("Thread %d: %d\n", *((int *)arg), i);
  }
  return NULL;
}

int main() {
  pthread_t threads[3];
  int thread_args[3];
  int i;

  for (i = 0; i < 3; i++) {
    thread_args[i] = i;
    pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);
  }

  for (i = 0; i < 3; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
