#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<netdb.h>
#include<unistd.h>
#include<sys/types.h>


int main()
{
    struct sockaddr_in addr1 , addr2;
    int id1, id2, len1;
    char mes[128];
    
// Création du socket IPv4
    id1 = socket(AF_INET, SOCK_STREAM, 0);
    if (id1 == -1) {
        perror("Erreur lors de la création du socket");
        exit(1);
    }

// Configuration de l'adresse IPv4
    memset(&addr1, 0, sizeof(addr1));
    addr1.sin_family = AF_INET;
    addr1.sin_port = htons(1550);
    addr1.sin_addr.s_addr = INADDR_ANY;

if (bind(id1,(struct sockaddr *)&addr1, sizeof(addr1))==-1)
{
    printf("Erreur de bind !!!");
    exit(1);

}
listen(id1,10);
printf("En attente de connexion ...\n ");

len1 = sizeof addr2 ;
id2 = accept(id1,(struct sockaddr *)&addr2,&len1);


    printf("Machine connecte \n Message : ");
    read(id2, mes, 128);
    printf("%s", mes);
    close(id1);

}
