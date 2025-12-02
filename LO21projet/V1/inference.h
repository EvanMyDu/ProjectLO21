//
// Created by Myotte-Duquet on 24/11/2025.
//

#ifndef UNTITLED1_INFERENCE_H
#define UNTITLED1_INFERENCE_H

#include "bc.h"
#include "regle.h"

typedef struct ElementFait {
    char *fait;
    struct ElementFait *next;
} ElementFait;

typedef ElementFait *ListeFaits;

// Opérations sur les faits
ListeFaits CreerListeFaitsVide();
ListeFaits AjouterFait(ListeFaits f, char *fait);
int FaitAppartient(ListeFaits f, char *fait);
void AfficherFaits(ListeFaits f);

// Vérification des prémisses
int PremissesVerifier(Regle *r, ListeFaits listeFaits);

// Moteur d'inférence
ListeFaits moteur_inferences(BC BaseConnaissance, ListeFaits BaseFaits);

#endif //UNTITLED1_INFERENCE_H