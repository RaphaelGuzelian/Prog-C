/* Fichier bits.c
* Vérifie si les bit n°4 et n°20 sont à 1
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
* Commentaire : On pourrait rendre le programme flexible en faisant une fonction qui crée les maskes en fonction des bits choisis 
*/


#include <stdio.h> // Importation des bibliothèques nécessaires 

int main() { // Affiche 1 si les bits n°4 et n°20 sont à 1 ou 0

    // Variables
    int d = 0;
    int mask1 = 8;
    int mask2 = 524288;

    // Saisie de la valeur testée
    printf("Entrer un nombre à comparer :\n");
    scanf("%d", &d);

    // Conditions
    if ((d & mask1) && (d & mask2)){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
    return 0;
}
