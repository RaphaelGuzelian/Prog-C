/* Fichier fichier.c
* Permet de lire et écrire dans un fichier texte
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/

#include <stdio.h> // Importation des bibliothèques nécessaires
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void lire_fichier(char *nom_de_fichier) { // Fonction permettant de lire un fichier donné en paramètre
    char content;
    int fd, size;
    fd = open (nom_de_fichier, O_RDONLY); // Ouverture du fichier en lecture seulement
    while (1) {
        size = read(fd, &content, 1);
        if (size < 1) { // Condition permettant de vérifier si il reste un caractère à lire
            break;
        }
        printf("%c", content); // Affichage du caractère
    }
    close(fd); // Fermeture du fichier
}

void ecrire_dans_fichier(char *nom_de_fichier, char *message) { // Fonction permettant d'écrire dans un fichier donné en paramètre
    int fd, size;
    fd = open (nom_de_fichier, O_CREAT|O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR); // Ouverture du fichier
    size = write(fd, message, strlen(message)); // Ecriture du message
    close(fd); // Fermeture du fichier
}

