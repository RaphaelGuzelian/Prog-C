/* Fichier variables.c
* Permet  d'affecter et afficher les valeurs des variables des différents types de base
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/

#include <stdio.h> // Importation de la bibliothèque nécessaire

int main() {

    signed char a = -5; // Affectation d'une valeur à la variable d'un certain type
    unsigned char b = 5;

    signed short c =  -30000;
    unsigned short d = 30000;

    signed int e = -55555;
    unsigned int f = 55555;

    signed long int g = -5555555;
    unsigned long int h = 5555555;

    signed long long int i = -555555555555;
    unsigned long long int j = 555555555555;

    float k = 3.14;
    double l = 156123.124;
    long double m = 15622223.1515;
    
    printf("a : %c \n",a); // Affichage de la valeur des variables des différents types de base
    printf("b : %hhu \n",b);
    printf("c : %hd \n",c);
    printf("d : %hu \n",d);
    printf("e : %d \n",e);
    printf("f : %u \n",f);
    printf("g : %ld \n",g);
    printf("h : %lu \n",h);
    printf("i : %lld \n",i);
    printf("j : %llu \n",j);
    printf("k : %f \n",k);
    printf("l : %g \n",l);
    printf("m : %Lg \n",m);
    return 0;

}