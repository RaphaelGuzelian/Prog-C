/* Fichier chaine.c
* Compte le nombre d'éléments dans une chaine de caractère, concatène 2 chaines de caractères et copie une chaine de caractère dans une autre chaine de caractère
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
* Commentaire : On pourrait rendre la taille des char variables
*/


#include <stdio.h> // Importation des bibliothèques nécessaires 

int nbr_carac(char *mots) { // Fonction qui compte le nombre d'élément dans la chaine
    // Variables
    int nbr_lettre = 0;
    int i;

    // Conditions
    for (i = 0; mots[i] != '\0'; ++i) {
        nbr_lettre++;
    }

    return nbr_lettre; // Retourne le nombre de caractere 
}

int cat_car(char *mots1, char *mots2, char *concat) { // Fonction qui concatène 2 chaines de caracteres directement dans une variable du programme principal

    // Variables
    int taille1=nbr_carac(mots1);
    int taille2=nbr_carac(mots2);
    
    // Boucles FOR qui ecrient lettre par lettre les deux chaines l'une apres l'autres
    for(int i=0; i<taille1; ++i){
        concat[i]=mots1[i];// *(concat+i) = *(mots+i) a la meme utilité que la ligne
    }
    for(int i=0; i<taille2; ++i){
        concat[i+taille1]=mots2[i];
    }
    return 0;
}

int cop_char(char *copy,char *past){ // Fonction qui copie une chaine de caractere dans une autre

    //Variable
    int taille =nbr_carac(copy);

    // Boucles FOR qui copie une chaine de caractere dans une autre
    for(int i=0;i<taille;i++) { 
        past[i]=copy[i];
    }
    return 0;
}


int main() { // Programme principale

    // Variables
    char mot1[50];    
    char mot2[50];
    char concat[100];

    // Saisie des differents mots
    printf("Entrer un mot : "); //choix du mot
    scanf("%s",mot1);
    printf("Entrer un autre mot : "); //choix du mot
    scanf("%s",mot2);

    //  Donne la longueur des deux mots
    printf("Votre premier mot contient %d caracteres\n",nbr_carac(mot1));
    printf("Votre deuxieme mot contient %d caracteres\n",nbr_carac(mot2));
    
    // Concatene deux chaines
    cat_car(mot1,mot2,concat);
    printf("Vos deux mots concatenés : %s\n",concat);

    // Copie une chaine dans une autre
    cop_char(mot1,mot2);
    printf("Votre mot copié dans un autre : %s\n",mot2);
    return 0;
    }
