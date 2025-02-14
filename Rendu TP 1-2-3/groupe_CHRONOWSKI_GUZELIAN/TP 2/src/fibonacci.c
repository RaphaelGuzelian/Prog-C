/* Fichier fibonacci.c
* Permet de calculer la suite de Fibonacci avec le nombre de termes voulu
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/

#include <stdio.h> // Importation des bibliothèques nécessaires 

int fibonacci(int n) {
    /*Fonction permettant de calculer le résultat d'un termes de la suite de Fibonnaci par récurrence
    Entrées : numéro du terme
    Sortie : valeur du terme n
    */
    if (n == 0) { // U0 = 0
        return 0;
    } else if (n == 1) { // U1 = 1
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2); // Calcul de 'Un=Un-1 + Un-2'
    }
}

int main() {
    int nbr_termes;
    printf("Entrer le nombre de termes :"); // Choix du nombre de termes
    scanf("%d", &nbr_termes);

    int i;
    for (i = 0; i < nbr_termes; i++) { // Boucle affichant 'Un' en appellant fibonacci()
        printf("U%d = %d\n",i,fibonacci(i));

    }
    
    return 0;
}