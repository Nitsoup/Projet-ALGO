#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"

void afficherIHM(Plateau p, int vies, Contrat c, int niveau) {

    system("cls");


    printf("=============================================\n");
    printf("   NIVEAU %d  |  VIES : %d  |  COUPS : %d\n", niveau, vies, c.coupsRestants);
    printf("   TEMPS RESTANT : %d secondes\n", c.tempsRestant);
    printf("=============================================\n\n");


    printf("CONTRAT A REMPLIR :\n");
    for(int i = 1; i <= NB_TYPES_ITEMS; i++) {
        if(c.cibles[i] > 0) {
            printf("  Item %d : %d restants | ", i, c.cibles[i]);
        }
    }
    printf("\n\n");


    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {


            if (i == p.curseurY && j == p.curseurX) {
                printf("[%d]", p.grille[i][j]);
            } else {
                switch(p.grille[i][j]) {
                    case 1: printf(" @ "); break;
                    case 2: printf(" # "); break;
                    case 3: printf(" $ "); break;
                    case 4: printf(" X "); break;
                    case 5: printf(" O "); break;
                    default: printf(" . "); break;
                }
            }
        }
        printf("\n");
    }
}