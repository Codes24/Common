/*
 *	SERVER CHAT MANAGER HEADER FILE
 *	Create on 27th, April 2017 by
 *		[+] Nguyen Thanh Khoa
 *			Email 15520377@gm.uit.edu.vn
 *		[+] Nguyen Thanh Dinh
 *			Email 15520117@gm.uit.edu.vn
 *		[+] Pham Minh Toan
 *			Email 15520905@gm.uit.edu.vn
 *	Class	Operating System Course
 *	School	University Of Information Technology	 	
*/

#ifndef SERVER_H
#define SERVER_H
#include "stdsoc.h"

#define NUM_CLIENT 10	/* Number of client can connect to server */

void open_server();	/* show information a bout server */
void signal_handler();	/* handle signal from users */
void forward(int socket, const char* message);	/* forward message to lan */
void save_soc(int socket);	/* save socket to array */
void delete_soc(int socket); /* delete socket which close connection */	
void* handle_thread(void* soc);	/* thread maintain one connection from client */

int all_socket[NUM_CLIENT];	/* hold all socket */

void signal_handler()
{
	printf("\nShutting down server ... Done! \n");
	exit(0);
}
void forward(int socket, const char* message)
{
	int i;	/* index for loops */
	for(i=0;i<NUM_CLIENT;i++)
	{
		if ( all_socket[i] != socket && all_socket[i] != -19)
		{
			say(all_socket[i], message);
		}
	}
}

void* handle_thread(void* soc)
{
	int connection;	/* socket this thread's maintianing*/
	connection = (int)soc;
	char* message = malloc(1000*sizeof(char));	/* buffer for message */
	char* user_name = malloc(50*sizeof(char));	/* buffer hold user name */
	hear(connection, message, 1000);
	strcpy(user_name, message);
	printf("Connected with %s ...\n", user_name);
	sprintf(message, "    --->Connected with %s\n", user_name);
	forward(connection, message);
	sprintf(message, "Your id on server #%d ... \n", connection);
	say(connection, message);
	while(1)
	{
		hear(connection, message, 1000);
		if (strstr(message,"!exit") || strstr(message, "!quit"))
		{
			printf("Disconnect with %s\n", user_name);
			sprintf(message, "    --->Disconnected with %s\n", user_name);
			forward(connection, message);
			close(connection);
			delete_soc(connection);
			break;
		}
		printf("%s say: %s\n", user_name, message);
		char* for_mess = malloc(1000*sizeof(char));	/* buffer message will be forward */
		sprintf(for_mess, "    %s say: %s\n", user_name, message);
		forward(connection, for_mess);
	}
	close(connection);
	free(user_name);
	free(message);
	pthread_exit(0);
}

void save_soc(int socket)
{
	int i;
	for(i=0;i<NUM_CLIENT;i++)
	{
		if (all_socket[i] == -19)
		{
			all_socket[i] = socket;
			break;
		}
	}
}

void delete_soc(int socket)
{
	int i;
	for(i=0;i<NUM_CLIENT;i++)
	{
		if (all_socket[i] == socket)
		{
			all_socket[i] = -19;
			break;
		}
	}
}

void open_server()
{
	printf("+----------------------------------------------------+\n");
	printf("| Lan chat server                                    |\n");
	printf("| Run server as ./server PORT                        |\n");
	printf("| Please press Ctrl+C to shutdown server             |\n");
	printf("+----------------------------------------------------+\n");
	/* Init a array, all_socket */
	int i;
	for(i=0;i<NUM_CLIENT;i++)
		all_socket[i] = -19;
}

#endif

/* END OF FILE */