//
// Created by Myotte-Duquet on 24/11/2025.
//

#include "regle.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Convention : SI IL Y A QU'UN SEUL ELEMENT DANS UNE REGLE IL S'AGIT DE LA CONCLUSION

typedef struct ElementRegle {
    struct ElementRegle *next;
     char *proposition;
}ElementRegle;

typedef ElementRegle *Regle;

Regle CreerRegleVide() {
    return NULL;
}

Regle AjoutPremisse(Regle r, char *premisse) {
    ElementRegle *proposition = malloc(sizeof(ElementRegle));
    proposition->proposition = premisse;
    proposition->next = NULL;
    if (r == NULL) {
        r = proposition;
        return r;
    }
    ElementRegle *p = r;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = proposition;

    return r;
}

Regle AjoutConclusion(Regle r, char *conclusion) {
    return AjoutPremisse(r, conclusion);
}

int TestPremisse(Regle r, char *proposition) {
    if (r == NULL || r->next == NULL) {
        return 1;
    }
    else {
        if (strcmp(r->proposition, proposition) == 0) {
            return 0;
        }
        else {
            return TestPremisse(r->next, proposition);
        }
    }
}


Regle SupprimeProposition(Regle r, char *proposition) {
    if (r==NULL) {
        return NULL;
    }
    if (r->next != NULL && strcmp(r->proposition, proposition) == 0) {
        ElementRegle *tmp = r;
        r=r->next;
        free(tmp);
        return r;
    }
    else {
        ElementRegle *p = r;
        while (p->next->next != NULL) {
            if (strcmp(p->next->proposition, proposition) == 0) {
                ElementRegle *tmp = p->next;
                p->next =p->next->next;
                free(tmp);
                return r;
            }
            p = p->next;
        }
    }
    return r;

}

int PremisseEstVide(Regle r) {
    if (r != NULL && r->next != NULL ) {
        return 0;
    }
    return 1;
}

int ConclusionSeule(Regle r) {
    if (r != NULL && r->next == NULL ) {
        return 1;
    }
    return 0;
}

char* PremierPremisse(Regle r) {
    if (PremisseEstVide(r) == 0) {
        return r->proposition;
    }
    return NULL;

}

char* Conclusion(Regle r) {
    if (r == NULL) {
        return NULL;
    }
    ElementRegle *p = r;
    while (p->next != NULL) {
        p = p->next;
    }
    return p->proposition;
}