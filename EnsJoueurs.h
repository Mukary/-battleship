#include <stdio.h>
#include <stdlib.h>
#ifndef ENSJOUEURS_H
#define ENSJOUEURS_H
#include "Joueur.h"

typedef struct EnsJ EnsJ;
typedef EnsJ *EnsJoueurs;

EnsJoueurs creer_EnsJoueurs(); /* estVide_EnsJoueurs(creer_EnsJoueurs()) == True */
EnsJoueurs ajouterJoueur(Joueur J, EnsJoueurs E); /* maximum de 2 joueurs */
EnsJoueurs supprimerJoueur(Joueur J, EnsJoueurs E); /* ne peut pas supprimer un joueur si la Partie commence ou si le joueur  à supprimer n'est pas dans l'ensemble ou si l'ensemble est vide */


#endif
