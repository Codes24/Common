#include "stack.h"
#include "run.h"

int main()
{
	stack* history = setupStack();
	char* cmd = malloc(100);
	int i;
	puts("================================================");
	puts("   simple program run command shells in linux");
	puts("   !! - show history");
	puts("   !X to run command X in history");
	puts("   type !exit or !quit to exit program");
	puts("================================================");
	while(1)
	{
		strcpy(cmd, "");
		printf("cmd> ");
		fgets(cmd, 100, stdin);
		fflush(stdin);
		if (strstr(cmd, "!exit") || strstr(cmd, "!quit"))
			break;
		else if (strstr(cmd, "!"))
		{
			if (cmd[1] == '!')
				showHistory(history);
			else
				runHistory(history, cmd);
		}
		else
		{	
			push(history, cmd);
			run(cmd);
		}
	}
	free(history);
	free(cmd);
}