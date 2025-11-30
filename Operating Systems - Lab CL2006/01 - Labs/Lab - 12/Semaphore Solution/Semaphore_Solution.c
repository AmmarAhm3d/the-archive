#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

sem_t s1, s2;

int x, y, w, z;
int x1,Y1, w1, z1, sm1, sm2;

void* worker1()
{
   sem_wait(&s1);

    x1 = z +2;
    sem_post(&s2);
    sem_wait(&s1);

    Y1 = z1 * 5;
    sm1  = x1 +Y1;

    printf("P1 x=%d \n", sm1);
    sem_post(&s2);
}
void* worker2()
{
    sem_wait(&s2);
    z1 = x1 * 2;
    sem_post(&s1);

    sem_wait(&s2);
    w1 =Y1 + 5;

    sm2 = z1 + w1;

    printf("P2 x=%d\n", sm2);

}

int main(int argc, char* argv[])
{

    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 0);
    pthread_t thread1, thread2;

    x = atoi(argv[1]);
    y = atoi(argv[2]);
    w = atoi(argv[3]);
    z = atoi(argv[4]);

    pthread_create(&thread1, NULL, worker1, NULL);
    pthread_create(&thread2,NULL, worker2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);


    return 0;
}