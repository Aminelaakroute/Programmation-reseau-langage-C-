#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    // Vérifier que deux arguments sont fournis (adresse IP et masque)
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <adresse IP> <masque>\n", argv[0]);
        return 1; // Indique une erreur
    }

    struct in_addr adresse, masque;
    struct in_addr reseau, locale;

    // Conversion des arguments (adresse IP et masque) en format réseau
    if (inet_aton(argv[1], &adresse) == 0 || inet_aton(argv[2], &masque) == 0) {
        fprintf(stderr, "Erreur lors de la conversion de l'adresse IP ou du masque.\n");
        return 1; // Indique une erreur
    }

    // Conversion en format hôte pour les opérations
    adresse.s_addr = ntohl(adresse.s_addr);
    masque.s_addr = ntohl(masque.s_addr);

    // Calcul des adresses réseau et locale
    reseau.s_addr = htonl(adresse.s_addr & masque.s_addr);
    locale.s_addr = htonl(adresse.s_addr & ~masque.s_addr);

    // Affichage des résultats
    fprintf(stdout, "Adresse réseau: %s\n", inet_ntoa(reseau));
    fprintf(stdout, "Adresse locale: %s\n", inet_ntoa(locale));

    return 0;
}
