/* Fichier main.c
* Permet de lancer des programmes 
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/

#include <stdio.h> // Importation de la bibliothèque nécessaire
#include <stdlib.h>
#include <time.h>
#include "operator.h" // Importation du prototype 'operator.h'
#include "fichier.h" // Importation du prototype 'fichier.h'
#include "liste.h" // Importation du prototype 'liste.h'

int main() {

    //=====Exercice 4.1=====
    char op;
    printf("Entrer l'operande (+,-,*,/,%%,&,|,~) :"); // Choix de l'opérande
    scanf("%c", &op);

    int num1;
    printf("Entrer num1 :"); // Choix de la variable 1 
    scanf("%d", &num1);

    int num2;
    printf("Entrer num2 :"); // Choix de la variable 2
    scanf("%d", &num2);

    switch (op) { // Switch case pour réaliser uniquement l'opération voulue
        case '+': printf("%d\n", somme(num1,num2));break;
        case '-': printf("%d\n", difference(num1,num2));break;
        case '*': printf("%d\n", produit(num1,num2));break;
        case '/': printf("%d\n", quotient(num1,num2));break;
        case '%': printf("%d\n", modulo(num1,num2));break;
        case '&': printf("%u\n", et (num1,num2));break;
        case '|': printf("%u\n", ou(num1,num2));break;
        case '~': printf("%u\n", negation(num1));break;
    }

    //=====Exercice 4.2=====
    ecrire_dans_fichier("fichier.txt","Ceci est un message\n");
    lire_fichier("fichier.txt");
   
    //=====EXercice 4.7=====
    int nb_couleur=10;
    struct couleur tableau_couleurs[nb_couleur];

    srand(time(NULL)); // Initialisation du générateur

    for (int i = 0; i < nb_couleur; i++) { // On attribue une valeur random entre 0 et 255 aux couleurs
        tableau_couleurs[i].rouge = rand() % 255;
        tableau_couleurs[i].vert = rand() % 255;
        tableau_couleurs[i].bleu = rand() % 255;
        tableau_couleurs[i].alpha = rand() % 255;
    }

    struct liste_couleurs liste; // Initialisation de la liste de couleur
    liste.premier.suivant = &liste.dernier;
    liste.dernier.precedent = &liste.premier;
    liste.premier.precedent = NULL;
    liste.dernier.suivant = NULL;

    parcours(&liste); // On verifie si la liste est bien vide

    for (int i = 0; i < nb_couleur; i++) { // On implémente les couleurs dans la liste
        insertion(&tableau_couleurs[i],&liste);
    };

    parcours(&liste); // On affiche la liste

    return 0;
}