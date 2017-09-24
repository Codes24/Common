#include "queue.h"

int main()
{
	int n,k;
	queue number = CreateQueue(10);
	data* i;
	cin>>n;
	for (int j=1;j<=n;j++)
	{
		cin>>k;
		i = CreateNode(k);
		int m = Enqueue(number,i);
		int p = Dequeue(number);
		if (m == 0) break;
	}
	Display(number);
	GetSize(number);
	Release(number);
	return 0;
}