// Fichier permetant la déclaration des differents elements nécessaires au fonctionnement du programme

struct couleur { //création de la structure 'couleur' contenant les couleurs
    unsigned int rouge;
    unsigned int vert;
    unsigned int bleu;
    unsigned int alpha;
    struct couleur *suivant;
    struct couleur *precedent;
};

struct liste_couleurs { // Remplissez ça pour gérer une liste (simplement chainée) de couleurs.
    struct couleur premier;
    struct couleur dernier;
};

// Declaration des fonctions 
void insertion (struct couleur *, struct liste_couleurs *);    

void parcours (struct liste_couleurs *);   