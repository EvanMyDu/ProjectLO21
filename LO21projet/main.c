#include <stdio.h>
#include "regle.h"
#include "bc.h"
#include "inference.h"

int main() {
   printf("=== TEST SYSTÈME EXPERT ===\n\n");

   // 1. Base de faits initiale
   ListeFaits BF = CreerListeFaitsVide();
   BF = AjouterFait(BF, "moteurDemarre");
   BF = AjouterFait(BF, "pharesFonctionnent");
   BF = AjouterFait(BF, "reservoirVide");

   printf("Base de faits initiale: ");
   AfficherFaits(BF);

   // 2. Création des règles
   BC BC1 = CreerBaseVide();

   // Règle 1: A et B et C => D
   Regle *R1 = CreerRegleVide();
   R1 = AjoutPremisse(R1, "reservoirVide");
   R1 = AjoutPremisse(R1, "pharesFonctionnent");
   R1 = AjoutPremisse(R1, "moteurDemarre");
   R1 = AjoutConclusion(R1, "problemeBougie");
   BC1 = AjoutRegle(BC1, R1);

   // Règle 2: A et B => C
   Regle *R2 = CreerRegleVide();
   R2 = AjoutPremisse(R2, "moteurDemarre");
   R2 = AjoutPremisse(R2, "pharesFonctionnent");
   R2 = AjoutConclusion(R2, "problemeBatterie");
   BC1 = AjoutRegle(BC1, R2);

   // Règle 3: A et B => D
   Regle *R3 = CreerRegleVide();
   R3 = AjoutPremisse(R3, "moteurDemarre");
   R3 = AjoutPremisse(R3, "pharesFonctionnent");
   R3 = AjoutConclusion(R3, "problemeStarter");
   BC1 = AjoutRegle(BC1, R3);

   // 3. Exécution du moteur d'inférence
   printf("\nLancement du moteur d'inferences...\n");
   BF = moteur_inferences(BC1, BF);

   printf("\nBase de faits finale: ");
   AfficherFaits(BF);

   printf("\nRelancement du moteur...\n"); //Test pour prouver que les faits ne sont pas ajoutés une deuxieme fois
   BF = moteur_inferences(BC1, BF);

   printf("\nBase de faits finale: "); //On peut voir qu'il n'y a pas de faits en double
   AfficherFaits(BF);

   return 0;
}