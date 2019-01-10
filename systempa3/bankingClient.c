#include "bankingClient.h"

int main(int argc, char* argv[]){

int clientSocket;
//struct addrinfo hints;
struct sockaddr_in serverAddr;
socklen_t addr_size;
char buffer[1024];
struct hostent *hostPtr;
char *IP;
char *hostDomain;
int sockfd = 0;
char *hello = "I am the client";
int val = 0;

hostDomain = (char*)malloc(sizeof(char)*255);

strcpy(hostDomain,argv[1]);

hostPtr = gethostbyname(hostDomain);

/* Create the socket */

	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("%s\n", "Socket Error");
		return -1;
	}

/* Initialize server address struct */

serverAddr.sin_family = AF_INET;

/* Set port number .. htons = host to network */

serverAddr.sin_port = htons(atoi(argv[2]));

/*Initialize IP address */

IP = (char*)malloc(sizeof(char)*255);

	if(hostPtr->h_addr_list[0] != NULL){
		strcpy(IP, inet_ntoa(*((struct in_addr*)hostPtr->h_addr_list[0])));
	}

	else{
		printf("%s\n", "Cannot find valid IP Address");
	} 

/*Set IP address to some address */

serverAddr.sin_addr.s_addr = inet_addr(IP);


printf("IP Address: %s\n", IP);
printf("Port Number: %d\n", serverAddr.sin_port);

/* Success */


	if(connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0 ){
		printf("%s", "Connection failed.");
		return -1;
	}

	else
	{
		printf("%s\n", "Client connection to Server success");
	}

	send(sockfd, hello, strlen(hello), 0);
	val = read(sockfd,buffer,1024);
	
	printf("%s\n", buffer);	
	

	










return 0;
}



