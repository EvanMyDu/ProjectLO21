#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regle.h"
#include "bc.h"
#include "inference.h"

int main(){

    /* -----------------------------
       Création de la Base de Faits
       -----------------------------*/
    ListeFaits BF = CreerListeFaitsVide();

    // Créer des copies des chaînes pour éviter les problèmes de mémoire
    char *fait1 = malloc(20);
    char *fait2 = malloc(20);
    strcpy(fait1, "¬moteurDemarre");
    strcpy(fait2, "pharesFonctionnent");

    BF = AjouterFait(BF, fait1);
    BF = AjouterFait(BF, fait2);

    printf("=== Base de faits initiale ===\n");
    AfficherFaits(BF);


    /* -----------------------------
       Création de la Base de Connaissances
       -----------------------------*/
    BC BC1 = CreerBaseVide();

    /* ----- Règle R1 ----- */
    Regle *R1 = CreerRegleVide();

    char *p1R1 = malloc(20);
    char *p2R1 = malloc(20);
    char *p3R1 = malloc(20);
    char *cR1 = malloc(20);

    strcpy(p1R1, "¬reservoirVide");
    strcpy(p2R1, "pharesFonctionnent");
    strcpy(p3R1, "¬moteurDemarre");
    strcpy(cR1, "problemeBougie");

    R1 = AjoutPremisse(R1, p1R1);
    R1 = AjoutPremisse(R1, p2R1);
    R1 = AjoutPremisse(R1, p3R1);
    R1 = AjoutConclusion(R1, cR1);
    BC1 = AjoutRegle(BC1, R1);

    /* ----- Règle R2 ----- */
    Regle *R2 = CreerRegleVide();

    char *p1R2 = malloc(20);
    char *p2R2 = malloc(20);
    char *cR2 = malloc(20);

    strcpy(p1R2, "¬moteurDemarre");
    strcpy(p2R2, "¬pharesFonctionnent");
    strcpy(cR2, "problemeBatterie");

    R2 = AjoutPremisse(R2, p1R2);
    R2 = AjoutPremisse(R2, p2R2);
    R2 = AjoutConclusion(R2, cR2);
    BC1 = AjoutRegle(BC1, R2);

    /* ----- Règle R3 ----- */
    Regle *R3 = CreerRegleVide();

    char *p1R3 = malloc(20);
    char *p2R3 = malloc(20);
    char *cR3 = malloc(20);

    strcpy(p1R3, "¬moteurDemarre");
    strcpy(p2R3, "pharesFonctionnent");
    strcpy(cR3, "problemeStarter");

    R3 = AjoutPremisse(R3, p1R3);
    R3 = AjoutPremisse(R3, p2R3);
    R3 = AjoutConclusion(R3, cR3);
    BC1 = AjoutRegle(BC1, R3);


    /* -----------------------------
       Exécution du moteur d'inférences
       -----------------------------*/
    printf("\n=== Lancement du moteur d'inférences ===\n");
    BF = moteur_inferences(BC1, BF);

    printf("\n=== Base de faits finale ===\n");
    AfficherFaits(BF);

    /* -----------------------------
       Nettoyage mémoire
       -----------------------------*/
    // Libérer la mémoire allouée
    free(fait1);
    free(fait2);
    free(p1R1); free(p2R1); free(p3R1); free(cR1);
    free(p1R2); free(p2R2); free(cR2);
    free(p1R3); free(p2R3); free(cR3);

    // Note: Vous devriez aussi ajouter des fonctions pour libérer
    // les listes chaînées (BC et ListeFaits)

    return 0;
}
