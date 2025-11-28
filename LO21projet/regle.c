//
// Created by Myotte-Duquet on 24/11/2025.
//

#include "regle.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Convention : SI IL Y A QU'UN SEUL ELEMENT DANS UNE REGLE IL S'AGIT DE LA CONCLUSION

typedef struct ElementRegle {
    struct ElementRegle *next; //Pointeur Donnant Sur le prochain element de la règle (Liste chainée)
     char *proposition; //Contenu de la proposition
}ElementRegle;

typedef ElementRegle *Regle; //Choix : La Règle en elle même est un ElementRegle

Regle CreerRegleVide() {
    return NULL;
}

Regle AjoutPremisse(Regle r, char *premisse) {
    ElementRegle *proposition = malloc(sizeof(ElementRegle)); //On associe de la mémoire pour la nouvelle proposition
    proposition->proposition = premisse;
    proposition->next = NULL;
    if (r == NULL) { //Cas où la règle est vide
        r = proposition;
        return r;
    }
    ElementRegle *p = r; //Pointeur pour parcourir la règle sans la modifier
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = proposition; //Une fois à la fin on ajoute la nouvelle proposition

    return r;
}

Regle AjoutConclusion(Regle r, char *conclusion) { //La conclusion étant la dernière proposition d'une règle cela revient à utiliser AjoutPrémisse
    return AjoutPremisse(r, conclusion);
}

int TestPremisse(Regle r, char *proposition) { //La fonction permet de savoir si une proposition appartient à une règle
    if (r == NULL || r->next == NULL) { //Cas de base : Cas où la règle est vide ou possède seulement la conclusion (Convention)
        return 1; //return 1 pour FAUX
    }
    else {
        if (strcmp(r->proposition, proposition) == 0) { //on compare la proposition en argument avec celle de la règle donnée
            return 0; //return 0 pour Vrai
        }
        else {
            return TestPremisse(r->next, proposition); //Récursivité on passe à la proposition suivante de la règle donnée
        }
    }
}


Regle SupprimeProposition(Regle r, char *proposition) { //Fonction pour supprimer une proposition de la prémisse
    if (r==NULL) { //Cas où la règle est vide
        return NULL;
    }
    if (r->next != NULL && strcmp(r->proposition, proposition) == 0) { //Cas où le premier élement de la règle est bien la proposition que l'on veut supprimer et que ce n'est pas la conclusion
        ElementRegle *tmp = r; //on créé un tampon pointant sur r car on doit sauvegarder cette adresse mémoire pour la libérer par la suite
        r=r->next; //Pour remettre à jour l'ordre de la règle après l'effacement
        free(tmp); //on libère la mémoire associée au pointeur tmp
        return r;
    }
    else {
        ElementRegle *p = r;
        while (p->next->next != NULL) { //Pour ne pas avoir la cas où la proposition que l'on étudie est la conclusion
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

int PremisseEstVide(Regle r) {
    if (r != NULL && r->next != NULL ) { //Convention : Si la règle est vide ou si il y a une seule proposition dans la règle soit la conclusion on retourne 1
        return 0;
    }
    return 1;
}

int ConclusionSeule(Regle r) {  //Convention : Si la règle est vide ou si il y a plus d'une seule proposition dans la règle on retourne 1
    if (r != NULL && r->next == NULL ) {
        return 1;
    }
    return 0;
}

char* PremierPremisse(Regle r) { //Cela renvoie la première proposition de la prémisse
    if (PremisseEstVide(r) == 0) { //Cas où la règle n'est pas vide (+ de 1 proposition)
        return r->proposition;
    }
    return NULL;

}

char* Conclusion(Regle r) { //Cela renvoie la conclusion
    if (r == NULL) { //Cas où la règle est vide
        return NULL;
    }
    ElementRegle *p = r; //Pointeur pour parcourir la règle sans la modifier
    while (p->next != NULL) { //On s'arrête au dernier élement qui est la conclusion
        p = p->next;
    }
    return p->proposition; //On renvoie la conclusion
}