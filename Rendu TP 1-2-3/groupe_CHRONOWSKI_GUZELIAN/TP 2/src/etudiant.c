/* Fichier etudiant.c
* Permet d'afficher les informations de 5 étudiants
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
* Commentaire : On pourrait choisir le nombre d'étudiants dont on veut afficher les informations
*/

#include <stdio.h> // Importation des bibliothèques nécessaires 

int main() {

    // Création des caractéristiques des 5 étudiants
    char nom[5][30]= {"Dupont","Dutrotoir","Delaroute","DeTrois","Deschamps"};
    char prenom[5][30] = {"Toto","Tata","Titi","Tutu","Tete"};
    char adresse[5][30] = {"1 Rue Oui", "2 Rue Non","3 Rue Peutetre","4 Rue Rue","5 Rue Leraclo"};
    int notes_C[5] = {15,16,17,18,19};
    int notes_OS[5] = {12,14,11,17,16};

    int i;
    for (i = 0; i < 5; i++) { // Boucle permettant l'affichage des informations des 5 étudiants 
        printf("Nom : %s // Prenom : %s // Adresse : %s // Note C : %d // Note OS : %d\n", nom[i], prenom[i], adresse[i], notes_C[i], notes_OS[i]);
    }
    return 0;
}