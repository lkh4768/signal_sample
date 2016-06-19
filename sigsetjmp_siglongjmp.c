#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

#include<setjmp.h>

sigjmp_buf position;

void catchint(int signo)
{
	printf("siglongjmp start\n");
	siglongjmp(position, 1);
}

int main()
{
	static struct sigaction act, oldact;
	sigfillset(&(act.sa_mask));

	if(sigsetjmp(position, 1) == 0)
	{
		printf("sigsetjmp start\n");
		act.sa_handler = catchint;
		sigaction(SIGINT, &act, &oldact);
	}

	int i = 0;
	while(1)
	{
		printf("sleep call#%d\n", i++);
		sleep(1);
		if(i == 5)
			sigaction(SIGINT, &oldact, NULL);

	}
	exit(0);
}
