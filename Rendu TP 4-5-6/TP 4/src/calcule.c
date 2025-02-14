/* Fichier calcule.c
* Permet de réaliser des opérations voulues en utilisant une ligne de commande
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
*/


#include <stdio.h> // Importation des bibliothèques nécessaires
#include <stdlib.h>
#include "operator.h" // Importation du prototype 'operator.h'


int main(int argc, char** argv) {

    char op = argv[1][0];
    int num1 = atoi(argv[2]), num2 = atoi(argv[3]);


    switch (op) { // Switch case pour réaliser uniquement l'opération voulue
        case '+': printf("%d\n", somme(num1,num2));break;
        case '-': printf("%d\n", difference(num1,num2));break;
        case '*': printf("%d\n", produit(num1,num2));break;
        case '/': printf("%d\n", quotient(num1,num2));break;
        case '%': printf("%d\n", modulo(num1,num2));break;
        case '&': printf("%u\n", et(num1,num2));break;
        case '|': printf("%u\n", ou(num1,num2));break;
        case '~': printf("%u\n", negation(num1));break;
    }

    return 0;
}

