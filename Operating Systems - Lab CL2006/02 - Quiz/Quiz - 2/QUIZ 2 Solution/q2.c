#include <stdio.h>
#include <pthread.h>

int arr[10];

void *find_duplicate(void *arg)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += arr[i];
    }
    int duplicate = sum - 45;
    printf("The duplicate number is %d\n", duplicate);
    pthread_exit(NULL);
}

int main()
{
    int i, j, temp;
    for (i = 0; i < 10; i++)
    {
        do
        {
            printf("Enter value between (1-9) for index %d: ", i);
            scanf("%d", &temp);
        } while (temp < 1 || temp > 9);
        arr[i] = temp;
    }

    pthread_t thread;
    pthread_create(&thread, NULL, find_duplicate, NULL);
    pthread_join(thread, NULL);

    return 0;
}

// q1
// n/2
// n
// n*n