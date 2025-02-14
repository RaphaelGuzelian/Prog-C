/* Fichier chercher.c
* Partie 1 : Permet de chercher si un entier est dans le tableau ou non
* Partie 2 : Permet de chercher si une phrase est dans le tableau ou non
* Commentaire : On peut faire en sorte de chercher plusieurs entiers ou phrases dans les tableaux
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
* /!\ Partie 2 réalisée avec le groupe de COURBIN Michel et MICHELI Sébastien
*/


#include <stdio.h> // Importation des bibliothèques nécessaires
#include <stdlib.h>
#include <time.h>


void recherche_entier(int *tableau, int nbr_cherche) { 
    /*Fonction permettant de chercher si l'entier est présent
    Entrée : tableau et nombre cherché
    Sortie : affichage de la présence du nombre cherché
    */
    int compteur = 0;
     for (int i = 0; i < 100; i++) { 
         if(tableau[i] == nbr_cherche) {
            compteur ++;
         }
     }
     if (compteur >= 1) {
        printf("entier présent\n");
     } else {
        printf("entier non présent\n");
     }
}

int main() {

    //==========Partie 1, recherche d'un entier==========
    srand(time(NULL)); // Initialisation du générateur

    int tableau[100];
    for (int i = 0; i < 100; i++) { // On remplie le tableau de valeur random entre 0 et 100
        tableau[i] = rand() % 101;
        printf("%d\n",tableau[i]);
    }

    int nbr_cherche;
    printf("Entrer le nombre à chercher :"); // Choix du nombre a chercher par l'utilisateur
    scanf("%d", &nbr_cherche);

    recherche_entier(tableau,nbr_cherche); // On appelle la fonction 'recherche'






    //==========Partie 2 recherche de phrase, réalisée avec le groupe de COURBIN Michel et MICHELI Sébastien==========
    char phrases[10][150] = {"Bonjour oui","Bonjour non",
                            "Bonsoir oui","Bonsoir non",
                            "La pomme", "La voiture",
                            "Le chat", "Le chien",
                            "La voiture", "La voiture noire"};

    char phrase_cherche[] = "La voiture noire"; 
    int j=0;

    for (int i = 0; i<10; i++) { // On parcourt le tableau de phrases
        j=0;

        while (phrases[i][j]== phrase_cherche[j]) { // Tant que les lettres de la phrase parcourue et celles de la phrase cherchée correspondent
            if (phrases[i][j]=='\0') { // Si on arrive à l'élément NULL, c'est qu'on est à la fin et que notre phrase correspond
                printf("Phrase trouvée\n");
                return 0;
            } else { // Sinon, on continue de parcourir les autres phrases
                j++;
            }
        }
        
    }
    printf("Phrase non trouvée\n");
    return 0;
}

