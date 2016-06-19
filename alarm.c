#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

#define TIMEOUT 5

void catch()
{
	printf("alarm on\n");
}

int main()
{
	struct sigaction act;
	act.sa_handler = catch;
	sigaction(SIGALRM, &act, NULL);

	alarm(TIMEOUT);

	char s[5];
	scanf("%s", s);

	alarm(0);

	printf("5555");

	exit(0);
}
