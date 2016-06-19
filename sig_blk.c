#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main()
{
	int i;
	sigset_t set;

	sigfillset(&set);

	sigprocmask(SIG_SETMASK, &set, NULL);
	for(i = 0; i< 10; i++)
	{
		printf("important#%d\n", i);
		sleep(1);
	}

	sigprocmask(SIG_UNBLOCK, &set, NULL);
	for(i = 0; i< 10; i++)
	{
		printf("nomal#%d\n", i);
		sleep(1);
	}

	exit(0);
}
