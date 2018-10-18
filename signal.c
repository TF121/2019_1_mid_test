#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// user signal gandler
static void sig_usr(int signo)
{
	if(signo == SIGUSR1)
		printf("received SIGUSR 1: %d\n", signo);
	else if(signo == SIGUSR2)
		printf("received SIGUSR 2: %d\n", signo);
	else if(signo == SIGTERM)
		printf("received SIGTERNM, die hard!!! ;) \n");
}

int main()
{
	// signal handler registration
	if(signal(SIGUSR1, sig_usr) == SIG_ERR)
		perror("cannot catch SIGUSR1 \n");
	if(signal(SIGUSR2, sig_usr) == SIG_ERR)
		perror("cannot catch SIGUSR2 \n");
	if(signal(SIGTERM, sig_usr) == SIG_ERR)
		perror("cannot catch SIGTERM \n");

	for( ; ; )
		sleep(60);

	return 0;
}

