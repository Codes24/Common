#include "Input.h"
#include "iostream"

using namespace std;

void Input::input()
{
	for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{
			cin>>matrix[i][j];
		}
	}
}
Input::~Input()
{
	
}

void Input::output()
{
	cout<<"========================="<<endl;
	for(int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}