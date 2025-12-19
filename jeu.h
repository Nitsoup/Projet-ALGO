#ifndef JEU_H
#define JEU_H
#include <stdbool.h>

// --- Constantes ---
#define NB_LIGNES 25
#define NB_COLONNES 45
#define NB_TYPES_ITEMS 5
#define VIES_DEPART 3

// --- Structures ---
typedef struct {
    int grille[NB_LIGNES][NB_COLONNES];
    int curseurX;
    int curseurY;
} Plateau;

typedef struct {
    int cibles[NB_TYPES_ITEMS + 1];
    int coupsRestants;
    int tempsRestant;
} Contrat;

// --- Prototypes : Initialisation ---
void genererPlateau(Plateau *p);

// --- Prototypes : Affichage ---
void afficherIHM(Plateau p, int vies, Contrat c, int niveau);
void afficherPlateau(Plateau *p);

// --- Prototypes : Logique (Matrice) ---
void appliquerGraviteEtRemplissage(Plateau *p);
int supprimerSuites4(Plateau *p, Contrat *c);
int supprimerCarre4x4(Plateau *p, Contrat *c);
int supprimerCroix9(Plateau *p, Contrat *c);
int supprimerSuite6(Plateau *p, Contrat *c);
void mettreAJourPlateau(Plateau *p, Contrat *c);
void stabiliserPlateau(Plateau *p, Contrat *c);
void permuterItems(Plateau *p, int x1, int y1, int x2, int y2);
void gererDeplacement(Plateau *p, Contrat *c);
void gererAction(Plateau *p, Contrat *c);
void sauvegarderPartie(Plateau p, Contrat c, int vies, int niveau);
#endif 