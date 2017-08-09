#include "stdio.h"
#include "pthread.h"
#include "stdlib.h"
#include "time.h"
#include "inttypes.h"
int sum = 0;
void *runner(void *number)
{
	int i, upper = (intptr_t)number;
	for (i = 0;i<=upper;i++)
	{
		sum += i;
	}
	pthread_exit(0);
}

int main(int argc, char* argv[])
{
	clock_t begin = clock();
	int i = 5000;
	pthread_t thread1, thread2;
	pthread_attr_t attr1, attr2;
	pthread_attr_init(&attr1);
	pthread_attr_init(&attr2);
	pthread_attr_setstacksize(&attr1, 120); 
	pthread_create(&thread1, &attr1, runner, (void*)1000000);
	// pthread_create(&thread2, &attr2, runner, (void*)10000000);
	pthread_join(thread1, NULL);
	// pthread_join(thread2, NULL);
	clock_t end = clock();
	printf("sum = %d in %f\n", sum, (double)(end - begin) / CLOCKS_PER_SEC);
}

