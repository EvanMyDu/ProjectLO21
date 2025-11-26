//
// Created by Myotte-Duquet on 24/11/2025.
//
#include <stdlib.h>
#include <string.h>
#include "bc.h"


typedef struct ElementBC {
        Regle regle;
        struct ElementBC *next;
}ElementBC;

typedef ElementBC *BC;

BC CreerBaseVide() {
        return NULL;
}

BC AjoutRegle(BC bc, Regle r) {
        ElementBC *newel = malloc(sizeof(ElementBC));
        newel->regle = r;
        newel->next = NULL;
        if (bc == NULL) {
                bc = newel;

                return bc;
        }
        ElementBC *p = bc;
        while (p->next != NULL) {
                p = p->next;
        }
        p->next = newel;
        return bc;
}


Regle RegleBase(BC bc) {
        if (bc == NULL) {
                return NULL;
        }
        return bc->regle;
}