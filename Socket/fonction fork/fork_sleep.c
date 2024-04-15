#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid = fork();
    if (pid == 0)
    {
        exit(1);
    }
    else if(pid > 0)
    {
        sleep(0);
        system("ps -elf | grep $PPID | grep defunct");
    }
    else
    {
        printf("Error spawning child \n");
        exit(1);
    }
    
    return 0 ;
}