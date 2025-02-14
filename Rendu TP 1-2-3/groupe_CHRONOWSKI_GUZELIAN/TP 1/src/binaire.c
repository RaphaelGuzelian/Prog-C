/* Fichier binaire.c
* Transforme un entier positif en nombre binaire
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
* Commentaire : A noter que le programme est codé pour fonction avec des nombres codés sur 64 bits ou moins. 
*               Pour le transformer en programme traitant les nombres codés sur plus de bits, 
*               il suffit de modifier la taille du tableau dans les variables.
*               On peut faire en sorte d'améliorer le programme pour qu'il prenne en compte les entiers négatifs
*               et que le programme code la négativité de l'entier comme le compilateur le comprend. 
*               On peut aussi mettre une saisie protégée.
*/


#include <stdio.h> // Importation de la bibliothèque nécessaire

int main(){ // Programme transformant un entier positif en nombre binaire

    // Variables
    int nb=0;
    int i=-1;
    int j=0;
    int bininv[64]; // Tableau contenant tous les bits du nombre dans le sens inverse dû à la methode de calcule

    // Saisie du nombre voulu
    printf("Entrer un nombre à transformer en binaire :\n");
    scanf("%d", &nb);

    if(nb!=0){ // Condition permettant de gérer le cas 0

        while(nb>=1){ // Boucle permettant de trouver les valeurs binaires
            i++;
            bininv[i]=nb%2;
            nb=nb/2;
        }
        
        for(j=0;j<=i;j++){ // Affichage du nombre en binaire dans le bon sens
            printf("%u",bininv[i-j]);
        }
        printf("\n");
    }
    else{ // Cas 0
        printf("0\n");
    }

return 0;
}