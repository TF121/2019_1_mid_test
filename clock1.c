/* clock1.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void clock_tick(int signo)
{
	printf("\r%ld", time(NULL));
	alarm(1);
}

void handler_init(int signo){
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, BUFSIZ);
	printf("\e[2J\e[H");
	
	if(signal(SIGALRM, clock_tick) == SIG_ERR)
		perror("cannot catch SIGARM");

	if(signal(SIGINT, handler_init) == SIG_ERR)
		perror("cannot catch SIGINIT");

	clock_tick(-1);

	for( ; ; )
		pause();
	
	exit(EXIT_SUCCESS);

	return(0);
}
