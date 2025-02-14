/* Fichier couleur_compteur.c
* Permet d'afficher le nombre de couleurs diffrentes parmis 100 couleurs aléatoires
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/

#include <stdio.h> // Importation des bibliothèques nécessaires 
#include <stdlib.h>
#include <time.h>


int main() {

    // Variables

    int taille=100; // Nombre de couleurs demandées
    int compt=0; // Compte le nombre de couleurs différentes

    struct couleur { // Création de la structure 'couleur' contenant les couleurs
        unsigned int rouge;
        unsigned int vert;
        unsigned int bleu;
        unsigned int alpha;
    };
    
    struct couleur tableau_couleur[taille]; // Déclaration de la structure 'tableau_couleur' 
    struct couleur tableau_couleur_uni[taille]; // Déclaration de la structure 'tableau_couleur_uni'

    srand(time(NULL)); // Initialisation du générateur

    for (int i = 0; i < taille; i++) { // On attribue une valeur random entre 0 et 255 aux couleurs
        tableau_couleur[i].rouge = rand() % 255;
        tableau_couleur[i].vert = rand() % 255;
        tableau_couleur[i].bleu = rand() % 255;
        tableau_couleur[i].alpha = rand() % 255;
    }

    // On fixe 2 couleurs de la même facon pour s'assurer que le programme fonctionne
    tableau_couleur[1].rouge = 100;
    tableau_couleur[1].vert = 100;
    tableau_couleur[1].bleu = 100;
    tableau_couleur[1].alpha = 100;

    tableau_couleur[2].rouge = 100;
    tableau_couleur[2].vert = 100;
    tableau_couleur[2].bleu = 100;
    tableau_couleur[2].alpha = 100; 

    for (int i = 0; i < taille; i++) { // Boucle FOR qui parcourt toute les couleurs
        int Verif=0;
        for (int j = 0; j < compt; j++) { // Boucle FOR qui parcourt toutes les couleurs en la comparant avec une couleur du tableau
            if ((tableau_couleur[i].rouge==tableau_couleur_uni[j].rouge) && (tableau_couleur[i].vert==tableau_couleur_uni[j].vert) && (tableau_couleur[i].bleu==tableau_couleur_uni[j].bleu) && (tableau_couleur[i].alpha==tableau_couleur_uni[j].alpha)){
                Verif=1;
                break;
                }
        }
        if (Verif==0){ // Met la couleur unique dans le tableau des couleurs uniques
            tableau_couleur_uni[compt].rouge = tableau_couleur[i].rouge;
            tableau_couleur_uni[compt].vert = tableau_couleur[i].vert;
            tableau_couleur_uni[compt].bleu = tableau_couleur[i].bleu;
            tableau_couleur_uni[compt].alpha = tableau_couleur[i].alpha;
            compt++;
        }                           
    }

    for (int i = 0; i < compt; i++) { // Affichage des valeurs des composants des couleurs unique
        printf("Couleur %d : rouge = 0x%x, vert = 0x%x, bleu = 0x%x, alpha = 0x%x\n",i+1, tableau_couleur_uni[i].rouge, tableau_couleur_uni[i].vert, tableau_couleur_uni[i].bleu, tableau_couleur_uni[i].alpha);
    }

    return 0;
}