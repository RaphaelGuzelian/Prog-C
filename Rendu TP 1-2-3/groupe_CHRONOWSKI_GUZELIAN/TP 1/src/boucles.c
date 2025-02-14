/* Fichier boucles.c
* Créer un triangle rectangle dans la fenêtre de commande via des "*" et "#"
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
* Commentaire : On pourrait mettre un SWITCH CASE pour choisir quel type de boucle on utilise 
*/


#include <stdio.h> // Importation de la bibliothèque nécessaire

int main(){ // Programme créeant un triangle rectangle dans la fenêtre de commande via des "*" et "#"

    // Variables
    int taille=0;
    int i=1;
    int j=1;

    while (taille<4){ // Boucle de saisie protégée pour avoir un triangle plus grand que 4 lignes
        printf("Entrer la taille du triangle (>4) :\n");
        scanf("%d", &taille);   
    }

    // Programme via une boucle FOR
    printf("Boucle FOR :\n");

    for(i=1;i<=taille;i++){ // Boucle FOR traitant ligne par ligne l'affichage

        if(i==1){ // Cas de la première ligne; Affichage du sommet
                printf("\n*\n");
            }

        else if((i>1)&&(i<taille)){ // Cas de la deuxième ligne à la N-1 ligne
            printf("* "); // Affichage d'un bord

            int f=2; // On initie la suite de ligne au deuxième caractère car on affiche directement l'étoile qui fait le bord

            for(f=2;f<=i-1;f++){ // Affiche tout les caractères entre les bords
                printf("# ");;
            }
            printf("*\n"); // Affichage d'un bord
        }

        else if(i==taille){ // Cas de la dernière ligne
            int f=1; // On initie le premier caractère à 1 car la derniere ligne n'est que bord et donc on utilise seulement "*" 

            for(f=1;f<=i;f++){ // Affiche tous les éléments composants le bord
                printf("* ");
            }
            printf("\n"); // On permet un affichage plus jolie
    }

    // Programme via une boucle WHILE
    printf("Boucle WHILE :\n");

    while(j<=taille){// Boucle WHILE traitant ligne par ligne l'affichage

        if(j==1){// Cas de la première ligne; Affichage du sommet
                printf("\n*\n");
            }

        else if((j>1)&&(j<taille)){// Cas de la deuxième ligne à la N-1 ligne
            printf("* ");// Affichage d'un bord

            int f=2; // On initie la suite de ligne au deuxième caractère car on affiche directement l'étoile qui fait le bord

            for(f=2;f<=j-1;f++){ // Affiche tout les caractères entre les bords
                printf("# ");
            }
            printf("*\n");// Affichage d'un bord
        }

        else if(j==taille){ // Cas de la dernière ligne
            int f=1; // On initie le premier caractère à 1 car la derniere ligne n'est que bord et donc on utilise seulement "*" 

            for(f=1;f<=j-1;f++){ // Affiche tous les éléments composants le bord
                printf("* ");
            }
            printf("*\n"); // On permet un affichage plus jolie
        }
        j++; // Incrémentation de la variable permtant le cas d'arrêt 
    }
    return 0;
    }
}