// sigactionH.h

#include <signal.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdio.h> 

void sig_int(int signo)
{
	sigset_t sigset, oldset;

	// 핸들러가 수행되는 동안 수신되는 모든 시그널에 대해서 블럭한다.
	sigfillset(&sigset);

	// blocking all signals while performing the handler function by putting SIG_BLOCK
	if(sigprocmask(SIG_BLOCK, &sigset, &oldset) < 0)
	{
		printf("sigprocmask %d error \n", signo);
	}

	fprintf(stderr,"SIGINT !!!!\n");

	sleep(10);
}

void sig_usr(int signo)
{
	printf("sig_usr: %d\n", signo);
}
