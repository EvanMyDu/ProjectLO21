//
// Created by Myotte-Duquet on 24/11/2025.
//
#include <stdio.h>
#include "inference.h"
#include <stdlib.h>
#include <string.h>

//Créer une liste de faits vide
ListeFaits CreerListeFaitsVide() {
    return NULL;
}

//savoir si un fait appartient à une liste de fait
int FaitAppartient(ListeFaits listeFaits, char * fait) {
    ElementFait *f = listeFaits; //On initialise un *f pour pouvoir parcourir la liste de faits sans modifier la base de faits entrée en paramètre
    while (f != NULL) {
        if (strcmp(f->fait, fait) == 0) return 1; //si c'est la même chaine de str on renvoie vrai
        f = f->next;

        // Besoin de la mettre en full maj ou en full min car TEST != test par exemple

    }
    return 0; //sinon on renvoie faux
}

// Ajouter un fait à la liste
ListeFaits AjouterFait(ListeFaits f, char *fait) {
    // Vérifier si le fait existe déjà
    if (FaitAppartient(f, fait)) {
        return f; //Si il existe on ne le rajoute pas
    }

    ElementFait *nouveau = malloc(sizeof(ElementFait)); //creation d'un nouveau fait
    nouveau->fait = fait;
    nouveau->next = NULL;

    if (f == NULL) { //Si la base de faits est vide alors on renvoie juste ce fait
        return nouveau;
    }

    ElementFait *p = f; //Si la base de faits n'est pas vide alors on ajoute ce fait à la liste de fait et on renvoie la liste f à laquelle on a rajouter nouveau
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = nouveau;
    return f;
}

void AfficherFaits(ListeFaits listeFaits) {
    printf("Faits : ");
    ElementFait *f = listeFaits;
    while (f != NULL) {
        printf("%s", f->fait);
        f = f->next;
        if (f != NULL) {
            printf(", ");
        }
    }
    printf("\n");
}

int PremissesVerifier(Regle *r, ListeFaits listeFaits) {
    if (listeFaits == NULL) return 0; //verifie que la liste de faits n'est pas vide
    if ((r->premisse == NULL) && (r->conclusion == NULL)) return 0; //verifie que la règle existe

    ElementRegle *p = r->premisse;
    while (p->next != NULL) { //on parcours jusqu'à la conclusion
        if (FaitAppartient(listeFaits, p->proposition) == 0) return 0; //la premisse n'est pas verifier
        p = p->next;
    }
    return 1; //toutes les premisses sont dans la base de faits
}

ListeFaits moteur_inferences(BC BaseConnaissance, ListeFaits BaseFaits) {
    int nouveau_fait = 1;

    while(nouveau_fait != 0) {

        nouveau_fait = 0;
        BC courant = BaseConnaissance;

        if (courant == NULL || BaseFaits == NULL) return BaseFaits;

        while (courant != NULL) {

            Regle *regle = courant->regle;
            char *conclusion = Conclusion(regle); // On stocke la conclusion pour éviter de rappeler la fonction plusieurs fois

            if (ConclusionSeule(regle) == 1) { // Cas où la règle ne contient qu'une seule proposition (la conclusion)

                if (FaitAppartient(BaseFaits, conclusion) == 0) { // Si la conclusion n'est pas déjà dans les faits

                    BaseFaits = AjouterFait(BaseFaits, conclusion); //on ajoute la conclusion de cette règle à la base de faits
                    printf("Nouveau fait (conclusion seule) : %s \n", conclusion);
                    nouveau_fait = 1;

                }

            }

            else if (PremissesVerifier(regle, BaseFaits)) { //Si la règle de la base de connaissance a toute ses premisses dans la base de fait

                if (FaitAppartient(BaseFaits, conclusion) == 0) { // Si la conclusion n'est pas déjà dans les faits

                    BaseFaits = AjouterFait(BaseFaits, conclusion); //on ajoute la conclusion de cette règle à la base de faits
                    printf("Nouveau fait : %s \n", conclusion);
                    nouveau_fait = 1;

                }

            }

            courant = courant->next; // On passe à la règle suivante dans la base de connaissances

        }
    }

    return BaseFaits;

}