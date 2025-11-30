#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

int X, Y, Z, W;
int X1, Y1, Z1, W1;
int S1, S2;
sem_t sem1, sem2;

void *thread1(void *arg) {
  X1 = Z + 2;
  Y1 = Z1 * 5;
  S1 = X1 + Y1;
  printf("x=%d\n", S1);
  sem_post(&sem1);
  return NULL;
}

void *thread2(void *arg) {
  sem_wait(&sem1);
  Z1 = X1 * 2;
  W1 = Y1 + 5;
  S2 = Z1 + W1;
  printf("x=%d\n", S2);
  sem_post(&sem2);
  return NULL;
}

int main() {
  printf("Enter values for X, Y, Z and W: ");
//   entry checking
  if (scanf("%d %d %d %d", &X, &Y, &Z, &W) != 4) {
        printf("Error: invalid input\n");
        exit(1);
        }
    
  sem_init(&sem1, 0, 0);
  sem_init(&sem2, 0, 0);

  pthread_t t1, t2;
  pthread_create(&t1, NULL, thread1, NULL);
  pthread_create(&t2, NULL, thread2, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  sem_destroy(&sem1);
  sem_destroy(&sem2);

  return 0;
}