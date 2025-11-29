//
// Created by Myotte-Duquet on 24/11/2025.
//

#ifndef UNTITLED1_REGLE_H
#define UNTITLED1_REGLE_H

//Convention : SI IL Y A QU'UN SEUL ELEMENT DANS UNE REGLE IL S'AGIT DE LA CONCLUSION
typedef struct ElementRegle {
    struct ElementRegle *next; //Pointeur Donnant Sur le prochain element de la règle (Liste chainée)
    char *proposition; //Contenu de la proposition
}ElementRegle;

typedef ElementRegle *Regle; //Choix : La Règle en elle même est un ElementRegle

Regle CreerRegleVide();
Regle AjoutPremisse(Regle r, char *premisse);
Regle AjoutConclusion(Regle r, char *conclusion);
int TestPremisse(Regle r, char *proposition);
Regle SupprimeProposition(Regle r, char *proposition);
int PremisseEstVide(Regle r);
int ConclusionSeule(Regle r);
char* PremierPremisse(Regle r);
char* Conclusion(Regle r);
#endif //UNTITLED1_REGLE_H