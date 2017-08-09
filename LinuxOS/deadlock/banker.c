#include "stdio.h"
#include "stdlib.h"

typedef struct process
{
	int* allocate;
	int* max;
	int* need;
}process;

typedef struct all_pro
{
	int number_of_process;
	int number_of_resource;
	int* available;
	process* pro_i;
}all_pro;

process init_pro(int resource)
{
	process pro;
	pro.allocate = malloc(sizeof(int)*resource);
	pro.max = malloc(sizeof(int)*resource);
	pro.need = malloc(sizeof(int)*resource);
	return pro;
}

all_pro read_data(const char* file_name)
{
	FILE* f;
	all_pro pro;
	f = fopen(file_name, "r");
	int row;
	int column;
	int i, j;
	fscanf(f, "%d", &row);
	fscanf(f, "%d", &column);
	pro.number_of_process = row;
	pro.number_of_resource = column;
	pro.pro_i = malloc(sizeof(process)*row);
	pro.available = malloc(sizeof(int)*column);
	for(i=0;i<row;i++)
		pro.pro_i[i] = init_pro(column);
	for(i=0;i<row;i++)
		for(j=0;j<column;j++)
			fscanf(f, "%d", &pro.pro_i[i].max[j]);
	for(i=0;i<row;i++)
		for(j=0;j<column;j++)
			fscanf(f, "%d", &pro.pro_i[i].allocate[j]);
	for(i=0;i<row;i++)
		for(j=0;j<column;j++)
			pro.pro_i[i].need[j] = pro.pro_i[i].max[j] - pro.pro_i[i].allocate[j];
	for(i=0;i<column;i++)
		fscanf(f, "%d", &pro.available[i]);
	return pro;
}

void display(all_pro pro)
{
	int i, j;
	puts("---- Max ----");
	for(i=0;i<pro.number_of_process;i++)
	{
		for(j=0;j<pro.number_of_resource;j++)
			printf(" %d", pro.pro_i[i].max[j]);
		printf("\n");
	}
	puts("---- Allocate ----");
	for(i=0;i<pro.number_of_process;i++)
	{
		for(j=0;j<pro.number_of_resource;j++)
			printf(" %d", pro.pro_i[i].allocate[j]);
		printf("\n");
	}
	puts("---- Need ----");
	for(i=0;i<pro.number_of_process;i++)
	{
		for(j=0;j<pro.number_of_resource;j++)
			printf(" %d", pro.pro_i[i].need[j]);
		printf("\n");
	}
	puts("---- Available ----");
	for(i=0;i<pro.number_of_resource;i++)
		printf(" %d", pro.available[i]);
	printf("\n");
}

int can_allocate(int* a, int* b, int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if (a[i] < b[i])
			return 0;
	}
	return 1;
}

int* add_array(int* a, int* b, int size)
{
	int i;
	int* result;
	result = malloc(sizeof(int)*size);
	for(i=0;i<size;i++)
		result[i] = a[i] + b[i];
	return result;
}
int* sub_array(int* a, int* b, int size)
{
	int i;
	int* result;
	result = malloc(sizeof(int)*size);
	for(i=0;i<size;i++)
		result[i] = a[i] - b[i];
	return result;
}
void show_array(int* a, int size)
{
	int i;
	for(i=0;i<size;i++)
		printf(" %d", a[i]);
	printf("\n");
}
int banker(all_pro pro)
{
	int num, i, k;
	int s_i;	/* safe index */
	num = 0;
	s_i = 0;
	int* safe;
	safe = malloc(sizeof(int)*pro.number_of_process);
	for(k=0;k<pro.number_of_process;k++)
		safe[k] = -1;
	int safe_or_unsafe;
	while(num<pro.number_of_process)
	{
		int old_num;
		old_num = num;
		for(i=0;i<pro.number_of_process;i++)
		{
			int old_i = 0;
			for(k=0;k<pro.number_of_process;k++)
			{
				if (i == safe[k])
				{
					old_i = 1;
				}
			}
			if (can_allocate(pro.available, pro.pro_i[i].need, pro.number_of_resource) == 1 && old_i == 0)
			{
				safe[s_i] = i;
				num++;
				s_i++;
				pro.available = add_array(pro.available, pro.pro_i[i].allocate, pro.number_of_resource);
			}
		}
		if (old_num == num)
		{
			safe_or_unsafe = 0;
			break;
		}
		if (num == pro.number_of_process)
		{
			safe_or_unsafe = 1;
			break;
		}
	}
	puts("---- Banker Algorithm ----");
	if (safe_or_unsafe == 0)
		puts("unsafe state");
	else
	{
		puts("safe state");
		printf(" <P%d,", safe[0]);
		for(i=1;i<pro.number_of_process-1;i++)
			printf(" P%d,", safe[i]);
		printf(" P%d>\n", safe[pro.number_of_process-1]);
	}
	return safe_or_unsafe;
}
	

int main(int argc, char const *argv[])
{
	/* code */
	all_pro pro;
	pro = read_data("data.txt");
	display(pro);
	int i;
	i = banker(pro);
	if (i == 1)
	{
		int p;
		int k;
		int* add;
		add = malloc(sizeof(int)*pro.number_of_resource);
		printf("Them tai nguyen cho process thu: ");
		scanf("%d", &p);
		puts("Nhap cac gia tri tai nguyen them vao:");
		for(k=0;k<pro.number_of_resource;k++)
		{
			scanf("%d", &add[k]);
		}
		if (can_allocate(pro.available, add, pro.number_of_resource) == 1)
		{
			pro.pro_i[p].allocate = add_array(pro.pro_i[p].allocate, add, pro.number_of_resource);
			pro.available = sub_array(pro.available, add, pro.number_of_resource);
			pro.pro_i[p].need = sub_array(pro.pro_i[p].need, add, pro.number_of_resource);
			banker(pro);
		}
		else
		{
			puts("Can't response request");
		}
	}
	return 0;
}