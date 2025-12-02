//
// Created by Myotte-Duquet on 24/11/2025.
//

#ifndef UNTITLED1_BC_H
#define UNTITLED1_BC_H
#include "regle.h"

typedef struct ElementBC {
    Regle* regle; //Chaque élement de la BC contient une règle
    struct ElementBC *next; //Pointeur Donnant Sur le prochain element de la BC (Liste chainée)
}ElementBC;

typedef ElementBC *BC; //Choix : La BC en elle même est un ElementBC

BC CreerBaseVide();
BC AjoutRegle(BC bc, Regle *r);
Regle* RegleBase(BC bc);


#endif //UNTITLED1_BC_H