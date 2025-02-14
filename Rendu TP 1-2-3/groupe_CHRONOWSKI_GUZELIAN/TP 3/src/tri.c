/* Fichier tri.c
* Permet de trier un tableau de facon croissante
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/

#include <stdio.h> // Importation des bibliothèques nécessaires
#include <stdlib.h>
#include <time.h>

int main() {

    // Variables
    int taille = 100; // Taille du tableau à trié

    srand(time(NULL)); // Initialisation du générateur

    int tableau[taille];

    for (int i = 0; i < taille; i++) { // On remplie le tableau de valeurs random entre 0 et 100
        tableau[i] = rand() % taille+1;
    }

    for (int i = 0; i < taille-1; i++) { // Algorithme de tri par interversion
        for(int j = i+1; j < taille; j++) {
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

    return 0;
}