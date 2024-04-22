#include<stdio.h>
#include<unistd.h>

//dans ce programme et plus precisement dans la fonction "if" apres la creation de processus avec fork, la processus prend un PID different a 0 et non negatif, dans ce cas le programme execute la partie parent, puis la creation d'un programme dupliquer, commence l'execution a partir de 'pid_t pid = fork() ;' jusau'a la fin de la fonction if 'else' dans ce cas le PID prend la valeur 0 et ca segnefie que la processus fils est creer avec succes

int main(){
pid_t pid = fork() ;

if(pid == -1)
{
  //Erreur de creation d'une precessus
  printf("Erreur de creation de processus !!\n");
}
else if(pid == 0)
{
  //processus fils
  printf("Processus fils Creer avec succes\n");
  printf("Fils_PID : %d\n", pid); 
  printf("Fils_PID : %d\n", getpid());
  printf("Parent_PID : %d\n", getppid());
}
else
{
  //processus parent
  printf("Processus parent Creer avec succes\n");
  printf("Parent_PID(pid) : %d\n", pid);
  printf("Parent_PID(getpid) : %d\n",getpid());
  
}

}