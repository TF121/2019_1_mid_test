/* signal to parent.c */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

// user signal handler
static void sig_usr(int signo)
{
	if(signo == SIGUSR1)
		printf("SIGUSR1 received from its child\n");
	else if(signo == SIGUSR2)
		printf("SIGUSR2 received from its child\n");
	/*
	else if(signo == SIGINT)
		printf("SIGNIT received from its child\n");
	*/

}

int main()
{
	// 자식 프로세스
	if(!fork())
	{
		int ppid;

		ppid = getppid();
		kill(ppid, SIGUSR1);
		kill(ppid, SIGUSR2);
		kill(ppid, SIGINT);

		exit (0);
	}

	// 부모 프로세스
	else
	{
		// signal handler registration
		if(signal(SIGUSR1, sig_usr) == SIG_ERR)
			perror("cannot catch SIGUSR1\n");
		if(signal(SIGUSR2, sig_usr) == SIG_ERR)
			perror("cannot catch SIGUSR2\n");

	/*
	   if(signal(SIGINT, sig_usr) == SIG_ERR)
			perror("cannot catch SIGINT\n");
	*/

		// 자식 프로세스의 종료를 기다리기
		wait(NULL);

	}
	return 0;
}
