#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define PORT 1550

int main() {
    int idServeur, idClient, fd;
    struct sockaddr_in addrServeur, addrClient;
    char message[128];

    // Création du socket
    idServeur = socket(AF_INET, SOCK_STREAM, 0);
    if (idServeur == -1) {
        perror("Erreur lors de la création du socket serveur");
        exit(1);
    }

    // Configuration de l'adresse du serveur
    memset(&addrServeur, 0, sizeof(addrServeur));
    addrServeur.sin_family = AF_INET;
    addrServeur.sin_port = htons(PORT);
    addrServeur.sin_addr.s_addr = htonl(INADDR_ANY);

    // Liaison du socket
    if (bind(idServeur, (struct sockaddr *)&addrServeur, sizeof(addrServeur)) == -1) {
        perror("Erreur de bind !!!");
        close(idServeur);
        exit(1);
    }

    // Mise en écoute
    if (listen(idServeur, 10) == -1) {
        perror("Erreur de listen");
        close(idServeur);
        exit(1);
    }

    printf("En attente de connexion ...\n");

    // Accepter une connexion
    socklen_t addrClientLen = sizeof(addrClient);
    idClient = accept(idServeur, (struct sockaddr *)&addrClient, &addrClientLen);
    if (idClient == -1) {
        perror("Erreur lors de l'acceptation de la connexion");
        close(idServeur);
        exit(1);
    }

    // Lecture de la demande du client
    read(idClient, message, sizeof(message));
    printf("Demande du client : %s\n", message);

    // Traitement de la demande
    if (strcmp(message, "create_file") == 0) {
        // Création du fichier
        fd = open("nouveau_fichier.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
        if (fd == -1) {
            perror("Erreur lors de la création du fichier");
            close(idClient);
            close(idServeur);
            exit(1);
        }
        write(idClient, "Fichier créé avec succès.", sizeof("Fichier créé avec succès."));
        close(fd); // Fermeture du fichier
    } else {
        write(idClient, "Commande non reconnue.", sizeof("Commande non reconnue."));
    }

    // Fermeture des sockets
    close(idClient);
    close(idServeur);

    return 0;
}
