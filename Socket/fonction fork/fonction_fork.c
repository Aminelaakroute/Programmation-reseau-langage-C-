#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>


int main(){
    pid_t pid =fork();



    if (pid == -1)
    {
        printf("Erreur dans la creation de la proocessus !!");
    }else if (pid == 0)
    {
        // Code exécuté par le processus fils
        printf("child processus pid = %d getpid = %d\n",pid,getpid());
    }else
    {
        // Code exécuté par le processus parent 
        printf("Parent processus pid = %d getpid = %d\n",pid,getpid());
    }

    
}