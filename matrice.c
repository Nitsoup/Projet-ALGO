
#include "matrice.h"
#include <stdlib.h>
#include "initialiser.h"

int supprimerCarre4x4(Plateau *p, Contrat *c) {
    int aSupprime = 0;

    for (int i = 0; i <= NB_LIGNES - 4; i++) {
        for (int j = 0; j <= NB_COLONNES - 4; j++) {
            int type = p->grille[i][j];
            if (type == 0) continue;

            int estCarre = 1;

            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; y++) {
                    if (p->grille[i+x][j+y] != type) estCarre = 0;
                }
            }

            if (estCarre) {
                aSupprime = 1;
                for (int x = 0; x < 4; x++) {
                    for (int y = 0; y < 4; y++) {
                        // Mise à jour du contrat
                        if (c->cibles[type] > 0) c->cibles[type]--;
                        p->grille[i+x][j+y] = 0;
                    }
                }
            }
        }
    }
    return aSupprime;
}


int supprimerSuite6(Plateau *p, Contrat *c) {
    int aSupprime = 0;
    int typeATraiter = 0;


    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j <= NB_COLONNES - 6; j++) {
            int type = p->grille[i][j];
            if (type != 0 &&
                p->grille[i][j+1] == type && p->grille[i][j+2] == type &&
                p->grille[i][j+3] == type && p->grille[i][j+4] == type &&
                p->grille[i][j+5] == type) {

                typeATraiter = type;
                aSupprime = 1;
                }
        }
    }


    for (int j = 0; j < NB_COLONNES; j++) {
        for (int i = 0; i <= NB_LIGNES - 6; i++) {
            int type = p->grille[i][j];
            if (type != 0 &&
                p->grille[i+1][j] == type && p->grille[i+2][j] == type &&
                p->grille[i+3][j] == type && p->grille[i+4][j] == type &&
                p->grille[i+5][j] == type) {

                typeATraiter = type;
                aSupprime = 1;
                }
        }
    }


    if (aSupprime) {
        for (int i = 0; i < NB_LIGNES; i++) {
            for (int j = 0; j < NB_COLONNES; j++) {
                if (p->grille[i][j] == typeATraiter) {
                    if (c->cibles[typeATraiter] > 0) c->cibles[typeATraiter]--;
                    p->grille[i][j] = 0;
                }
            }
        }
    }

    return aSupprime;
}

int supprimerSuites4(Plateau *p, Contrat *c) {
    int aSupprime = 0;
    // Vérification horizontale
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j <= NB_COLONNES - 4; j++) {
            int type = p->grille[i][j];
            if (type != 0 && p->grille[i][j+1] == type &&
                p->grille[i][j+2] == type && p->grille[i][j+3] == type) {
                for(int k = 0; k < 4; k++) p->grille[i][j+k] = 0;
                if(c->cibles[type] > 0) c->cibles[type] -= 4;
                aSupprime = 1;
                }
        }
    }
    // Vérification verticale
    for (int j = 0; j < NB_COLONNES; j++) {
        for (int i = 0; i <= NB_LIGNES - 4; i++) {
            int type = p->grille[i][j];
            if (type != 0 && p->grille[i+1][j] == type &&
                p->grille[i+2][j] == type && p->grille[i+3][j] == type) {
                for(int k = 0; k < 4; k++) p->grille[i+k][j] = 0;
                if(c->cibles[type] > 0) c->cibles[type] -= 4;
                aSupprime = 1;
                }
        }
    }
    return aSupprime;
}

void mettreAJourPlateau(Plateau *p, Contrat *c) {
    supprimerSuite6(p, c);
    supprimerCroix9(p, c);
    supprimerCarre4x4(p, c);
    supprimerSuites4(p, c);

    // Utilisez la fonction fusionnée ici aussi
    appliquerGraviteEtRemplissage(p);
}
int supprimerCroix9(Plateau *p, Contrat *c) {
    int aSupprime = 0;
    int ligneImpactee = -1;
    int colonneImpactee = -1;
    int typeImpacte = 0;


    for (int i = 2; i < NB_LIGNES - 2; i++) {
        for (int j = 2; j < NB_COLONNES - 2; j++) {
            int type = p->grille[i][j];
            if (type == 0) continue;


            if (p->grille[i-1][j] == type && p->grille[i-2][j] == type &&
                p->grille[i+1][j] == type && p->grille[i+2][j] == type &&
                p->grille[i][j-1] == type && p->grille[i][j-2] == type &&
                p->grille[i][j+1] == type && p->grille[i][j+2] == type)
            {
                typeImpacte = type;
                ligneImpactee = i;
                colonneImpactee = j;
                aSupprime = 1;
                break;
            }
        }
        if (aSupprime) break;
    }


    if (aSupprime) {

        for (int j = 0; j < NB_COLONNES; j++) {
            if (p->grille[ligneImpactee][j] == typeImpacte) {
                if (c->cibles[typeImpacte] > 0) c->cibles[typeImpacte]--;
                p->grille[ligneImpactee][j] = 0;
            }
        }

        for (int i = 0; i < NB_LIGNES; i++) {
            if (p->grille[i][colonneImpactee] == typeImpacte) {
                if (c->cibles[typeImpacte] > 0) c->cibles[typeImpacte]--;
                p->grille[i][colonneImpactee] = 0;
            }
        }
    }

    return aSupprime;
}

void stabiliserPlateau(Plateau *p, Contrat *c) {
    int encoreDesSuppressions = 1;
    while (encoreDesSuppressions) {
        int s4 = supprimerSuites4(p, c);
        int sc = supprimerCarre4x4(p, c);
        int sx = supprimerCroix9(p, c);
        int s6 = supprimerSuite6(p, c);

        if (s4 || sc || sx || s6) {
            // Remplacez les deux anciennes lignes par celle-ci :
            appliquerGraviteEtRemplissage(p);
            encoreDesSuppressions = 1;
        } else {
            encoreDesSuppressions = 0;
        }
    }
}

void appliquerGraviteEtRemplissage(Plateau *p) {
    // 1. PHASE DE GRAVITÉ : On fait tomber les items existants
    for (int j = 0; j < NB_COLONNES; j++) {
        for (int i = NB_LIGNES - 1; i > 0; i--) {
            if (p->grille[i][j] == 0) {
                int k = i - 1;
                while (k >= 0 && p->grille[k][j] == 0) k--;
                if (k >= 0) {
                    p->grille[i][j] = p->grille[k][j];
                    p->grille[k][j] = 0;
                }
            }
        }
    }

    // 2. PHASE DE REMPLISSAGE COMPLET : On remplit TOUS les trous restants en haut
    // On parcourt toute la grille. Si une case est encore à 0, on met un nouvel item.
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            if (p->grille[i][j] == 0) {
                p->grille[i][j] = (rand() % NB_TYPES_ITEMS) + 1;
            }
        }
    }
}