/* Fichier etudiant_bd.c
* Permet de sauvegarder le nom, le prénom, l'adresse et la note de C et OS d'un élève dans un fichier 'etudiant.txt'
* Auteurs : Amaury Chronowsky, Raphaël Guzélian 
*/

#include <stdio.h> // Importation de la bibliothèque nécessaire
#include <string.h>
#include "fichier.h" // Importation du prototype 'fichier.c'

int main(){

    struct etudiant { // Création de la structure 'etudiant' contenant les informations des étudiants
        char nom[30];
        char prenom[30];
        char adresse[100];
        short notes_C;
        short notes_OS;
    };

    int nbetu;
    

    printf("Combien d'eleve voulez-vous entrer : ");// On choisie le nombre d'élève que l'on veut entrer
    scanf("%d", &nbetu);
    char c=getchar();
    struct etudiant etudiant_cpe[nbetu];


    for (int i=0;i<nbetu;i++){// On saisie les informations pour chaque étudiants
        char buffer[30];


        // Saisie des valeurs
        printf("Entrer le nom de famille l'etudiant(e) : ");
        scanf("%s",etudiant_cpe[i].nom);
        c=getchar();
        ecrire_dans_fichier("etudiant.txt",etudiant_cpe[i].nom);
        ecrire_dans_fichier("etudiant.txt",", ");

        printf("Entrer le prenom de l'etudiant(e) : ");
        scanf("%s",etudiant_cpe[i].prenom);
        c=getchar();
        ecrire_dans_fichier("etudiant.txt",etudiant_cpe[i].prenom);
        ecrire_dans_fichier("etudiant.txt",", ");

        printf("Entrer l'adresse de l'etudiant(e): ");
        fgets(etudiant_cpe[i].adresse, 100 , stdin);// On utilise fgets pour permettre de prendre en compte les ' '
        int a=strlen(etudiant_cpe[i].adresse);
        etudiant_cpe[i].adresse[a-1]='\0';// On fait ça pour enlever le retour à la ligne dû à la fonction fgets 
        ecrire_dans_fichier("etudiant.txt",etudiant_cpe[i].adresse);  
        ecrire_dans_fichier("etudiant.txt",", ");

        printf("Entrer la notes de OS de l'etudiant(e) (entre 0 et 20) : ");
        scanf("%hi",&etudiant_cpe[i].notes_OS);
        sprintf(buffer,"%i",etudiant_cpe[i].notes_OS);// Permet de changer le type d'une variable
        ecrire_dans_fichier("etudiant.txt",buffer);
        ecrire_dans_fichier("etudiant.txt",", ");

        printf("Entrer la notes de C de l'etudiant(e) (entre 0 et 20) : ");
        scanf("%hi",&etudiant_cpe[i].notes_C);
        sprintf(buffer,"%i",etudiant_cpe[i].notes_C);// Permet de changer le type d'une variable
        ecrire_dans_fichier("etudiant.txt",buffer);
        ecrire_dans_fichier("etudiant.txt","\n");
    
    }
    return 0;
}