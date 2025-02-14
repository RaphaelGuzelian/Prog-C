/* Fichier octets.c
* Permet d'afficher les octets d'un type 
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/


#include <stdio.h> // Importation de la bibliothèque nécessaire

int main(){

    // Variables 
    short a = 10;
    int b = 300;
    long int c = 123456789;
    float d = 10.10;
    double e = 123456.123456;
    long double f = 123456789.123456789;

    unsigned char *ptra = NULL;
    unsigned char *ptrb = NULL;
    unsigned char *ptrc = NULL;
    unsigned char *ptrd = NULL;
    unsigned char *ptre = NULL;
    unsigned char *ptrf = NULL;

    // Assignations des adresses 
    ptra = (unsigned char *)&a;
    ptrb = (unsigned char *)&b;
    ptrc = (unsigned char *)&c;
    ptrd = (unsigned char *)&d;
    ptre = (unsigned char *)&e;
    ptrf = (unsigned char *)&f;

    // Affichage

    for(int i = sizeof(a)-1; 0 <= i; i--){
        printf("%x ", *(ptra+i));
    }

    printf("\n");

    for(int i = sizeof(b)-1; 0 <= i; i--){
        printf("%x ", *(ptrb+i));
    }

    printf("\n");

    for(int i = sizeof(c)-1; 0 <= i; i--){
        printf("%x ", *(ptrc+i));
    }

    printf("\n");

    for(int i = sizeof(d)-1; 0 <= i; i--){
        printf("%x ", *(ptrd+i));
    }

    printf("\n");

    for(int i = sizeof(e)-1; 0 <= i; i--){
        printf("%x ", *(ptre+i));
    }

    printf("\n");

    for(int i = sizeof(f)-1; 0 <= i; i--){
        printf("%x ", *(ptrf+i));
    }

    printf("\n");
}