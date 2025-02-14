/* Fichier etudiant2.c
* Permet d'afficher les informations de 5 étudiants grâce aux structures
* Auteurs : CHRONOWSKI Amaury et GUZELIAN Raphaël
* Commentaire : On pourrait rendre le programme plus propre en créant les étudiants par des boucles 
*/


#include <stdio.h> // Importation des bibliothèques nécessaires 
#include <string.h>

int main() {

    struct etudiant { // Création de la structure 'etudiant' contenant les informations des étudiants
    char prenom[30];
    char nom[30];
    char adresse[30];
    short notes_C;
    short notes_OS;
    };

    struct etudiant etudiant_cpe[5]; // Déclaration de la structure 'etudiant_cpe'

    // Création des étudiants
    strcpy(etudiant_cpe[0].nom,"Dupont");
    strcpy(etudiant_cpe[0].prenom,"Toto");
    strcpy(etudiant_cpe[0].adresse,"1 Rue Oui");
    etudiant_cpe[0].notes_C = 15;
    etudiant_cpe[0].notes_OS = 12;

    strcpy(etudiant_cpe[1].nom,"Dutrotoir");
    strcpy(etudiant_cpe[1].prenom,"Tata");
    strcpy(etudiant_cpe[1].adresse,"2 Rue Non");
    etudiant_cpe[1].notes_C = 16;
    etudiant_cpe[1].notes_OS = 14;

    strcpy(etudiant_cpe[2].nom,"Delaroute");
    strcpy(etudiant_cpe[2].prenom,"Titi");
    strcpy(etudiant_cpe[2].adresse,"3 Rue Peutetre");
    etudiant_cpe[2].notes_C = 17;
    etudiant_cpe[2].notes_OS = 18;

    strcpy(etudiant_cpe[3].nom,"DeTrois");
    strcpy(etudiant_cpe[3].prenom,"Tutu");
    strcpy(etudiant_cpe[3].adresse,"4 Rue Rue");
    etudiant_cpe[3].notes_C = 18;
    etudiant_cpe[3].notes_OS = 17;

    strcpy(etudiant_cpe[4].nom,"Deschamps");
    strcpy(etudiant_cpe[4].prenom,"Tete");
    strcpy(etudiant_cpe[4].adresse,"5 Rue Leraclo");
    etudiant_cpe[4].notes_C = 19;
    etudiant_cpe[4].notes_OS = 16;


    int i;
    for (i = 0; i < 5; i++) { // Affichage des informations des étudiants
        printf("Nom : %s\n",etudiant_cpe[i].nom);
        printf("Prenom : %s\n",etudiant_cpe[i].prenom);
        printf("Adresse : %s\n",etudiant_cpe[i].adresse);
        printf("Note C : %i\n",etudiant_cpe[i].notes_C);
        printf("Note OS : %i\n",etudiant_cpe[i].notes_OS);
    }

    return 0;
}





