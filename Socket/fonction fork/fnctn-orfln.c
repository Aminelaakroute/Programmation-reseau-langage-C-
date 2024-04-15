#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
//C'est pas une fonction orphelin !!!!!!!!!!!!!!!!!!!!!!!!!!!
int main(){
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
    }
    else if(pid == 0)
    {
        //code de processus enfant
        printf("je suis le processus enfant avec PID : %d\n",getpid());
        sleep(5);
        printf("Processus enfant termine \n");

    }
    else
    {
        printf("Je suis le processus parent avec PID : %d\n",getpid());
        printf("Je vais attendre la termination du prcessus enfant.\n");
        wait(NULL);
        printf("Processus parent termine\n");
    }
    
    return 0 ;
}