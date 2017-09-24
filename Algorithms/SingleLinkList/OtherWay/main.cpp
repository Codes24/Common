#include "singlelinklist.h"

int main()
{
	list date = CreateList();
	int n,m;
	data* i;
	cin>>n;
	for(int j=1;j<=n;j++)
	{
		cin>>m;
		i = CreateNode(m);
		AddEnd(date,i);
	}
	Delete(date,3);
	Display(date);
	Release(date);
	return 0;
}