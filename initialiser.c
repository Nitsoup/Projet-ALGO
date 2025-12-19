#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"
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

void afficherPlateau(Plateau *p) {
    // Efface la console (Windows)
    system("cls");

    printf("--- PLATEAU DE JEU ---\n\n");

    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            
            // Si le curseur est sur cette case, on l'entoure de crochets [ ]
            if (i == p->curseurY && j == p->curseurX) {
                printf("[%d]", p->grille[i][j]);
            } else {
                // Sinon on affiche l'item normalement
                printf(" %d ", p->grille[i][j]);
            }
        }
        printf("\n"); // Retour à la ligne après chaque ligne de la grille
    }
    
    printf("\nPosition curseur : (%d, %d)\n", p->curseurX, p->curseurY);
}

void permuterItems(Plateau *p, int x1, int y1, int x2, int y2) {
    int temp = p->grille[y1][x1];
    p->grille[y1][x1] = p->grille[y2][x2];
    p->grille[y2][x2] = temp;
}

// Sous-programme : Gestion du curseur et de l'échange
void gererAction(Plateau *p, Contrat *c) {
    char touche;
    
    printf("\nCOMMANDES : z(haut), s(bas), q(gauche), d(droite), p(permuter), v(sauvegarder) + ENTREE : ");
    
    scanf(" %c", &touche); 

    if (touche == 'z' && p->curseurY > 0) p->curseurY--;
    else if (touche == 's' && p->curseurY < NB_LIGNES - 1) p->curseurY++;
    else if (touche == 'q' && p->curseurX > 0) p->curseurX--;
    else if (touche == 'd' && p->curseurX < NB_COLONNES - 1) p->curseurX++;
    else if (touche == 'v') {
        // Appeler la sauvegarde 
        sauvegarderPartie(*p, *c, 3, 1);
    }
    else if (touche == 'p') {
        char dir;
        printf("Permuter avec quel voisin ? (z,q,s,d) + ENTREE : ");
        scanf(" %c", &dir);
        
        int nx = p->curseurX, ny = p->curseurY;
        if (dir == 'z') ny--;
        else if (dir == 's') ny++;
        else if (dir == 'q') nx--;
        else if (dir == 'd') nx++;

        if (nx >= 0 && nx < NB_COLONNES && ny >= 0 && ny < NB_LIGNES) {
            permuterItems(p, p->curseurX, p->curseurY, nx, ny);
            c->coupsRestants--;
            // On lance la stabilisation pour supprimer les alignements créés
            stabiliserPlateau(p, c);
        }
    }

}
