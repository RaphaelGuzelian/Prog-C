/* Fichier ptvariables.c
* Donne les adresses où sont stockées les variables et affiche les variables avec les adresses
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
* Commentaire : On pourrait afficher les octets en valeur décimale en séparant la valeur en hexadécimal
*/


#include <stdio.h> // Importation des bibliothèques nécessaires 
int main() {

    signed char a = 20;
    signed char *signed_char_ptr=&a;

    unsigned char b = 5;
    unsigned char *unsigned_char_ptr=&b;


    signed short c =  -30000;
    signed short *signed_short_ptr=&c;

    unsigned short d = 30000;
    unsigned short *unsigned_short_ptr=&d;


    signed int e = -55555;
    signed int *signed_int_ptr=&e;   

    unsigned int f = 55555;
    unsigned int *unsigned_int_ptr=&f; 


    signed long int g = -5555555;
    signed long int *signed_long_int_ptr=&g;  

    unsigned long int h = 5555555;
    unsigned long int *unsigned_long_int_ptr=&h;


    signed long long int i = -555555555555;
    signed long long int *signed_long_long_int_ptr=&i;

    unsigned long long int j = 555555555555;
    unsigned long long int *unsigned_long_long_int_ptr=&j;


    float k = 3.14;
    float *float_ptr=&k;


    double l = 156123.124;
    double *double_ptr=&l;


    long double m = 15622223.1515;
    long double *long_double_ptr=&m;
    

    // Affichage
    printf("a : %hhu, adresse : %p \n",*signed_char_ptr,signed_char_ptr);
    printf("b : %hhu, adresse : %p \n",*unsigned_char_ptr,unsigned_char_ptr);
    printf("c : %hd, adresse : %p \n",*signed_short_ptr,signed_short_ptr);
    printf("d : %hu, adresse : %p \n",*unsigned_short_ptr,unsigned_short_ptr);
    printf("e : %d, adresse : %p \n",*signed_int_ptr,signed_int_ptr);
    printf("f : %u, adresse : %p \n",*unsigned_int_ptr,unsigned_int_ptr);
    printf("g : %ld, adresse : %p \n",*signed_long_int_ptr,signed_long_int_ptr);
    printf("h : %lu, adresse : %p \n",*unsigned_long_int_ptr,unsigned_long_int_ptr);
    printf("i : %lld, adresse : %p \n",*signed_long_long_int_ptr,signed_long_long_int_ptr);
    printf("j : %llu, adresse : %p \n",*unsigned_long_long_int_ptr,unsigned_long_long_int_ptr);
    printf("k : %f, adresse : %p \n",*float_ptr,float_ptr);
    printf("l : %g, adresse : %p \n",*double_ptr,double_ptr);
    printf("m : %Lg, adresse : %p \n",*long_double_ptr,long_double_ptr);

    return 0;
}
