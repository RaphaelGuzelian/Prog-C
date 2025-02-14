/* Fichier puissance.c
* Permet de calculer a à la puissance b
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
* Commentaire : On pourrait faire en sorte que le programme permette de calculer des puissances négatives
*/

#include <stdio.h> // Importation des bibliothèques nécessaires

int puissance(int a, int b) {
    /*Fonction permettant de calculer a puissance b
    Entrées : a et b
    Sortie : a à la puissance b
    */
    int resultat = a;
    if (b == 0) { // Si b vaut 0, le resultat est automatiquement 1
        resultat = 1;
    } else {
        int i;
        for (i = 1; i < b; i++) { // On multiplie 'resultat' qui contient a, par a, le tout b fois
            resultat *= a;
        }
    }

    return resultat;
}

int main() {
    int a,b;

    printf("Entrer a :"); // Choix du paramètre a
    scanf("%d", &a);

    printf("Entrer b :"); // Choix du paramètre b
    scanf("%d", &b);

    printf("Le resultat de %d a la puissance %d est : %d\n",a,b,puissance(a,b)); // Affichage du résultat

    return 0;

}