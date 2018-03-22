#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

//Only one process is given rtnice value, that process runs first
int main()
{    

    long int pid=fork();
    int val = 200;    
    
    if(pid!=0)
    {
        printf("Process 1 has PID: %ld\n",getpid());
        printf("Process 2 has PID: %ld\n",pid);

        int retval = syscall(323, pid, val);

        printf("Process 1 has rt_nice: 0\n");
        printf("Process 2 has rt_nice: %d\n", val);
        
    }

    
    if(pid == 0)
    {
        long sum = 0;
        long i = 0;
        for(i=0; i<2000000000; i++)
        {
            sum += i;       
        }
        
	printf("Process with PID: %ld terminated\n",getpid());
        
    }

    else
    {
        long sum=0;
        long i=0;
        for(i=0; i<2000000000; i++)
        {
            sum += i;     
        }
       
        printf("Process with PID: %ld terminated\n",getpid());
        wait(pid);
    }

    return 0;
}
