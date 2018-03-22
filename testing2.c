#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

// 2 processes have rtnice values, the process with lower PID value runs first
int main()
{
	long int pid=fork();

	int value1 = 0;
	int value2 = 0;

	if(pid != 0)
	{
		printf("Process 1 has PID: %ld\n", getpid());
		printf("Process 2 has PID: %ld\n", pid);
		
		value1 = syscall(323, pid, 20000);
		value2 = syscall(323, getpid(), 200);

		if(value1 == 0 && value2 == 0)
		{
			printf("Process 1 has rt_nice: 200\n");
			printf("Process 2 has rt_nice: 20000\n");
		}

		else
		{
			printf("System call generated an error\n");
		}
	}

	
	if(pid==0)
	{

		long sum = 0;
		long i = 0;
		for(i=0; i<3000000000; i++)
		{
			sum += i;
		}

		printf("Process with PID: %ld terminated\n", getpid());
		
	}

	else
	{
		
		long sum = 0;
		long i = 0;
		for(i=0; i<3000000000; i++)
		{
			sum += i;
	
		}

		printf("Process with PID: %ld terminated\n", getpid());
		wait(pid);
	}

	return 0;
}
