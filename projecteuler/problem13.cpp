/*
	Work out the first ten digits of the sum of  one-hundred 50-digit numbers in "problem13.txt" file
*/

#include "iostream"
#include "cmath"
#include "mtString.h"
#include "fstream"

using namespace std;

char** read_file()
{
	char** number_line = new char*[100];
	for (int i=0;i<100;i++)
		number_line[i] = new char[51];
	fstream f;
	f.open("problem13.txt", ios::in);
	int i = 0;
	while(i<100)
	{
		f.getline(number_line[i], 51);
		i++;
	}
	f.close();
	return number_line;
}
int char_to_int(char c)
{
	switch(c)
	{
		case '0' : return 0;
		case '1' : return 1;
		case '2' : return 2;
		case '3' : return 3;
		case '4' : return 4;
		case '5' : return 5;
		case '6' : return 6;
		case '7' : return 7;
		case '8' : return 8;
		case '9' : return 9;
	}
	return 0;
}
int** charA_to_intA(char** charArray)
{
	int** intArray = new int*[100];
	for(int i=0;i<100;i++)
		intArray[i] = new int[50];
	for (int i=0;i<100;i++)
		for (int j=0;j<50;j++)
			intArray[i][j] = char_to_int(charArray[i][j]);
	return intArray;
}
int sum_array_a_memory_c(int* a,int &c)
{
	int sum = 0;
	for (int i=0;i<100;i++)
	{
		sum += a[i];
	}
	sum += c;
	int n;
	n = sum%10;
	int memory = 0;
	while(sum/10 != 0)
	{
		sum -= 10;
		memory++;
	}
	c = memory;
	return n;
}
int** array_100x50_to_50x100(int** array)
{
	int** arrayReturn = new int*[50];
	for (int i=0;i<50;i++)
		arrayReturn[i] = new int[100];
	int m = 0;
	int n = 0;
	for(int i = 49;i>=0;i--)
	{
		for(int j=0;j<100;j++)
		{
			arrayReturn[m][n] = array[j][i];
			n++;
		}
		m++;
		n = 0;
	}
	return arrayReturn;
}
int* sum_array(int** array,int &memory)
{
	int* result = new int[50];
	for(int i=0;i<49;i++)
		result[i] = sum_array_a_memory_c(array[i], memory);
	result[49] = 0;
	for(int i = 0;i<100;i++)
		result[49] += array[49][i];
	result[49] += memory;
	return result;
}
int main()	/* #Wed16Nov2016 */
{
	char** charArray = read_file();
	int** intArray = charA_to_intA(charArray);
	int memory = 0;
	int** intArray_50x100 = array_100x50_to_50x100(intArray);
	int* result = sum_array(intArray_50x100, memory);
	for(int i = 49;i>=0;i--)
		cout<<result[i];
	delete result;
	delete intArray_50x100;
	delete charArray;
	delete intArray;
	return 0;
}