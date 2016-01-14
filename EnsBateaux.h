#include <stdio.h>
#include <stdlib.h>
#ifndef ENSBATEAUX_H
#define ENSBATEAUX_H
#include "Bateau.h"

typedef struct EnsB EnsB;
typedef EnsB *EnsBateaux;

EnsBateaux creer_EnsBateau(); /* estVide_EnsB(creer_EnsBateau) == True */
EnsBateaux ajouterBateau(Bateau B, EnsBateaux EB); /* ne peut pas ajouter un bateau deja present dans EnsBateaux, ne peut pas ajouter un bateau vide */
EnsBateaux supprimerBateau(Bateau B, EnsBateaux EB); /* on ne peut pas supprimer un bateau non présent dans EnsBateaux, on ne peut pas supprimer un bateau si estVide_EnsB(EnsBateaux) == True */
int estVide_EnsB(EnsBateaux EB);/*True si l'ensemble est vide cad que TOUS les bateaux de l'ensemble ont été détruits ou lors de l'initialisation, False sinon*/

#endif
