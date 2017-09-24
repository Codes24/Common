#include "convert.h"
float charToFloat(char ch)
{
	switch(ch)
	{
		case '0':	return 0;
		case '1':	return 1;
		case '2':	return 2;
		case '3':	return 3;
		case '4':	return 4;
		case '5':	return 5;
		case '6':	return 6;
		case '7':	return 7;
		case '8':	return 8;
		case '9':	return 9;		
	};
}
float pow(int n)
{
	int i = 0;
	float r = 1;
	while(i<n)
	{
		r *= 10;
		i++;
	}
	return r;
}
float getIntPart(const char* strNumber)
{
	char* realString;
	int i = 0;
	int j = 0;
	float sign = 1;
	float number = 0;
	if(strNumber[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	while(strNumber[i] != '.' && strNumber[i] != ',' && strNumber[i] != '\0')
	{
		i++;
		j++;
	}
	realString = new char[j+1];
	i = 0;
	j = 0;
	if (sign == -1)
		i = 1;
	while(strNumber[i] != '.' && strNumber[i] != ',' && strNumber[i] != '\0')
	{
		realString[j] = strNumber[i];
		i++;
		j++;
	}
	realString[j] = '\0';
	for(i=0;i<strlen(realString);i++)
	{
		number += (charToFloat(realString[i]) * pow(strlen(realString)-i-1));
	}
	return number*sign;
}
float getRealPart(const char* strNumber)
{
	char* realString;
	float number = 0;
	int i = 0;
	while(strNumber[i] != '.' && strNumber[i] != ',')
		i++;
	i++;
	int k = i;
	int j = 0;
	while(strNumber[i] != '\0')
	{
		i++;
		j++;
	}
	realString = new char[j];
	j = 0;
	while(strNumber[k] != '\0')
	{
		realString[j] = strNumber[k];
		k++;
		j++;
	}
	realString[j] = '\0';	
	for(i=0;i<strlen(realString);i++)
	{
		number += (charToFloat(realString[i]) * pow(strlen(realString)-i-1));
	}
	return (number / pow(strlen(realString)));
}
float toFloat(const char* strNumber)
{
	int i=0;
	bool isReal = false;
	while(strNumber[i] != '\0')
	{
		if (strNumber[i] == ',' || strNumber[i] == '.')
		{
			isReal = true;
			break;
		}
		i++;
	}
	if (isReal == true)
		return getIntPart(strNumber) + getRealPart(strNumber);
	return getIntPart(strNumber);
}