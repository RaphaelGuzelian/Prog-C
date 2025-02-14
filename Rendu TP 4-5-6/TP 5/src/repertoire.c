/* Fichier repertoire.c
* Permet de parcourir un répertoire donné en paramètre et d'afficher ce qu'il y a dedans
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/

#include <sys/types.h> // Importation des bibliothèques nécessaires
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "repertoire.h" // Importation des prototypes nécessaires


void lire_dossier(char *directory) {

    struct dirent *dir;
    DIR *dirp = opendir(directory); //Ouverture du dossier

    if (dirp == NULL) { //Si il n'y a rien dedans
        perror("opendir"); //No such file or directory
    } 
    while ((dir = readdir(dirp)) != NULL) { //Tant qu'il y a des fichiers, on les lit les noms
        printf("%s\n", dir->d_name);
    }

        closedir(dirp); //Fermeture du dossier
    
}

void lire_dossier_recursif(char *directory) {

    struct dirent *dir;
    DIR *dirp = opendir(directory); //Ouverture du dossier

    if (dirp == NULL) { //Si il n'y a rien dedans
        perror("opendir"); //No such file or directory
    } 
    
    while ((dir = readdir(dirp)) != NULL) { //Tant qu'il y a des fichiers, on les lit les noms
        printf("%s\n", dir->d_name);
        if ((dir->d_type == DT_DIR) && (strcmp(".", dir->d_name)) && (strcmp("..", dir->d_name))) { // Si c'est un dossier et pas les dossiers . et ..
            char *content = malloc(strlen(directory)+sizeof(char)*(strlen(dir->d_name)+2)); // Allocation dynamique de mémoire
            content = strcat(content, directory); // On crée le string contenant le nom du dossier
            content = strcat(content, "/");
            content = strcat(content, dir->d_name);
            lire_dossier_recursif(content);
            free(content); // Libération de la mémoire
        }
    }
        closedir(dirp); //Fermeture du dossier
}

void lire_dossier_iteratif(char *directory) {
    
    struct dirent *dir1;
    DIR *dirp1 = opendir(directory); //Ouverture du dossier

    if (dirp1 == NULL) { //Si il n'y a rien dedans
        perror("opendir dirp1"); //No such file or directory
    } 

    while((dir1 = readdir(dirp1)) != NULL) { //Tant qu'il y a des fichiers, on les lit les noms
        if ((strcmp(dir1->d_name, ".")) && (strcmp(dir1->d_name, ".."))) { // On prend pas en compte les . et ..
            printf("%s\n", dir1->d_name); // Affiche fichier et dossier du répertoire passé en commande
        }
        if ((dir1->d_type == DT_DIR) && (strcmp(".", dir1->d_name)) && (strcmp("..", dir1->d_name))) { //Si c'est un dossier
            struct dirent *dir2; 
            DIR *dirp2 = opendir(dir1->d_name);

            if (dirp2 == NULL) { //Si il n'y a rien dedans
                perror("opendir dirp2"); //No such file or directory
            } 

            while((dir2 = readdir(dirp2)) != NULL) { // On lit ce qu'il y a dans le dossier
                if ((strcmp(dir2->d_name, ".")) && (strcmp(dir2->d_name, ".."))) { // On prend pas en compte les . et ..
                        printf("%s\n", dir2->d_name); // Affiche fichier et dossier du dossier parent 
                }    
                if ((dir2->d_type == DT_DIR) && (strcmp(".", dir2->d_name)) && (strcmp("..", dir2->d_name))) { // Si c'est un dossier 
                    char *dossier = malloc(strlen(directory)+sizeof(char)*(strlen(dir2->d_name)+2)); 
                    dossier[0]='\0';
                    dossier = strcat(dossier, directory); // On crée le path par rapport au dossier passé par l'utilisateur     
                    dossier = strcat(dossier, "/");
                    dossier = strcat(dossier, dir1->d_name);
                    dossier = strcat(dossier, "/");
                    dossier = strcat(dossier, dir2->d_name);

                    struct dirent *dir3; 
                    DIR *dirp3 = opendir(dossier);

                    if (dirp3 == NULL) { //Si il n'y a rien dedans
                        perror("opendir dirp3"); //No such file or directory
                        
                    } 

                    while((dir3 = readdir(dirp3)) != NULL) { // On lit ce qu'il y a dans le dossier
                        if ((strcmp(dir3->d_name, ".")) && (strcmp(dir3->d_name, ".."))) { // On prend pas en compte les . et ..
                            printf("%s\n", dir3->d_name); // Affiche fichier et dossier du dossier parent
                        }
                    }
                }   
            }
        }
    }
}


int main(int argc, char *argv[]) {
    lire_dossier_iteratif(argv[1]);
    return 0;
}