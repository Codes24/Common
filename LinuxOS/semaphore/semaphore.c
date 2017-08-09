#include "stdio.h"
#include "unistd.h"
#include "pthread.h"
#include "semaphore.h"

#define MAX 10

int sum;
void* thread_add(void* n);
void* thread_sub(void* n);
sem_t sem_a;
sem_t mutex;
sem_t sem_b;
int main()
{
	sum = 0;
	sem_init(&sem_a, 0, 2);
	sem_init(&mutex, 0, 1);
	sem_init(&sem_b, 0, 0);
	pthread_t thread1, thread2;
	pthread_attr_t attr1, attr2;
	pthread_attr_init(&attr1);
	pthread_attr_init(&attr2);
	pthread_create(&thread1, &attr1, thread_add, (void*)10);
	pthread_create(&thread2, &attr2, thread_sub, (void*)10);
	// pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	sem_destroy(&sem);
}

void* thread_add(void* n)
{
	while(1)
	{
		sem_wait(&sem_a);
		sem_wait(&mutex);
		printf("<A1>\n");
		sem_post(&mutex);
		sem_post(&sem_b);
	}
}

void* thread_sub(void* n)
{
	while(1)
	{
		sem_wait(&sem_b);
		sem_wait(&mutex);
		printf("<B1>\n");
		sem_post(&mutex);
		sem_post(&sem_a);
	}
}