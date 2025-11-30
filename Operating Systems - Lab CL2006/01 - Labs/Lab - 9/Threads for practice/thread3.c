#include <pthread.h>
#include <stdio.h>

void *is_prime(void *arg) {
  int n = *((int *)arg);
  int i, flag = 0;

  for (i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }

  if (n == 1) {
    printf("%d is not prime.\n", n);
  } else {
    if (flag == 0)
      printf("%d is prime.\n", n);
    else
      printf("%d is not prime.\n", n);
  }
}

void *factorial(void *arg) {
  int n = *((int *)arg);
  int i;
  unsigned long long fact = 1;

  for (i = 1; i <= n; ++i)
    fact *= i;

  printf("Factorial of %d = %llu\n", n, fact);
}

int main() {
  pthread_t tid[2];
  int n1 = 5, n2 = 0;

  pthread_create(&tid[0], NULL, is_prime, &n1);
  pthread_create(&tid[1], NULL, factorial, &n2);

  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);

  return 0;
}
