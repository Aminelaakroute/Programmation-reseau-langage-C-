#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {


    int i ;
    struct in_addr adresse, masque;
    struct in_addr reseau, locale;

    
    fprintf (stdout, "l'adresse est : %s \t le massaue est %s\n", argv [1],argv[2]);
    
    
    inet_aton(argv[1], &adresse);
    inet_aton(argv[2], &masque);

    reseau.s_addr = adresse.s_addr & masque.s_addr;
    locale.s_addr = adresse.s_addr & ~masque.s_addr;

    
    fprintf(stdout, "Adresse réseau: %s\n", inet_ntoa(reseau));
    fprintf(stdout, "Adresse locale: %s\n", inet_ntoa(locale));

    return 0;
}