/* Fichier tableauptr.c
* Permet de multiplier par 3 une valeur dans un tableau si son indice est divisible par 2 grâce aux pointeurs
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
* Commentaires : On pourrait avoir le choix du nombre d'éléments à mettre dans les tableaux
*/


#include <stdio.h> // Importation des bibliothèques nécessaires
#include <stdlib.h>
#include <time.h>


int main() {

    int tableau_int[5]; // Création du tableau de int
    float tableau_float[5]; // Création du tableau de float

    srand(time(NULL)); // Initialisation du générateur 

    for (int i = 0; i < 5; i++) { // On remplie les tableaux de int et float randoms
        *(tableau_int+i) = rand() % 10;
        *(tableau_float+i) = (float)rand() / 1000;
    } 


    for (int i = 0; i < 5; i++) { // Affichage des anciens int 
        printf("Ancien int : %d\n",*(tableau_int+i));
    }

    for (int i = 0; i < 5; i++) { // Affichage des anciens float
        printf("Ancien float : %f\n",*(tableau_float+i));
    }



    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) { 
            *(tableau_int+i) *= 3; // Accès à l'élément de 'tableau_int' si son indice est divisible par 2, et multiplication de la valeur associée par 3
            *(tableau_float+i) *= 3; // Accès à l'élément de 'tableau_float' si son indice est divisible par 2, et multiplication de la valeur associée par 3
        } 
    }



    for (int i = 0; i < 5; i++) { // Affichage des nouveaux int
        printf("Nouveau int : %d\n",*(tableau_int+i));
    }

    for (int i = 0; i < 5; i++) { // Affichage des nouveaux float
        printf("Nouveau float : %f\n",*(tableau_float+i));
    }
    
    return 0;
}