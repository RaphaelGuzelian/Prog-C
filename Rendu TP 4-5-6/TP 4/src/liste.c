/* Fichier liste.c
* Permet d'inserer des couleurs dans une liste et de parcourir la liste 
* Auteurs : Amaury Chronowsky, Raphaël Guzélian 
*/

#include "liste.h" // Importation de la bibliothèque nécessaire
#include <stdio.h> 

void insertion (struct couleur *couleur, struct liste_couleurs *liste){ // Programme qui insert les couleurs
    couleur->suivant = liste->premier.suivant; 
    couleur->precedent = &liste->premier;
    liste->premier.suivant->precedent = couleur;
    liste->premier.suivant = couleur; 
};


void parcours (struct liste_couleurs *liste){ // Programme qui affiche les couleurs
    struct couleur *coul = liste->premier.suivant;
    int i=1;
    while(coul != &liste->dernier) { // Boucle WHILE qui affiche toutes les couleurs
        printf("Couleur n°%d, ",i);
        printf("rouge : %d, ", coul->rouge);
        printf("vert : %d, ", coul->vert);
        printf("bleu : %d, ", coul->bleu);
        printf("nuance : %d\n", coul->alpha);
        coul = coul->suivant;
        i++;
    }
};






