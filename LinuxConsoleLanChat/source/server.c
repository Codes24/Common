/*
 * 	SIMPLE CHAT SERVER MANAGER
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
#include "server.h"

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		printf("Please run server as ./server PORT\n");
		exit(0);
	}
	open_server();
	signal(SIGINT, signal_handler);
	/* 
	 *	Begin BLAB 
	 * 	Bind to port
	 *	Listen
	 *	Accept
	 * 	Begin Talk
	*/
	int server_socket = init_socket();	/* server main socket */
	if (bind_to_port(server_socket, atoi(argv[1])) == -1)
	{
		printf("ERROR::BIND::TO::PORT\n");
		exit(-1);
	}	
	listen_client(server_socket, NUM_CLIENT);
	struct sockaddr_storage client_addr;	/* hold EndPoint's information, ip address, protocal, port ... */
	unsigned int address_size = sizeof(client_addr);	/* size of client_addr */
	puts("Waiting for connection ... ");
	int connection;	/* hold socket value */
	char* message = malloc(1000*sizeof(char));	/* buffer message */
	int thread_index = 0;	/* index of thread array */
	pthread_t thread[NUM_CLIENT];	/* thread array */
	pthread_attr_t attr[NUM_CLIENT];/* thread attritue array */
	while(1)
	{
		connection = accept(
			server_socket, 
			(struct sockaddr*)&client_addr, 
			&address_size
		);
		if (connection < 0)
		{
			puts("ERROR::SERVER::ACCEPT::CLIENT");
			exit(-1);
		}
		save_soc(connection);
		pthread_attr_init(&attr[thread_index]);
		int rc = pthread_create(
			&thread[thread_index], 
			&attr[thread_index], 
			handle_thread, 
			(void*)(connection)
		);
		if (rc < 0)
			puts("ERROR::CAN'T::CREATE::THREAD");
		thread_index++;
	}
	close(server_socket);
	free(message);
	return 0;
}

/* END OF FILE */