#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"

void sauvegarderPartie(Plateau p, Contrat c, int vies, int niveau) {
    FILE *f = fopen("sauvegarde.txt", "w");

    if (f == NULL) {
        printf("\n[ERREUR] Impossible de creer le fichier.\n");
        return;
    }

    // Sauvegarde des scores et du curseur
    fprintf(f, "%d %d %d %d %d %d\n", vies, niveau, c.coupsRestants, c.tempsRestant, p.curseurX, p.curseurY);

    // Sauvegarde des cibles du contrat
    for (int i = 1; i <= NB_TYPES_ITEMS; i++) {
        fprintf(f, "%d ", c.cibles[i]);
    }
    fprintf(f, "\n");

    // Sauvegarde de la grille
    for (int i = 0; i < NB_LIGNES; i++) {
        for (int j = 0; j < NB_COLONNES; j++) {
            fprintf(f, "%d ", p.grille[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
    printf("\n[SAUVEGARDE] Reussie dans sauvegarde.txt !\n");
    printf("Appuyez sur une touche pour continuer...");
    
    // Petite pause pour que le joueur voie le message
    char pause;
    scanf(" %c", &pause); 
}