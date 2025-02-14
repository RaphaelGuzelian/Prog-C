/* Fichier conditions.c
* Donne les nombres entre 0 et 1000 remplissant les conditions de l'exercice
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
* Commentaire : On pourrait mettre tous les éléments remplissants les conditions dans un tableau 
*               pour chaque conditions pour afficher seulement ces tableaux pour rendre le résultat du programme plus lisible.
*/


#include <stdio.h> // Importation de la bibliothèque nécessaire

int main(){ // Programme donnant les nombres entre 0 et 1000 remplissant les conditions de l'exercice

    // Variables
    int i=0;

    for(i=0;i<=1000;i++){ // Boucle FOR comptant de 0 à 1000
        if((i%2==0) && (i%15==0)){ // Condition 1 (divisible par 2 et par 15) 
            printf("%u est divisible par 2 et 15\n",i);
        }

        if ((i%103==0) || (i%107==0)){ // Condition 2 (divisible par 103 ou par 107)
            printf("%u est divisible par 103 ou 107\n",i);
        }

        if (((i%7==0) || (i%5==0)) && (i%3!=0)){ // Condition 3 (divisible par 7 ou par 5, mais pas par 3)
            printf("%u est divisible par 7 ou 5, mais pas par 3\n",i);
        }
    }
    return 0;
}