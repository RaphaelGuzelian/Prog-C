/* Fichier factorielle.c
* Permet de calculer le factorielle d'un entier positif en récursif
* Auteurs : Amaury Chronowsky, Raphaël Guzélian 
*/

#include <stdio.h> // Importation de la bibliothèque nécessaire

int multi(int val,int res){// Fonction recursive qui fait le calcule de la factorielle
    if(val==0){// Cas d'arrêt de la récursion
        return res;
    }
    else{
        res=val*res;
        val=val-1;
        multi(val,res);
    }
}

int main(){// Programme principal
    
    // Variables
    int val;
    int res=1;

    // Saisie de la valeur
    printf("Entrer la valeur dont on veut calculer la factorielle : ");
    scanf("%d", &val);

    // Affichage de resultat
    printf("Le resultat de %d! est %d.\n",val,multi(val,res));
}