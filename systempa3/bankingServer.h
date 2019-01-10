#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <pthread.h>
/* A new account with all the information. */

typedef struct CLIENT_ACCOUNT{
char* accountName;
double currentBalance;
bool flag; 
}account;


/* Methods */

account* create(char* accountName);

void serve(account* current);

void deposit(double amount, account* current);

double withdraw(double amount, account* current);

/* Returns this struct's current balance */
double query(account* currentBalance);

void end(account* current);

void quit();
