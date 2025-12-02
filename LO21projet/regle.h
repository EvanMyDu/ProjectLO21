//
// Created by Myotte-Duquet on 24/11/2025.
//

#ifndef UNTITLED1_REGLE_H
#define UNTITLED1_REGLE_H


typedef struct ElementRegle {
    struct ElementRegle *next; //Pointeur Donnant Sur le prochain element de la règle (Liste chainée)
    char *proposition; //Contenu de la proposition (prémisse)
}ElementRegle;

typedef struct {
    ElementRegle *premisse; //accède à la premiere proposition de la prémisse
    char *conclusion;   //Dans cette version la conclusion est séparée de la prémisse

}Regle;

Regle* CreerRegleVide();
Regle* AjoutPremisse(Regle *r, char *premisse);
Regle* AjoutConclusion(Regle *r, char *conclusion);
int TestPremisse(Regle *r, char *proposition);
int TestDansPremisse(ElementRegle *ElemRegle, char *proposition);
Regle* SupprimeProposition(Regle *r, char *proposition);
int PremisseEstVide(Regle *r);
int ConclusionSeule(Regle *r);
char* PremierPremisse(Regle *r);
char* Conclusion(Regle *r);
#endif //UNTITLED1_REGLE_H