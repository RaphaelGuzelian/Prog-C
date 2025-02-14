/* Fichier chercherfichier.c
* Permet de chercher un mot dans un fichier et d'afficher la ligne et le nombre de fois qu'il est présent
* Auteurs : Amaury Chronowsky, Raphaël Guzélian 
*/


#include <stdio.h> // Importation des bibliothèques nécessaires
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int recherche(char *phrase, char *fichier) {
    /* Fonction permettant d'afficher la ligne et le nombre de fois que le mot est présent
       Entrées : Mot à chercher et le fichier où chercher
       Sortie : Affichage de la ligne et le nombre de fois que le mot est présent
    */
    char *phrase_cherche = phrase;

    char content[1000];
    int fd, size;
    unsigned int lettre_ok = 0, compteur = 0, numero_ligne = 1;

    fd = open (fichier, O_RDONLY);
    size = read(fd, content, 1000);

    for (int i=0; i<size; i++) { 
        lettre_ok=0;
        
        if (content[i] == '\n') { // Si on arrive en fin de ligne
            if (compteur > 0) { 
                printf("Ligne %d : %d fois\n", numero_ligne, compteur); // On affiche si on a trouvé le mot
            }
            numero_ligne++;
            compteur=0;
        }

        for (unsigned int j=0; j<strlen(phrase_cherche); j++) { //Parcours de la phrase cherchée pour pouvoir comparer
            if (content[i] == phrase_cherche[j]) { //Si les lettres correspondent avec le mot recherché
                lettre_ok++;
                i++;
            } 
            if (lettre_ok == strlen(phrase_cherche) && (content[i] == ' ' ||  content[i] == '\n')) { //Si on a trouvé le mot recherché
                compteur++;
                lettre_ok=0; //On met à zéro pour pouvoir voir si le même mot est encore présent sur la même ligne
                
            }
        }

    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 3) { // Sécurité
        puts("NB argument insuffisant: 2 requis");
        exit(-1);
    }
    recherche(argv[1],argv[2]);
    return 0;
}

    

            

    
        
        



