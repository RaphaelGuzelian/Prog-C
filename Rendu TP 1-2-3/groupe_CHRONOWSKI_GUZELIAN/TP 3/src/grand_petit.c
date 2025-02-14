/* Fichier grand_petit.c
* Permet d'afficher la valeur max et min dans un tableau
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/

#include <stdio.h> // Importation des bibliothèques nécessaires
#include <stdlib.h>
#include <time.h>

int calculs(int *tableau) {
    /*Fonction permettant de calculer le max et le min d'un tableau en paramètre
    Entrée : tableau
    Sortie : affichage du max et min
    */
    int max = 0; 
    for (int i = 0; i < 100; i++) {  // On cherche le plus grand numero du tableau
        if (tableau[i] >= max) {
            max = tableau[i];
        }
    }

    int min = max;
    for (int i = 0; i < 100; i++) {  // On cherche le plus petit numero du tableau
        if (tableau[i] <= min) {
            min = tableau[i];
        }
    }
    printf("Le plus grand numero du tableau est %d et le plus petit est %d\n",max,min); //Affichage du max et min
}


int main() {
    srand(time(NULL)); // Initialisation du générateur

    int tableau[100];
    for (int i = 0; i < 100; i++) { // On remplie le tableau de valeur random entre 0 et 100
        tableau[i] = rand() % 101;
        printf("%d\n",tableau[i]);
    }
    calculs(tableau); // On appelle la fonction 'calculs'
    return 0;
}