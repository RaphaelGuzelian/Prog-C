/* Fichier opérateurs.c
* Affiche les résultats des opérations arithmétiques et logiques (et relationnels)
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
* Commentaire : On pourrait mettre un SWITCH CASE pour les opérations logiques pour éviter d'avoir des conflits avec les divisions par 0
*/


#include <stdio.h> // Importation de la bibliothèque nécessaire

int main(){ // Programme affichant les résultats des opération arithmetique et logique (et relationnel)
    
    // Variables
    int a=16;
    int b=3;

    // Opérations Arithmetiques 
    float mul=a*b;
    float add=a+b;
    float sub1=a-b;
    float sub2=b-a;
    float div1=a/b;
    float div2=b/a;
    float mod1=a%b;
    float mod2=b%a;

    // Opérations relationnels
    int sup1=a>b;
    int sup2=b>a;
    int supeg1=a>=b;
    int supeg2=b>=a;
    int inf1=a<b;
    int inf2=b<a;
    int infeg1=a<=b;
    int infeg2=b<=a;
    int eg=a==b;
    int dif=a!=b;

    // Opérations logiques
    int neg1=!a;
    int neg2=!b;
    int and=a&&b;
    int or=a||b;

    // Affichage des opérations Arithmetiques 
    printf("Multiplication de a et b : %f \n",mul);
    printf("Addition de a et b : %f \n",add);
    printf("Soustraction de a par b : %f \n",sub1);
    printf("Soustraction de b par a : %f \n",sub2);
    printf("Division de a par b : %f \n",div1);
    printf("Division de b par a : %f \n",div2);
    printf("Modulus de a par b : %f \n",mod1);
    printf("Modulus de b par a : %f \n",mod2);

    // Affichage des opérations relationnels
    printf("a est superieur à b : %u \n",sup1);
    printf("b est superieur à a : %u \n",sup2);
    printf("a est superieur ou égale à b : %u \n",supeg1);
    printf("b est superieur ou égale à a : %u \n",supeg2);
    printf("a est inferieur à b : %u \n",inf1);
    printf("b est inferieur à a : %u \n",inf2);
    printf("a est inferieur ou égale à b : %u \n",infeg1);
    printf("b est inferieur ou égale à a : %u \n",infeg2);
    printf("a est égale à b : %u \n",eg);
    printf("a est different de b %u \n",dif);

    // Affichage des opérations logiques
    printf("Négation de a : %u \n",neg1);
    printf("Négation de b : %u \n",neg2);
    printf("a et b : %u \n",and);
    printf("a ou b %u \n",or);
    
    return 0;
}