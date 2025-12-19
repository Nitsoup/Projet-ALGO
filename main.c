#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"

int main() {
    Plateau monPlateau;
    Contrat monContrat;
    int vies = 3;
    int niveau = 1;

    // 1. Initialisation (Giulia)
    genererPlateau(&monPlateau);
    monContrat.coupsRestants = 20;
    monContrat.tempsRestant = 120;
    for(int i=0; i<=NB_TYPES_ITEMS; i++) monContrat.cibles[i] = 10;

    // 2. Affichage initial
    afficherIHM(monPlateau, vies, monContrat, niveau);

    printf("\nAppuyez sur Entree pour tester la suppression forcee...");
    getchar(); // Premier arrêt

    // 3. Test de suppression (Ton code)
    monPlateau.grille[0][0] = 1;
    monPlateau.grille[0][1] = 1;
    monPlateau.grille[0][2] = 1;
    monPlateau.grille[0][3] = 1;

    printf("Ligne de 4 creee. Stabilisation...\n");
    stabiliserPlateau(&monPlateau, &monContrat);
    afficherIHM(monPlateau, vies, monContrat, niveau);

    printf("\nTests finis. Appuyez sur Entree pour JOUER REELLEMENT...");
    // ... après tes tests ...


while (getchar() != '\n'); 

while (vies > 0 && monContrat.coupsRestants > 0) {
    // 1. Affichage
    afficherIHM(monPlateau, vies, monContrat, niveau);

    // 2. Gestion de l'action
    gererAction(&monPlateau, &monContrat);
}
    
    // Nettoyage du tampon avant de lancer la boucle
    int c; while ((c = getchar()) != '\n' && c != EOF); 

    // 4. BOUCLE DE JEU INTERACTIVE
    while (vies > 0 && monContrat.coupsRestants > 0) {
        afficherIHM(monPlateau, vies, monContrat, niveau);
        gererAction(&monPlateau, &monContrat); 
    }

    printf("\nPartie terminee !\n");
    return 0;
}