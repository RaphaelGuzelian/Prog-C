/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/* Fichier clients.c
* Permet de réaliser toutes les fonctions demandées au client dans l'exercice 4,5 et 6 (il suffit de changer la valeur de la variable 'mode' dans le main)
* - Envoie un message et affiche le message renvoyé par le serveur
* - Envoie un opération a faire et affiche le resultat
* - Ouverture et lecture de fichiers comtenant les notes d'eleves et envoie les calcules a faire au serveur puis affiche le resultat
* Auteurs : Amaury Chronowsky, Raphaël Guzélian 
*/

#include <string.h> // Importation de la bibliothèque nécessaire
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include "client.h" // Importation du prototype 'client.h'

/*
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */

int envoie_recois_message(int socketfd)
{
  char data[1024];

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Demandez à l'utilisateur d'entrer un message
  char message[1024];
  printf("Votre message (max 1000 caracteres): ");
  fgets(message, sizeof(message), stdin);
  strcpy(data, "message : ");
  strcat(data, message);

  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0)
  {
    perror("erreur lecture");
    return -1;
  }

  printf("Message recu: %s\n", data);

  return 0;
}

int envoie_operateur_numeros(int socketfd){
  
  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Demandez à l'utilisateur d'entrer un message
  char message[1024];
  printf("Votre calcule (sous forme : '(+,-,*,..)' 'nombre' 'nombre'...(max 1000 caracteres): ");
  fgets(message, sizeof(message), stdin);
  strcpy(data, "calcule : ");
  strcat(data, message);
  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0)
  {
    perror("erreur lecture");
    return -1;
  }

  printf("%s\n", data);

  return 0;
}

int envoie_operateur_numeros_etu(int socketfd){
  
  // Variables

  // Donne le nombre d'etudiants et de notes
  int nb_etu=5;
  int nb_note=5;

  // Variables ou on stocke les donnees
  float moy_tot=0;
  float list_moy_etu[nb_etu];
  int list_not_tot[nb_etu*nb_note];

  // Variable tempont
  char buff1[1024];
  char buff2[1024];
  float buff3=0;
  int count=0;
  int tot=0;

  // Initialisation des moyenne a 0 pour chaque utidiant nécessaire pour la suite des calcule
  for(int i=0;i<nb_etu;i++){
    list_moy_etu[i]=0;    
  }

  // Recuperation des valeurs dans les fichiers
  char *path="../etudiant";
  lire_dossier_recursif(path,list_not_tot,count);
  
  // Boucle FOR d'appel du serveur pour faire les claculs 
  for(int i=0;i<nb_etu;i++){
    tot=0;
    for(int j=0;j<nb_note;j++){ // Boucle FOR d'addition de toute les notes d'un eleve
      // Mise sous la forme "+ X Y"
      sprintf(buff1,"+ %d ",tot);
      sprintf(buff2,"%d",list_not_tot[i*nb_note+j]);
      strcat(buff1, buff2);
      // Envoie
      write(socketfd, buff1, strlen(buff1));
      memset(buff1, 0, sizeof(buff1));
      // Reception
      read(socketfd, buff1, sizeof(buff1));
      tot=atoi(buff1);
      memset(buff1, 0, sizeof(buff1));
      memset(buff2, 0, sizeof(buff2));  
    }
    // Permet de calculer la moyenne avec la somme des notes et le nombre de notes sous la forme "/ sommenote nb_note"
    sprintf(buff1,"/ %d ",tot);
    sprintf(buff2,"%d",nb_note);
    strcat(buff1, buff2);
    // Envoie
    write(socketfd, buff1, strlen(buff1));
    memset(buff1, 0, sizeof(buff1));
    // Reception
    read(socketfd, buff1, sizeof(buff1));
    // On enregistre la moyenne de l'eleve
    list_moy_etu[i]=atof(buff1);
    memset(buff1, 0, sizeof(buff1));
    memset(buff2, 0, sizeof(buff2));  

    // Cacul de la moyene de la classe la methode est la suivante : 
    // on calcule d'abors la division de la moyenne d'un eleve par le nombre d'eleve et on additionne l'ensemble pour chaque eleve 

    // Ici c'est la division
    // On met sous la forme "/ moy_etu nb_etu" 
    sprintf(buff1,"/ %f ",list_moy_etu[i]);
    sprintf(buff2,"%d",nb_etu);
    strcat(buff1, buff2);
    // Envoie
    write(socketfd, buff1, strlen(buff1));
    memset(buff1, 0, sizeof(buff1));
    memset(buff2, 0, sizeof(buff2));
    // Reception 
    read(socketfd, buff1, sizeof(buff1));
    buff3=atof(buff1);

    memset(buff1, 0, sizeof(buff1));
    memset(buff2, 0, sizeof(buff2)); 

    // Ici on fait l'addition des valeurs caculees
    // On met sous la forme "+ 'somme des resulat precedent' 'resultat actuel'"
    sprintf(buff1,"+ %f ",buff3);
    sprintf(buff2,"%f",moy_tot);
    strcat(buff1, buff2);
    printf("%s\n",buff1);
    // Envoie
    write(socketfd, buff1, strlen(buff1));
    memset(buff1, 0, sizeof(buff1));
    // Reception
    read(socketfd, buff1, sizeof(buff1));
    moy_tot=atof(buff1);
    memset(buff1, 0, sizeof(buff1));
    memset(buff2, 0, sizeof(buff2));   
  }
  
  // Envoie de la mise en arret du serveur
  strcpy(buff1,"non");
  write(socketfd, buff1, strlen(buff1));

  // Affichage des resultats
  for(int i;i<nb_etu;i++){
    printf("L'etudiant(e) n°%d à %f de moyenne.\n",i+1,list_moy_etu[i]);
  }
  printf("La moyenne de la classe est %f\n",moy_tot);
  
  return 0;
}

