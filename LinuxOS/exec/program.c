#include "stdio.h"
#include "stdlib.h"

/* Buils this file with gcc -o program program.c */
int main(int argc, char* argv[])
{	
	/* print the first command-line argument */
	printf("%s\n", argv[1]);
	/* print the TEXT enviroment variable  */
//	printf("%s\n", getenv("TEXT"));
	return 0;
}
