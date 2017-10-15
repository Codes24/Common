/*
	*sloved by minh toan on 20/11/2016
	By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle int problem67.txt file

*/


#include "iostream"
#include "fstream"

using namespace std;

int** put_data(int size)
{
	int** data = new int*[size];
	for(int i=0;i<size;i++)
		data[i] = new int[i+1];
	fstream f;
	f.open("problem67.txt", ios::in);
	for(int i=0;i<size;i++)
		for(int j=0;j<i+1;j++)
			f>>data[i][j];
	f.close();
	return data;
}
int max(int a,int b)
{
	if(a > b)
		return a;
	else 
		return b;
}
void out_data(int** data,int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<i+1;j++)
			cout<<data[i][j]<<" ";
		cout<<endl;
	}
	return;
}
int cal(int** data,int size)
{	/* #Sun18Nov2016 */
	for(int i=size-2;i>=0;i--)
	{
		for(int j=0;j<=i;j++)
		{
			data[i][j] = max((data[i][j] + data[i+1][j]), (data[i][j] + data[i+1][j+1]));
		}
	}
	return data[0][0];
}
int main()
{
	int size = 100;
	int** data = put_data(size);
	cout<<cal(data, size);
	// out_data(data, size);
	delete data;
	return 0;
}