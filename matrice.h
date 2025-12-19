//
// Created by gward on 17/12/2025.
//

#ifndef PROJET_MATCH_MATRICE_H
#define PROJET_MATCH_MATRICE_H

#include "initialiser.h"


void appliquerGraviteEtRemplissage(Plateau *p);
void remplirSommet(Plateau *p);

int supprimerSuites4(Plateau *p, Contrat *c);
int supprimerCarre4x4(Plateau *p, Contrat *c);
int supprimerCroix9(Plateau *p, Contrat *c);
int supprimerSuite6(Plateau *p, Contrat *c);

void mettreAJourPlateau(Plateau *p, Contrat *c);
void stabiliserPlateau(Plateau *p, Contrat *c);

#endif //PROJET_MATCH_MATRICE_H