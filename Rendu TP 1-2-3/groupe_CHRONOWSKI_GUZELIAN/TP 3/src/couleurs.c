/* Fichier couleurs.c
* Permet d'afficher les valeurs en hexadécimal des composants R,G,B,A de 10 couleurs 
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/


#include <stdio.h> // Importation des bibliothèques nécessaires 
#include <stdlib.h>
#include <time.h>


int main() {
    struct couleur { // Création de la structure 'couleur' contenant les couleurs
        unsigned int rouge;
        unsigned int vert;
        unsigned int bleu;
        unsigned int alpha;
    };

    struct couleur tableau_couleur[10]; // Déclaration de la structure 'tableau_couleur' 

    srand(time(NULL)); // Initialisation du générateur

    for (int i = 0; i < 10; i++) { // On attribue une valeur random entre 0 et 255 aux couleurs
        tableau_couleur[i].rouge = rand() % 255;
        tableau_couleur[i].vert = rand() % 255;
        tableau_couleur[i].bleu = rand() % 255;
        tableau_couleur[i].alpha = rand() % 255;
    }

    for (int i = 0; i < 10; i++) { // Affichage des valeurs des composants des 10 couleurs en hexadécimal
        printf("Couleur %d : rouge = 0x%x, vert = 0x%x, bleu = 0x%x, alpha = 0x%x\n",i+1, tableau_couleur[i].rouge, tableau_couleur[i].vert, tableau_couleur[i].bleu, tableau_couleur[i].alpha);
    }

    return 0;
}