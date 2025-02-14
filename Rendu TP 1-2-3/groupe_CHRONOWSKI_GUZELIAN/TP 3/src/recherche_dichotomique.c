/* Fichier recherche_dichotomique.c
* Permet de voire si il y a une valeur dans un tableau trié
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/

#include <stdio.h> //  Importation des bibliothèques nécessaires
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {

    // Variables
    int taille = 100; // Taille du tableau
    int tableau[taille];
    int val = 10;// Valeur recherchée
    int d=0;
    int f=taille;

    srand(time(NULL)); // Initialisation du générateur

    for (int i = 0; i < taille; i++) { // On remplie le tableau de valeurs random entre 0 et 100
        tableau[i] = rand() % taille+1;
    }

    for (int i = 0; i < 99; i++) { // Algorithme de tri par interversion
        for(int j = i+1; j < 100; j++) {
            if (tableau[i]>tableau[j]){
                int tmp=tableau[i];
                tableau[i]=tableau[j];
                tableau[j]=tmp;
            }
        }
    }
    
    for (int i = 0; i < taille; i++) { // Affichage du tableau trié
        printf("%d, ",tableau[i]);
    }
    printf("\n");

    while((d<f)){ // Recherche de la valeur via fragmentation du tableau
        int m = floor((f+d)/2);
        if (tableau[m]==val){
            printf("La valeur %d est dans la liste à la valeur %d.\n",val,m);
            break;
        }
        if ((m==d)||(m==f)){
            printf("La valeur %d n'est pas dans la liste.\n",val);
            break;
        }
        else {
            if (val> tableau[m]) {
                d=m+1;
            }
            else{
                f=m-1;
            }
        }
    }
    return 0;
}