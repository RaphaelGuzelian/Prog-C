/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/* Fichier serveur.c
* Permet de réaliser toutes les fonctions demandées au serveur dans l'exercice 4,5 et 6 (il suffit de changer la valeur de la variable 'mode' dans le main)
* - Afficher le message recu du client et renvoie un message au client
* - Effectue les operations matematiques entre 2 variables envoyées par clent puis renvoie le resultat au client
* - Pour la derniere fonction on reutilise la deuxieme fonction pour faire des additions et des divisions pour calculer des moyennes 
* Auteurs : Amaury Chronowsky, Raphaël Guzélian 
*/

#include <sys/types.h> // Importation de la bibliothèque nécessaire
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "serveur.h" // Importation du prototype 'serveur.h'

/* renvoyer un message (*data) au client (client_socket_fd)
 */
int renvoie_message(int client_socket_fd, char *data)
{
  int data_size = write(client_socket_fd, (void *)data, strlen(data));

  if (data_size < 0)
  {
    perror("erreur ecriture");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int recois_envoie_message(int socketfd,int client_socket_fd)
{
  // la réinitialisation de l'ensemble des données
  char data[1024];
  memset(data, 0, sizeof(data));

  // lecture de données envoyées par un client
  int data_size = read(client_socket_fd, (void *)data, sizeof(data));

  if (data_size < 0)
  {
    perror("erreur lecture");
    return (EXIT_FAILURE);
  }

  /*
   * extraire le code des données envoyées par le client.
   * Les données envoyées par le client peuvent commencer par le mot "message :" ou un autre mot.
   */
  printf("Message recu: %s\n", data);
  char code[10];
  sscanf(data, "%s:", code);
  

  // Si le message commence par le mot: 'message:'
  if (strcmp(code, "message") == 0)
  { printf("oui");
    // la réinitialisation de l'ensemble des données
    memset(data, 0, sizeof(data));
  
    // Demandez à l'utilisateur d'entrer un message
    char message[1024];
    printf("Votre message (max 1000 caracteres): ");
    fgets(message, sizeof(message), stdin);
    strcpy(data, "message : ");
    strcat(data, message);

    renvoie_message(client_socket_fd, data);
  }

  // fermer le socket
  close(socketfd);
  return (EXIT_SUCCESS);
}

int recois_numeros_calcule(int socketfd,int mode,int client_socket_fd){ // Fonction effectuant les opérations mathématiques 
  
  // Varibales  
  char op;
  float num1;
  float num2;
  float res;
  char data[1024];
  char *fin="oui";

  while (strcmp("oui",fin)==0){ // Boucle WHILE permetant la lecture en continue de requete du clients car dans client.c on utilise le socket plusieurs fois 
  
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));
  
  // lecture de données envoyées par un client
  int data_size = read(client_socket_fd, (void *)data, sizeof(data));
    
  if(strcmp("non",data)==0){ // Condition de fin de la boucle quand plus aucune information est envoyé par le client
      break;
    }

  if (data_size < 0)
  {
    perror("erreur lecture");
    return (EXIT_FAILURE);
  }

  /*
   * extraire le code des données envoyées par le client.
   * Les données envoyées par le client peuvent commencer par le mot "message :" ou un autre mot.
   */
  printf("Message recu: %s\n", data);
  char code[10];
  sscanf(data, "%s:", code);

  // Si le message commence par le mot: 'calcule:' ou est une requete pour calculer des moyennes
  if ((strcmp(code, "calcule") == 0)||(mode==3))
  { 
    if (mode==2){ // Pour les operation mathematique basique on reçois un message sous la forme "calcule : 'operande' 'num1' 'num2'" que l'on traite pour obtenire les informations 
    sscanf(data,"%*s %*c %c %f %f",&op,&num1,&num2);
    printf("%c %f %f",op,num1,num2);
    }

    else{ // Pour le calcule de moyenne on recoi un message souys la forme "'operande' 'num1' 'num2'"
    sscanf(data," %c %f %f",&op,&num1,&num2);
    }
    printf("%c %f %f\n",op,num1,num2);
    switch (op) { // Switch case pour réaliser uniquement l'opération voulue
      case '+': res=num1+num2;break;
      case '-': res=num1-num2;break;
      case '*': res=num1*num2;break;
      case '/': res=num1/num2;break;
      case '%': res=(int)num1%(int)num2;break;
      case '&': res=(int)num1&(int)num2;break;
      case '|': res=(int)num1|(int)num2;break;
    }
    // Renvoie des resultats
    if (mode!=3){
      printf("%f\n",res);
      sprintf(data,"calcule : %f",res);
      renvoie_message(client_socket_fd, data);
      break;
    }
    printf("%f\n",res);
    sprintf(data,"%f",res);
    renvoie_message(client_socket_fd, data);
  }
  }
  // fermer le socket
  close(socketfd);
  return (EXIT_SUCCESS);

}

int main()
{
  int mode = 3; // 1 = mode transmission de message (Exo 4), 2 = calcule (Exo 5), 3 = cacule des moyennes (Exo 6)

  int socketfd;
  int bind_status;

  struct sockaddr_in server_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
    perror("Unable to open a socket");
    return -1;
  }

  int option = 1;
  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  // détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Relier l'adresse à la socket
  bind_status = bind(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (bind_status < 0)
  {
    perror("bind");
    return (EXIT_FAILURE);
  }

  // Écouter les messages envoyés par le client
  listen(socketfd, 10);

  struct sockaddr_in client_addr;
  unsigned int client_addr_len = sizeof(client_addr);

  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *)&client_addr, &client_addr_len);
  if (client_socket_fd < 0)
  {
    perror("accept");
    return (EXIT_FAILURE);
  }

  if (mode==1){ // Lire et répondre au client
    recois_envoie_message(socketfd,client_socket_fd);
  }
  if (mode==2){ // Lire, effefctuer l'operation et repondre au client
    recois_numeros_calcule(socketfd,mode,client_socket_fd);
  }
  if (mode==3){ // Lire, effefctuer l'operation et repondre au client
    recois_numeros_calcule(socketfd,mode,client_socket_fd);
  }

  return 0;
}