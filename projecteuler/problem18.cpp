/*
	*sloved by minh toan on 20/11/2016
	By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. 
However, Problem 67, is the same challenge with a triangle containing one-hundred rows; 
it cannot be solved by brute force, and requires a clever method! ;o)
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
	f.open("problem18.txt", ios::in);
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
	int size = 15;
	int** data = put_data(size);
	cout<<cal(data, size);
	delete data;
	return 0;
}