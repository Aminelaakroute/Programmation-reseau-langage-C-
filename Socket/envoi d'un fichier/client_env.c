#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>



int main() {
    int idClient;
    struct sockaddr_in addrServeur;
    char message[128];
    FILE *file;

    // Création d'un fichier
    file = fopen("client_file.txt", "w");
    if (file == NULL) {
        perror("Erreur lors de la création du fichier");
        exit(1);
    }
    fprintf(file, "Master SSI \nContenu du fichier créé par le client.\n");
    fclose(file);

    // Création du socket
    idClient = socket(AF_INET, SOCK_STREAM, 0);
    if (idClient == -1) {
        perror("Erreur lors de la création du socket client");
        exit(1);
    }

    // Configuration de l'adresse du serveur
    memset(&addrServeur, 0, sizeof(addrServeur));
    addrServeur.sin_family = AF_INET;
    addrServeur.sin_port = htons(1550);
    addrServeur.sin_addr.s_addr = inet_addr("127.0.0.1"); // Adresse IP du serveur

    // Connexion au serveur
    if (connect(idClient, (struct sockaddr *)&addrServeur, sizeof(addrServeur)) == -1) {
        perror("Erreur lors de la connexion au serveur");
        close(idClient);
        exit(1);
    }

    // Demande au serveur de créer un fichier
    strcpy(message, "create_file");
    write(idClient, message, strlen(message));

    // Lecture de la réponse du serveur
    read(idClient, message, sizeof(message));
    printf("Réponse du serveur : %s\n", message);

    // Fermeture du socket client
    close(idClient);

    return 0;
}
