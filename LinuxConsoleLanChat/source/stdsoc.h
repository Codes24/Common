/*
 *	STANDARD HEADER FILE FOR SOCKET PROGRAMMING
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

#ifndef STDSOC_H
#define STDSOC_H
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int init_socket();
int bind_to_port(int socket, int port);
void listen_client(int socket, int number_of_clients);
int say(int socket, const char* message);
int hear(int socket, char* buf, int len);

int init_socket()
{
	int s;
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0)
	{
		puts("ERROR::INITIALIZE::SOCKET");
		exit(0);
	}
	puts("Socket have been created ... ");
	return s;
}

int bind_to_port(int socket, int port)
{
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(port);
    if ((bind(socket, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0) 
    	return -1;
    puts("Bind socket successful ... ");
    return 1;
}

void listen_client(int socket, int number_of_clients)
{
	listen(socket, number_of_clients);
}
int say(int socket, const char* message)
{
	int result = send(socket, message, strlen(message), 0);
	if (result == -1)
	{
		printf("ERROR::SEND::MESSAGE::#%d\n", socket);
	}
	return result;
}
int hear(int socket, char* buf, int len)
{
	char *s = buf;
	int slen = len;
	int c = recv(socket, s, slen, 0);
	while ((c > 0) && (s[c-1] != '\n')) {
		s += c; slen -= c;
		c = recv(socket, s, slen, 0);
	}
	if (c < 0)
		return c;
	else if (c == 0)
		buf[0] = '\0';
	else
		s[c-1]='\0';
	return len - slen;
}

#endif

/*	END OF FILE */