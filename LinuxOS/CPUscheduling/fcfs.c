/* First Come Firt Served scheduling 
 * FCFS is non-preemptive scheduling, the first process come, the first process serviced
*/
#include "stdio.h"
#include "stdlib.h"

/* process and program structure */
typedef struct
{
	int ID;	/* process's identify number */
	int arr_time;	/* process's ariivel time */
	int ser_time;	/* number of CPU's burst for process */
	float waiting_time;	/* waiting time of this process */
	float response_time; /* response time of this process */
	float turn_around_time;	/* turn around time of this process */
}process;

typedef struct
{
	int num_of_processes; /* total of process of program */
	process* processes;	/* process list of this program */
	int* chart;	/* time chart of this program */
	float service_time;	/* total of ser_time of all process */
	float waiting_time;	/* total of waiting time */
	float response_time;	/* total of response time */
	float turn_around_time;	/* total of turn around time */
	float aver_waiting;	/* average of waiting time */
	float aver_response;	/* average of response time */
	float aver_turn_around;	/* average of turn around time */
}program;

/* non-main function */
process input_process(int id);	/* input process's data: id, arrival time, service time */
program input_program();	/* input program's data, number of process and data for each process */
void output(program pro);	/* output result after calculated */
void cal_time(program* pro);	/* calculate waiting time, response time, ... */
void init(program* pro);	/* initialize neccessary for Grand Chart */
void fcfs_algrithms(program* pro);	/* main algorithms */
process choose(int curr_arr, int curr_id, program pro); /* choose a process which serviced following */

/* main function */
int main(int argc, char const *argv[])
{
	program pro = input_program();
	fcfs_algrithms(&pro);
	output(pro);
	return 0;
}

process input_process(int id)
{
	process pro;
	pro.ID = id;
	printf("--- Process %d ---\n", id);
	printf("Arrivel time: ");
	scanf("%d", &pro.arr_time);
	printf("Service time: ");
	scanf("%d", &pro.ser_time);
	pro.waiting_time = 0;	
	pro.response_time = 0;	
	pro.turn_around_time = 0;
	return pro;
}
program input_program()
{
	int i,n;
	program pro;
	printf("Number of process: ");
	scanf("%d", &n);
	pro.processes = malloc(sizeof(process) * n);
	pro.num_of_processes = n;
	pro.service_time = 0;
	pro.waiting_time = 0;	
	pro.response_time = 0;	
	pro.turn_around_time = 0;
	pro.aver_waiting = 0;
	pro.aver_response = 0;
	pro.aver_turn_around = 0;
	for (i=0;i<n;i++)
	{
		pro.processes[i] = input_process(i);
	}
	return pro;
}

void cal_time(program* pro)
{
	int i, j;
	for(i=0;i<pro->num_of_processes;i++)
	{
		int time_pass;
		int done;
		time_pass = 0;
		for(j=pro->processes[i].arr_time;j<pro->service_time;j++)
		{
			if (pro->processes[i].ID == pro->chart[j]) break;
			time_pass++;
		}
		pro->processes[i].waiting_time = time_pass;
		pro->processes[i].response_time = time_pass;
		time_pass = 0;
		done = 0;
		for(j=pro->processes[i].arr_time;j<pro->service_time;j++)
		{
			if (pro->processes[i].ID == pro->chart[j] && done == 0)
				done = 1;
			if (pro->processes[i].ID != pro->chart[j] && done == 1)
				break;
			time_pass++;
		}
		pro->processes[i].turn_around_time = time_pass;
		pro->waiting_time += pro->processes[i].waiting_time;
		pro->response_time += pro->processes[i].response_time;
		pro->turn_around_time += pro->processes[i].turn_around_time;
	}
	pro->aver_waiting = pro->waiting_time / pro->num_of_processes;
	pro->aver_response = pro->response_time / pro->num_of_processes;
	pro->aver_turn_around = pro->turn_around_time / pro->num_of_processes;
}

void fcfs_algrithms(program* pro)
{
	init(pro);
	int i, j ,k;
	int curr_arr;
	int curr_id;
	int running_time;
	curr_arr = 0;
	curr_id = -1;
	process proc;
	i = 0;
	for(j=0;j<pro->num_of_processes;j++)
	{
		proc = choose(curr_arr, curr_id, *pro);
		curr_arr = proc.arr_time;
		curr_id = proc.ID;
		running_time = proc.ser_time;
		while(running_time > 0)
		{
			pro->chart[i] = proc.ID;
			i++;
			running_time--;
		}
	}
	cal_time(pro);
}

process choose(int curr_arr, int curr_id, program pro)
{
	int min;
	min = pro.service_time;
	int i;
	process pro_return;
	for(i=0;i<pro.num_of_processes;i++)
	{
		if (pro.processes[i].arr_time >= curr_arr && pro.processes[i].arr_time <= min && pro.processes[i].ID != curr_id)
		{
			min = pro.processes[i].arr_time;
			pro_return = pro.processes[i];
		}
	}
	return pro_return;
}
void init(program* pro)
{
	int num_ser_time;
	int i;
	num_ser_time = 0;
	for(i=0;i<pro->num_of_processes;i++)
		num_ser_time += pro->processes[i].ser_time;
	pro->service_time = num_ser_time;
	pro->chart = malloc(num_ser_time * sizeof(int));
	for(i=0;i<num_ser_time;i++)
		pro->chart[i] = 0;
	return;
}

void output(program pro)
{
	int i;
	printf("-------- OUTPUT -------\n");
	printf("Have %d processes\n", pro.num_of_processes);
	printf("List of processes: ID, Arrivel time, Service time\n");
	for(i=0;i<pro.num_of_processes;i++)
	{
		printf(" %5d%5d%5d\n", pro.processes[i].ID, pro.processes[i].arr_time, pro.processes[i].ser_time);
	}
	printf("Grand chart\n");
	for(i=0;i<pro.service_time;i++)
		printf("%d", pro.chart[i]);
	printf("\nTotal of service time: %f\n", pro.service_time);
	printf("Total of waiting time: %f\n", pro.waiting_time);
	printf("Total of response time: %f\n", pro.response_time);
	printf("Total of turn around time: %f\n", pro.turn_around_time);
	printf("Average of waiting time: %f\n", pro.aver_waiting);
	printf("Average of response time: %f\n", pro.aver_response);
	printf("Average of turn around time: %f\n", pro.aver_turn_around);
}