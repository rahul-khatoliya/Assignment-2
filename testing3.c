#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/time.h>

// No process has any rtnice value, all processes run as per original scheduler, hence runs simultaneously and terminate together

int main()
{
	
	long int pid=fork();
	
	if(pid!=0)
	{
		printf("Process 1 has PID: %ld\n",getpid());
		printf("Process 2 has PID: %ld\n",pid);
		printf("Process 1 has rt_nice: 0 \n");
		printf("Process 2 has rt_nice: 0 \n");
	}

	
	if(pid==0)
	{
		long sum = 0;
		long i = 0;
		for(i=0; i<1000000000; i++)
		{
			sum += i;		
		}
		
		printf("Process with PID %ld terminated \n",getpid());
		
	}



	else
	{
	
		long sum = 0;
		long i = 0;
		for(i=0; i<1000000000; i++)
		{
			sum += i;
		}
	
		printf("Process with PID %ld terminated \n",getpid());
		wait(pid);
	}

	return 0;
}
