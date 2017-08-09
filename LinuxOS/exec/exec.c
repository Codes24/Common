#include "stdio.h"
#include "unistd.h"

/* run ./program */
int main()
{
	/* use execl = list of arguments */
	execl("/home/minhtoan/program", "program", "toan", NULL);
	/* use execlp = list of arguments ans search for path */
	//execlp("program", "program", "toan", NULL);
	/* use execle = list pf arguments and a array of enviroment variables 
	 * if use execle, uncomment the line : printf("%s\n", getenv("TEXT")); in program.c
	*/
	//char* en[] = {"TEXT=toan", NULL};	// use for execle
	//execle("program", "program", "toan", NULL, en);
	return 0;
}
