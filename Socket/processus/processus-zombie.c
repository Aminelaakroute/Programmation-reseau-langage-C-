#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
pid_t pid = fork();
if(pid == -1)
{
  //Erreur de creation de processus 
  printf("Erreur de creation de processus !!");
}
else if(pid == 0)
{
  //code du processus fils
  printf("Processus fils (PID : %d) demarre. \n",getpid());
  //sleep(2);
  printf("Processus fils (PID : %d) termine. \n",getpid());
  exit(1);
}
else
{
//code du processus parent 
printf("Processus parent (PID: %d) en attente...\n", getpid());
sleep(5);
//Attente de 5 secondes pour observer le processus zombie
        
//Le processus parent ne récupère pas le statut de sortie du processus fils
// Ce qui entraîne la création d'un processus zombie
system("ps -elf | grep $PPID | grep defunct");
printf("Processus parent terminé.\n");
}

}