// clock.c 와 비슷한 coredump 되는 예제
// 기존의 coredump 되는 과정과는 다르게 강제로 SIGQUIT를 넣어 프로세스 종료를 유도함
// 한마디로 정상적인 종료 동작을 하도록 강제로 변경

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig)
{
	if(sig == SIGINT)
		printf("SIGINT is tranfered \n");

	if(sig == SIGQUIT)
	{
		printf("SIGQUIT is tranfered \n");
		exit(1);
	}

}

int main(int argc, char *argv[])
{
	if(signal(SIGINT, signal_handler) == SIG_ERR)
	{
		printf("signal error\n");
		exit(1);
	}

	if(signal(SIGQUIT, signal_handler) == SIG_ERR)
		//if(signal(SIGQUIT, SIG_DFL) == SIG_ERR)
	{
		printf("signal error\n");
		exit(1);
	}	

	//while(getchar() != 'q');
	for(;;)
	{
		printf("main function is paused, PID = %d \n", getpid());
		pause();
	}

	return 0;
}
