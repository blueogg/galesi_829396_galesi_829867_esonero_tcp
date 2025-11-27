/*
 * main.c
 *
 * TCP Client - Template for Computer Networks assignment
 *
 * This file contains the boilerplate code for a TCP client
 * portable across Windows, Linux and macOS.
 */
#define MAXCITYLENGHT 10
#define MAXADDRLENGHT 16
#if defined WIN32
#include <winsock.h>
#else
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#define closesocket close
#endif

#include <stdio.h>
#include <stdlib.h>
#include "protocol.h"

#define NO_ERROR 0

void errorhandler(char* errormessage){

	printf("%s\n", errormessage);
}

void clearwinsock() {
#if defined WIN32
	WSACleanup();
#endif
}



int main(int argc, char *argv[]) {

	//OTTIENE VALORE PARAMETRI

	char* luogo = NULL;
	long port = 0;
	char* indirizzo = NULL;

	for(int i = 1; i < argc; i++){

		if(strcmp(argv[i], "-s") == 0){
			indirizzo = malloc(MAXADDRLENGHT * sizeof(char));
			strcpy(indirizzo, argv[i + 1]);

		}
		if(strcmp(argv[i], "-p") == 0){
		port = strtol(argv[i + 1], NULL, 10);

		}

		if(strcmp(argv[i], "-t") == 0){
			luogo = malloc(MAXCITYLENGHT * sizeof(char));
			strcpy(luogo, argv[i  + 1]);
		}

	}





#if defined WIN32
	// Initialize Winsock
	WSADATA wsa_data;
	int result = WSAStartup(MAKEWORD(2,2), &wsa_data);
	if (result != NO_ERROR) {
		printf("Error at WSAStartup()\n");
		return 0;
	}
#endif

	int my_socket;
	memset(&my_socket, 0, sizeof(my_socket));
	my_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.S_un.S_addr = indirizzo == NULL ? inet_addr("127.0.0.1") : inet_addr(indirizzo);
	server_addr.sin_port = port == 0 ? htons(SERVER_PORT) : htons(port);

	if(connect(my_socket, (struct sockaddr*)&server_addr, sizeof(server_addr) < 0)){

		errorhandler("Connessione non andata a buon fine!");
		closesocket(my_socket);
		clearwinsock();
		return -1;

	}




	// TODO: Implement communication logic
	// send(...);
	// recv(...);

	// TODO: Close socket
	// closesocket(my_socket);

	printf("Client terminated.\n");

	clearwinsock();
	return 0;
} // main end
