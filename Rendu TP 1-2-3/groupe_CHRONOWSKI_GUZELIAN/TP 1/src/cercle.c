/* Fichier cercle.c
* Permet d'afficher l'aire et le périmètre d'un cercle de rayon voulu
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/

#include <stdio.h> // Importation des bibliothèques nécessaires
#include <math.h> // Bibliothèque permettant l'utilisation de pi avec M_PI

int main() {

    int rayon;
    printf("Entrer le rayon :"); // Choix du rayon par l'utilisateur
    scanf("%d", &rayon);

    float aire = M_PI * rayon * rayon; // Calcul de l'aire 
    float perimetre = 2 * M_PI * rayon; // Calcul du périmètre

    printf("L'aire du cercle est : %f\n", aire); // Affichage de l'aire
    printf("Le perimetre du cercle est : %f\n", perimetre); // Affichage du périmètre

    return 0;

}