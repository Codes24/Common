#include "stack.h"

int main()
{
	stack number = CreateStack(10);
	data* temp;
	int n,k;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>k;
		temp = CreateNode(k);
		int j = push(number,temp);
		int q = pop(number);
		if (j==0)
		{
			break;
		}
	}
	Display(number);
	GetSize(number);
	Release(number);
	return 0;
}