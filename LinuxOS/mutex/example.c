#include "stdio.h"
#include "pthread.h"

pthread_mutex_t mutex;
int data = 0;

void* thread_1(void* n);
void* thread_2(void* n);
int main()
{
	pthread_mutex_init(&mutex, NULL);
	pthread_t thread1, thread2;
	pthread_attr_t attr1, attr2;
	pthread_attr_init(&attr1);
	pthread_attr_init(&attr2);
	pthread_create(&thread1, &attr1, thread_1, (void*)1);
	pthread_create(&thread2, &attr2, thread_2, (void*)1);	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_mutex_destroy(&mutex);
	printf("Final value of data = %d\n", data);
}

void* thread_1(void* n)
{
	pthread_mutex_lock(&mutex);
	int a = data;
	a += (int)n;
	data = a;
	printf("Data in this thread a = %d\n", data);
	pthread_mutex_unlock(&mutex);
}

void* thread_2(void* n)
{
	pthread_mutex_lock(&mutex);
	int b = data;
	b -= (int)n;
	data = b;
	printf("Data in this thread b = %d\n", data);
	pthread_mutex_unlock(&mutex);
}