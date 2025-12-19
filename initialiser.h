//
// Created by gward on 17/12/2025.
//


#ifndef PROJET_MATCH_INITIALISER_H
#define PROJET_MATCH_INITIALISER_H


#define NB_LIGNES 25
#define NB_COLONNES 45
#define NB_TYPES_ITEMS 5
#define VIES_DEPART 3




typedef struct {
    int grille[NB_LIGNES][NB_COLONNES];
    int curseurX;
    int curseurY;
} Plateau;

typedef struct {
    int cibles[NB_TYPES_ITEMS +1];
    int coupsRestants;
    int tempsRestant;
} Contrat;


void genererPlateau(Plateau *p);

#endif //PROJET_MATCH_INITIALISER_H