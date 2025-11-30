#include <stdio.h>
#include <pthread.h>

void *myThreadFunc(void *arg) {
  printf("Thread is running\n");
  return NULL;
}

int main() {
  pthread_t thread_id;
  printf("Before thread creation\n");
  pthread_create(&thread_id, NULL, myThreadFunc, NULL);
  pthread_join(thread_id, NULL);
  printf("After thread creation\n");
  return 0;
}