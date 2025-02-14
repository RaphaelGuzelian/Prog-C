/* Fichier opérateurs2.c
* Permet de réaliser des opérations voulues
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
* Commentaire : On pourrait rajouter d'autres opérateurs logiques comme &&,||,!
*/

#include <stdio.h> // Importation de la bibliothèque nécessaire

int main() {

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
        case '+': printf("%d\n", num1 + num2);break;
        case '-': printf("%d\n", num1 - num2);break;
        case '*': printf("%d\n", num1 * num2);break;
        case '/': printf("%d\n", num1 / num2);break;
        case '%': printf("%d\n", num1 % num2);break;
        case '&': printf("%u\n", num1 & num2);break;
        case '|': printf("%u\n", num1 | num2);break;
        case '~': printf("%u\n%u\n", ~num1, ~num2);break;
    }

    return 0;
}