#include "singlelinklist.h"

int main()
{
	student* Start = CreateList();
	student* Node;
	student* i;
	char name[30];
	char id[10];
	int number,n;
	cin>>n;
	for (int j=1;j<=n;j++)
	{
		cout<<"Name: ";
		cin.ignore(256,'\n');
		cin.getline(name,30);
		cout<<"ID: ";
		cin.getline(id,10);
		cout<<"Number: ";
		cin>>number;
		Node = CreateNode(name,id,number);
		Insert(Start,Node);
	}
	Display(Start);
	DeleteList(Start);
	Display(Start);
	return 0;
}