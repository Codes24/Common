/*	
 *	SIMPLE CHAT CLIENT
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

#include "stdsoc.h"
#include "client.h"

int main(int argc, char const *argv[])
{
	if (argc < 3)	/* check commandline arguments */
	{
		printf("Please run client as ./client IP_ADDRESS PORT\n");
		exit(0);
	}
	open_client();
	int client_socket = init_socket();	/* client main socket */
	struct sockaddr_in si;	/* client EndPoint's information structure */
	memset(&si, 0, sizeof(si));
	si.sin_family = AF_INET;
	si.sin_addr.s_addr = inet_addr(argv[1]);
	si.sin_port = htons(atoi(argv[2]));
	char* user_name = malloc(50*sizeof(char));	/* buffer for user name */
	printf("User Name: ");
	fgets(user_name, 50, stdin);
	if (connect(client_socket, (struct sockaddr *) &si, sizeof(si)) == -1)
	{
		puts("ERROR::CONNECT::SERVER");
		exit(0);
	}
	/* Connected with server */
	printf("Connected with server as %s", user_name);
	char* message = malloc(1000);	/* buffer for message */
	say(client_socket, user_name);
	hear(client_socket, message, 1000);
	puts(message);
	pthread_t thread;	/* thread hear message from server */
	pthread_attr_t attr;	/* thread attritude */
	pthread_attr_init(&attr);
	pthread_create(&thread, &attr, listen_thread, (void*)(client_socket));
	while(1)
	{
		fgets(message, 1000, stdin);
		say(client_socket, message);
		if (strstr(message, "!exit") || strstr(message, "!quit"))
		{
			puts("Disconnected with server ... ");
			exit(0);
			break;
		}
	}
	pthread_join(thread, NULL);
	close(client_socket);
	free(message);
	free(user_name);
	return 0;
}

/* END OF FILE */