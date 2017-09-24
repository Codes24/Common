#ifndef FANO_H
#define FANO_H
#include "stdio.h"
#include "stdlib.h"
#include "math.h" 

int array_size(float* p);
float** array_setup(int size);
float array_sum(float **p, int a, int b);
float** input();
float** sorted(float** _p_, int n);
void output(float** p, int n);
void estimate(float** p, int a, int b);
float h(float** p, int n);
void fano();
int array_size(float* p)
{
	int i;
	i = 0;
	while(1)
	{
		if (p[i] == -1) return i-1;
		i++;
	}
	return 0;
}

float** array_setup(int size)
{
	float** p;
	int i,j;
	p = (float**)malloc(size * sizeof(float*));
	for(i=0;i<size;i++)
		p[i] = (float*)malloc(size * sizeof(float));
	for(i=0;i<size;i++)
		for (j = 0; j < size;j++)
			p[i][j] = -1;
	return p;
}

float array_sum(float** p, int a, int b)
{
	if (b<a) return 0;
	int i;
	float s;
	for(i=a;i<=b;i++)
		s += p[i][0];
	return s;
}
float** sorted(float** _p_, int n)
{
	int i,j;
	float temp;
	float** p;
	p = (float**)malloc(n * sizeof(float*));
	for(i=0;i<n;i++)
		p[i] = (float*)malloc(n * sizeof(float));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			p[i][j] = _p_[i][j];
	for (i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if (p[j][0] > p[i][0])
			{
				temp = p[j][0];
				p[j][0] = p[i][0];
				p[i][0] = temp;
			}
		}
	}
	return p;
}
float** input(int* n)
{
	int i;
	printf("Number of source: ");
	scanf("%d", n);
	float** p = array_setup(*n);
	for(i=0;i<*n;i++)
	{
		printf("a[%d] = ", i);
		scanf("%f", &p[i][0]);
	}
	p = sorted(p, *n);
	return p;
}

void output(float** p, int n)
{
	int i,j;
	puts("----------------------");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if (p[i][j] != -1)
				if (j != 0)
					printf("%.0f", p[i][j]);
				else
					printf("%.3f  ", p[i][j]);
		}
		printf("\n");
	}
	return;
}

void estimate(float** p, int a, int b)
{
	if (b <= a) return;
	float temp = 0;
	int i,j;
	float mid = array_sum(p, a, b)/2;
	for(i=a;i<=b;i++)
	{
		temp += p[i][0];
		if (temp >= mid)
		{
			float upper = temp;
			float lower = array_sum(p, i+i, b);
			float distance1 = upper - lower;
			float distance2;
			if (i - 1 >= a)
			{
				upper = array_sum(p, a, i - 1);
				lower = array_sum(p, i, b);
				distance2 = upper - lower;
			}
			else
				distance2 = 1;
			if (distance2 >= distance1)
			{
				for(j=a;j<=i;j++)
					p[j][array_size(p[j])+1] = 0;
				for(j=i+1;j<=b;j++)
					p[j][array_size(p[j])+1] = 1;
				estimate(p, a, i);
				estimate(p, i+1, b);
				return;
			}
			else
			{
				for(j=a;j<=i-1;j++)
					p[j][array_size(p[j])+1] = 1;
				for(j=i;j<=b;j++)
					p[j][array_size(p[j])+1] = 0;
				estimate(p, a, i-1);
				estimate(p, i, b);
				return;
			}	
			return;
		}
	}
	return;
}
float h(float** p, int n)
{
	int i;
	float H, L;
	H = 0;
	L = 0;
	for(i=0;i<n;i++)
	{
		H += p[i][0] * (-(log(p[i][0])/log(2)));
		L += p[i][0] * (array_size(p[i]));
	}
	float h = H/L*100;
	printf("------ H = %f\n", H);
	printf("------ L = %f\n", L);
	printf("------ h = %f\n", h);
}
void fano()
{
	int n;
	float** p = input(&n);
	estimate(p, 0, n-1);
	output(p, n);
	h(p, n);
}
#endif