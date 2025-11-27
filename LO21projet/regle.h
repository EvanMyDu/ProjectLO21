//
// Created by Myotte-Duquet on 24/11/2025.
//

#ifndef UNTITLED1_REGLE_H
#define UNTITLED1_REGLE_H
typedef struct ElementRegle ElementRegle;
typedef ElementRegle *Regle;

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