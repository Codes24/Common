/*
 *	CHAT CLIENT HEADER FILE
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

#ifndef CLIENT_H
#define CLIENT_H
void open_client();
void* listen_thread(void* socket);

void* listen_thread(void* socket)
{
	char* message = malloc(1000*sizeof(char));
	while(1)
	{
		hear((int)(socket), message, 1000);
		puts(message);
	}
	free(message);
	pthread_exit(0);
}

void open_client()
{
	printf("+----------------------------------------------------+\n");
	printf("| Lan chat client                                    |\n");
	printf("| Run server as ./client IP_ADDRESS PORT             |\n");
	printf("| Type !exit or !quit to disconnected with server    |\n");
	printf("+----------------------------------------------------+\n");
}

#endif
/*	END OF FILE */