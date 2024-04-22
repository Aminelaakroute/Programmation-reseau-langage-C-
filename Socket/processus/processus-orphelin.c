#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
pid_t pid = fork(); // Création du processus fils
    
if(pid == -1)
{
   //Erreur de creation de processus 
  printf("Erreur de creation de processus !!");
}else if(pid == 0) 
{
   // Code du processus fils
   printf("Processus fils (PID: %d) démarré.\n", getpid());
   sleep(2); // Le processus fils dort pendant 2 secondes
   printf("Processus fils (PID: %d) terminé.\n", getpid());
   exit(1);
}else 
{
   // Code du processus parent
   printf("Processus parent (PID: %d) terminé.\n", getpid());
}
    
}
