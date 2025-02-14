/* Fichier sizeof_types.c
* Permet d'afficher la taille des différents types de base (en octets)
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/

#include <stdio.h> // Importation de la bibliothèque nécessaire

int main() {

    printf("sizeof(signed char) : %lu\n", sizeof(signed char)); // Affichage de la taille en octets du type de base voulu
    printf("sizeof(unsigned char) : %lu\n", sizeof(unsigned char));

    printf("sizeof(signed short) : %lu\n", sizeof(signed short));
    printf("sizeof(unsigned short) : %lu\n", sizeof(unsigned short));

    printf("sizeof(signed int) : %lu\n", sizeof(signed int));
    printf("sizeof(unsigned int) : %lu\n", sizeof(unsigned int));

    printf("sizeof(signed long int) : %lu\n", sizeof(signed long int));
    printf("sizeof(unsigned long int) : %lu\n", sizeof(unsigned long int));

    printf("sizeof(signed long long int) : %lu\n", sizeof(signed long long int));
    printf("sizeof(unsigned long long int) : %lu\n", sizeof(unsigned long long int));

    printf("sizeof(float) : %lu\n", sizeof(float));
    printf("sizeof(double) : %lu\n", sizeof(double));
    printf("sizeof(long double) : %lu\n", sizeof(long double));
    
    return 0;

}