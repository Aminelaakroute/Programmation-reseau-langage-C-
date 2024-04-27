#include<stdio.h>
#include<netdb.h>


int main()
{
struct protoent *proto ;
setprotoent(1); //ouvre le fichier des protocoles

int i = 1 ;
while((proto = getprotoent()) != NULL){
   
   printf("%d : %s\n",i,proto -> p_name);
   i++;
   
}


endprotoent(); //ferme le fichier des protocoles
return (0);
}
