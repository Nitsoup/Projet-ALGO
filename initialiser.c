
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "initialiser.h"
#include <windows.h>


void genererPlateau(Plateau *p) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {

            p->grille[i][j] = (rand() % NB_TYPES_ITEMS) + 1;
        }
    }
    p->curseurX = NB_COLONNES / 2;
    p->curseurY = NB_LIGNES / 2;
}

