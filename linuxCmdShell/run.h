#ifndef RUN_H
#define RUN_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
void showHistory(stack* history);
void runHistory(stack* history, const char* cmd);
void run(const char* cmd);

void showHistory(stack* history)
{
	display(history);
}

void runHistory(stack* history, const char* cmd)
{
		node* i = history->head;
		char* number = malloc(2);
		number[0] = cmd[1];
		number[1] = '\0';
		int num = atoi(number);
		int j = history->currentSize - 1;
		while(1)
		{
			if (j == num)
			{
				run(i->command);
				return;
			}
			i = i->nextNode;
			j--;
		}
}

void run(const char* cmd)
{
	char** args = (char**)malloc(20*sizeof(char*));	// size axb
	int i;
	for(i=0;i<20;i++)
		args[i] = (char*)malloc(20*sizeof(char));
	i = 0;
	args[0] = "/bin/bash";
	args[1] = "-c";
	args[2] = strdup(cmd);
	args[3] == NULL;
	pid_t pid = fork();
	if (pid == 0)
	{
		execvp(args[0], args);
	}
	else if(pid > 0)
		wait();
	// for(i=0;i<=a;i++)
	// 	printf("%s ", args[i]);
	return;
}
#endif