#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

int main(){

	char tab1[20], tab2[20];
	int fd[2] ;
	pipe(fd);
	pid_t pid = fork();

if(pid == 0){
	strcpy(tab1 , "Bonjour SSI");
	close(fd[0]);
	write(fd[1], tab1, strlen(tab1));
	close(fd[1]);
}else if(pid > 0){
	close(fd[1]);
	read(fd[0],tab2,sizeof(tab2));
	close(fd[0]);
	printf("%s\n", tab2);

}
}
