#include<stdio.h>
#include<netdb.h>
#include <stdlib.h>
#include <string.h>

void func1{

}
void func2{
    
}
int main(int argc , char * argv[]){
    int i ;
    struct in_addr adresse;
    unsigned long int reseau;
    unsigned long int locale;
    for (i = 1; i < argc; i++)
     { 
      fprintf (stdout, "inet_netof (%s) = ", argv [i]); 
      if (inet_aton (argv [i], & adresse) == 0) 
     { 
    fprintf (stdout, "invalide \n");
    continue;
     }
     
reseau = func1(adresse);
locale = func2(adresse);

    }



}