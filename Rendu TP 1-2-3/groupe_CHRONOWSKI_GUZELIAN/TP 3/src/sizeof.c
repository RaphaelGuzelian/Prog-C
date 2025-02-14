/* Fichier sizeof.c
* Permet d'afficher la taille en octets de différents types
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/

#include <stdio.h> // Importation de la bibliothèque nécessaire

int main() {
    printf("La taille de int est de %d octets\n",sizeof(int));
    printf("La taille de int * est de %d octets\n",sizeof(int *));
    printf("La taille de int ** est de %d octets\n",sizeof(int **));
    printf("La taille de char * est de %d octets\n",sizeof(char *));
    printf("La taille de char ** est de %d octets\n",sizeof(char **));
    printf("La taille de char *** est de %d octets\n",sizeof(char ***));
    printf("La taille de float * est de %d octets\n",sizeof(float *));
    printf("La taille de float ** est de %d octets\n",sizeof(float **));
    printf("La taille de float *** est de %d octets\n",sizeof(float ***));
    return 0;
}

