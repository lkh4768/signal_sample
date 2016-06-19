#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void catchint(int signo)
{
	printf("\nCATCHINT: signo=%d\n", signo);
	printf("CACHINT: returning\n\n");
}

int main()
{
	static struct sigaction act, oldact;
	act.sa_handler = catchint;
	sigfillset(&(act.sa_mask));
	sigaction(SIGINT, &act, &oldact);

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
