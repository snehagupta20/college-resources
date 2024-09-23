#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int pid = fork();
	if (pid == 0)
	{
		printf("child process: pid =%d, ppid=%d\n",getpid(),getppid());
		char *args[]={"ls","-l",NULL};
		execvp("ls",args);
	}
	else{
		printf("parent process:pid=%d, ppid=%d\n", getpid(),getppid());
		wait(NULL);
	}
	return 0;
}
