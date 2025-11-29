//
// Created by Myotte-Duquet on 24/11/2025.
//
#include <stdlib.h>
#include <string.h>
#include "bc.h"




BC CreerBaseVide() {
        return NULL;
}

BC AjoutRegle(BC bc, Regle r) {
        ElementBC *newel = malloc(sizeof(ElementBC)); //On associe de la mémoire pour le nouveau élement de BC
        newel->regle = r;
        newel->next = NULL;
        if (bc == NULL) { //Cas où la BC est vide
                bc = newel;

                return bc;
        }
        ElementBC *p = bc; //On créé un nouvel pointeur pour parcourir la BC sans la modifier
        while (p->next != NULL) { // On s'arrête au dernier élementBC
                p = p->next; //Pour avancer dans la BC
        }
        p->next = newel; //On ajoute le nouvel ElementBC
        return bc;
}


Regle RegleBase(BC bc) { //On retourne la premiere règle de la BC
        if (bc == NULL) {//Cas où la BC est vide
                return NULL;
        }
        return bc->regle; //on renvoie donc la premiere règle de la BC
}