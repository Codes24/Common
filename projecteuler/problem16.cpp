#include "iostream"
#include "math.h"
#include "string.h"

using namespace std;

int char_to_int(char a)
{
	switch(a)
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
}
char int_to_char(int a)
{
	switch(a)
	{
		case 0 : return '0';
		case 1 : return '1';
		case 2 : return '2';
		case 3 : return '3';
		case 4 : return '4';
		case 5 : return '5';
		case 6 : return '6';
		case 7 : return '7';
		case 8 : return '8';
		case 9 : return '9';		
	}
}
void swap(char a[])
{
	char c;
	int j = strlen(a) - 1;
	for(int i=0;i<strlen(a)/2;i++)
	{
		c = a[i];
		a[i] = a[j- i];
		a[j - i] = c;
	}
}
int mul(int a,int b,int &memory)
{
	int c = a*b;
	c += memory;
	memory = c/10;
	return c%10;
}
int add(int a,int b,int &memory)
{
	int c = a + b;
	c += memory;
	memory = c/10;
	return c%10;
}
char* mul1000(const char* n)
{
	char* a = new char[strlen(n)+4];
	strcpy(a, n);
	strcat(a, "000");
	return a;
}
char* mul20(const char* n)
{
	int i = strlen(n) - 1;
	int j = 1;
	int memory = 0;
	char* a = new char[strlen(n) + 3];
	while(i >=0 )
	{
		a[j] = int_to_char(mul(char_to_int(n[i]),char_to_int('2'),memory));
		j++;
		i--;
	}
	if(memory != 0)
	{
		a[j] = int_to_char(memory);
		a[j+1] = '\0';
	}
	else
		a[j] = '\0';
	swap(a);
	return a;
}
char* mul4(const char* n)
{
	int i = strlen(n) - 1;
	int j = 0;
	int memory = 0;
	char* a = new char[strlen(n) + 2];
	while(i >=0 )
	{
		a[j] = int_to_char(mul(char_to_int(n[i]),char_to_int('4'),memory));
		j++;
		i--;
	}
	if(memory != 0)
	{
		a[j] = int_to_char(memory);
		a[j+1] = '\0';
	}
	else
		a[j] = '\0';
	swap(a);
	return a;
}
char* add_two_char(const char* a,const char* b)
{
	int memory = 0;
	char* result = new char[strlen(a) + 2];
	strcpy(result ,"");
	int i = 0;
	int i_a = strlen(a) - 1;
	int i_b = strlen(b) - 1;
	while(i_b >= 0)
	{
		result[i] = int_to_char(add(char_to_int(a[i_a]), char_to_int(b[i_b]), memory));
		i++;
		i_a--;
		i_b--;
	}
	if(i_a < 0)
	{
		if(memory != 0)
		{
			result[i] = int_to_char(memory);
			result[i+1] = '\0';
		}
		else
			result[i] = '\0';
		swap(result);
	}
	else if(i_a >= 0)
	{
		int c = 0;
		while(i_a >= 0)
		{
			result[i] = int_to_char(add(char_to_int(a[i_a]), memory, c));
			memory = c;
			c = 0;
			i++;
			i_a--;
		}
		if(memory != 0)
		{
			result[i] = int_to_char(memory);
			result[i+1] = '\0';
		}
		else
			result[i] = '\0';
		swap(result);
	}
	// cout<<result<<endl;
	return result;
}
char* carry_out2m1000(int n)
{
	char* f;
	char* t = "1024";
	for(int i=1;i<n;i++)
	{
		f = add_two_char(mul1000(t), mul20(t));
		t = add_two_char(f, mul4(t));
		// cout<<t<<endl;
	}
	return t;
}
int main()
{
	int n;
	cin>>n;
	char* t = new char[1000];
	strcpy(t, "1024");
	for(int i=1;i<n;i++)
	{
		strcpy(t, add_two_char(add_two_char(mul1000(t), mul20(t)), mul4(t)));
		cout<<t<<endl;
	}
	// cout<<t<<endl;
	delete t;
}