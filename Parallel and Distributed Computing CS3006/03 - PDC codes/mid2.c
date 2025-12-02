#include <omp.h>
#include <stdio.h>
int main() {
int total_and = 1; // Initialize total with some value
int total_or = 0; // Initialize total with some value
#pragma omp parallel for reduction(&&:total_and) reduction(||:total_or)
for (int i = 0; i < 8; i++) {
int thread_value = (i % 2 == 0);
// Set thread_value to 1 for even threads, 0 for odd threads
total_and = total_and && thread_value; // Perform logical AND reduction
total_or = total_or || thread_value; // Perform logical OR reduction
}
printf("Total (AND): %d\n", total_and);
printf("Total (OR): %d\n", total_or);
return 0;
}