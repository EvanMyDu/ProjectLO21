//
// Created by Myotte-Duquet on 24/11/2025.
//

#include "regle.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Convention :



Regle* CreerRegleVide() {
    Regle *r = malloc(sizeof(Regle));  //On associe de la mémoire pour créer la nouvelle règle
    r->conclusion = NULL;
    r->premisse = NULL;
    return r;
}

Regle* AjoutPremisse(Regle *r, char *premisse) {
    ElementRegle *proposition = malloc(sizeof(ElementRegle)); //On associe de la mémoire pour la nouvelle proposition
    proposition->proposition = premisse;
    proposition->next = NULL;
    if (r->premisse == NULL) { //Cas où la règle est vide
        r->premisse = proposition; //la règle pointera sur ce premier élement
        return r;
    }
    ElementRegle *p = r->premisse; //Pointeur pour parcourir la règle sans la modifier
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = proposition; //Une fois à la fin on ajoute la nouvelle proposition

    return r;
}

Regle* AjoutConclusion(Regle *r, char *conclusion) { //Dans cette version c'est beaucoup plus simple
    r->conclusion = conclusion;
    return r;
}

int TestPremisse(Regle *r, char *proposition) { //On teste si la règl est vide avant de s'intéresser aux élements
    if (r == NULL || r->premisse == NULL) {
        return 1;  //Cas où la règle est vide ou n'a pas de premisse
    }
    return TestDansPremisse(r->premisse, proposition); //Si c'est bon peut faire la récursion
}

int TestDansPremisse(ElementRegle *ElemRegle, char *proposition) {
    if (ElemRegle == NULL) {
        return 1;  // Fin de liste → FAUX
    }
    if (strcmp(ElemRegle->proposition, proposition) == 0) {
        return 0;  // Trouvé → VRAI
    }
    return TestDansPremisse(ElemRegle->next, proposition);  // Récursion
}


Regle* SupprimeProposition(Regle *r, char *proposition) { //Fonction pour supprimer une proposition de la prémisse
    if (r==NULL) { //Cas où la règle est vide
        return NULL;
    }
    if (r->premisse != NULL && strcmp(r->premisse->proposition, proposition) == 0) { //Cas où le premier élement de la règle est bien la proposition que l'on veut supprimer
        ElementRegle *tmp = r->premisse; //on créé un tampon pointant sur r car on doit sauvegarder cette adresse mémoire pour la libérer par la suite
        r->premisse=r->premisse->next; //Pour remettre à jour l'ordre de la règle après l'effacement
        free(tmp); //on libère la mémoire associée au pointeur tmp
        return r;
    }
    else {
        ElementRegle *p = r->premisse;
        while (p->next != NULL) { //Dans cette version on peut parcourir la règle entierement
            if (strcmp(p->next->proposition, proposition) == 0) { //On compare la proposition de l'élement suivant avec la proposition donnée
                ElementRegle *tmp = p->next; //Pareil qu'avant
                p->next =p->next->next;
                free(tmp);
                return r;
            }
            p = p->next;//Pour avancer dans la règle
        }
    }
    return r;

}

int PremisseEstVide(Regle *r) {
    if (r != NULL && r->premisse ) { //Dans cette version il suffit de tester si la liste est vide et si la prémisse est vide
        return 0;
    }
    return 1;
}

int ConclusionSeule(Regle *r) {
    if (PremisseEstVide(r) == 0 && r->conclusion) { //On teste si la prémisse est vide et que la conclusion est présente
        return 0;
    }
    return 1;
}

char* PremierPremisse(Regle *r) { //Cela renvoie la première proposition de la prémisse
    if (PremisseEstVide(r) == 0) { //Cas où la prémisse n'est pas vide
        return r->premisse->proposition;
    }
    return NULL;

}

char* Conclusion(Regle *r) { //Cela renvoie la conclusion
    if (r == NULL) { //Cas où la règle est vide
        return NULL;
    }
    return r->conclusion;
}