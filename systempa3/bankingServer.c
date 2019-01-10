#include "bankingServer.h"


//void sigIntHandler(int sig){
//	printf("%s\n", "Signal caught");

//}


void *show(void* thr){
printf("%s\n", "New Thread");
}


int main(int argc, char* argv[]){
int connfd = 0, sockfd = 0, new_socket = 0;
int val = 0;
struct sockaddr_in serv_addr;
char *hello = "I am the server";
char buff[1000] = {0};
int opt = 1;
int serv_len = sizeof(serv_addr);
/*Create file socket descriptor*/
if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
	printf("%s", "Socket failed");
	exit(-1);
}

/*Set the socket*/
if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
{
	printf("%s" "Set socket failure");
	exit(-1);
}



serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
serv_addr.sin_port = htons(atoi(argv[1]));

/*Bind*/
if(bind(sockfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr))){
	printf("%s", "Bind failure");
	exit(-1);
}

/*Listen*/
if(listen(sockfd,3) < 0 )
{
	printf("%s", "Listen failure");
	exit(-1);
}


/*Create a session thread */
pthread_t sessionThread;
pthread_create(&sessionThread, NULL, &show, NULL);



while(1)
{


if((new_socket=accept(sockfd, (struct sockaddr*)&serv_addr, (socklen_t*)&serv_len))<0)
{
	printf("%s", "Accept failure");
	//exit(EXIT_FAILURE);
}

else
{
printf("%s\n", "Server accepts connection from client");
}

/*Session-acceptor thread will spawn client-service thread */

//pthread_t clientThread;
//pthread_create(&clientThread, NULL, NULL, NULL);
//printf("%s\n", "Created client thread");
 

val = read(new_socket,buff,1000);
printf("%s\n", buff);
send(new_socket, hello, strlen(hello), 0);


printf("%s\n", "Thread");
//pthread_join(clientThread,NULL);
}

pthread_join(sessionThread,NULL);

return 0;
}


account* create(char* accountName){
account* newAccount = (account*)malloc(sizeof(account));
newAccount->accountName = accountName;
newAccount->currentBalance = 0;
newAccount->flag = 0;
return newAccount;
}

void serve(account* current){
current->flag = 1;

}

void deposit(double amount, account* current){
current->currentBalance += amount;

}

double withdraw(double amount, account* current){
current->currentBalance -= amount;
}

double query(account* current){
return current->currentBalance;
}

void end(account* current){
current->flag = 0;
}

void quit(){

}









