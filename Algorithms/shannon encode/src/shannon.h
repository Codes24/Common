#ifndef SHANNON_H
#define SHANNON_H
#include "stdio.h"
#include "stdlib.h"
#include "logarithm.h"
#include "binary.h"

/* about details, see shannon.png */
float* input_p();
void shannon();
void sort(float* _p_, int n);

float* input_p(int* n)
{
	float* source;
	int i;
	printf("Number of informations: ");
	scanf("%d", n);
	source = malloc((*n) * sizeof(float)); 
	for(i=0;i<*n;i++)
	{
		printf("a[%d] = ", i);
		scanf("%f", &source[i]);
	}
	return source;
}

int cal_l(float _p_)
{
	double r = -logarit(_p_, 2);
	if (r > (double)(int)r)
		return (int)(r+1);
	else
		return (int)r;
}

void shannon()
{
	int n;
	float* _p_ = input_p(&n);
	sort(_p_, n);
	float _q_, H, L;
	binary* bin;
	int* _w_;
	int i, _l_;
	H = 0;
	L = 0;
	for(i=0;i<n;i++)
	{
		if (i>0) _q_ += _p_[i-1];
		else _q_ = 0;
		bin = ftob(_q_);
		_l_ = cal_l(_p_[i]);
		H += _p_[i] * (-logarit(_p_[i], 2));
		L += _l_ * _p_[i];
		_w_ = malloc(_l_*sizeof(int));
		int k;
		for(k = 0;k<_l_;k++)
			_w_[k] = bin->_array_[k];
		printf("-- %f -- %f -- ", _p_[i], _q_);
		display_b(bin);
		printf(" -- %d -- ", _l_);
		for (k=0;k<_l_;k++)
			printf("%d", _w_[k]);
		printf("\n");
	}
	printf("Hieu suat: %f\n", (H/L)*100);
}

void sort(float* _p_, int n)
{
	int i,j;
	float temp;
	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (*(_p_+j) > *(_p_+i))
			{
				temp = *(_p_+j);
				*(_p_+j) = *(_p_+i);
				*(_p_+i) = temp;
			}
		}
	}
}
#endif