void lire_dossier_recursif(char *directory, int *list_note,int count) {// Fonction de lecture recursive de fichiers
  struct dirent *dir;
  DIR *dirp = opendir(directory); //Ouverture du dossier
  if (dirp == NULL) { //Si il n'y a rien dedans
    perror("opendir"); //No such file or directory
  }  
  while ((dir = readdir(dirp)) != NULL) { //Tant qu'il y a des fichiers, on les lit les noms
    if ((strcmp(".", dir->d_name)) && (strcmp("..", dir->d_name))) { // Si c'est un dossier et pas les dossiers . et ..
      // On cree la bonne arboraissance pour obtenir le ficher/dossier trouve
      char* subdirectory = malloc(sizeof(char) * (strlen(directory)+2+strlen(dir->d_name)));
      strcpy(subdirectory,directory);
      strcat(subdirectory,"/");
      strcat(subdirectory,dir->d_name);
      if (dir->d_type == DT_DIR) {// On regarde si c'est un dossier ou un fichier
        lire_dossier_recursif(subdirectory, list_note, count);
        count = count+5;     
      }
      else {
        // Lance la lecture du fichier
        lire_fichier(subdirectory, count, list_note);
        count++;

      }            
      free(subdirectory);
    }
  }
  closedir(dirp); //Fermeture du dossier. On quitte cette boucle pour proceder au fichier suviant ou finir quand tout les fichier on ete traité.
}

void lire_fichier(char *nom_fichier, int ind, int *list_note){// Fonction qui lit les fichiers
	//Variables
  char cont[10];
 	int file;
  int note;
  // Sauvegarde de la valeur du fichier dans le tableau de notes
	file = open (nom_fichier, O_RDONLY);
	read(file, cont, 2);
	note = atoi(cont);
	close(file);
  list_note[ind] = note;
}

int main()
{
  int mode = 3; // 1 = mode transmission de message, 2 = calcule, 3 = calcule de moyennes via fichiers

  int socketfd;
  struct sockaddr_in server_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status < 0)
  {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }

  // Appeler la fonction pour envoyer un message au serveur
  if (mode==1){// Lire et répondre au client
    envoie_recois_message(socketfd);
  }
  if (mode==2){// Effectue des calcules simple
    envoie_operateur_numeros(socketfd);
  }
  if (mode==3){// Calcule de moyennes
    envoie_operateur_numeros_etu(socketfd);
  }
  close(socketfd);
}
