#include <stdio.h>
#include <stdlib.h>
#ifndef JOUEUR_H
#define JOUEUR_H
#include "EnsBateaux.h"


typedef struct Player Player;
typedef Player *Joueur;

Joueur creerJoueur(EnsBateaux E, int x); /*Joueur != NULL càd qu'un joueur n'est valide que s'il a au moins un bateau dans EnsBateaux et un numero => joueur_Valide(creerJoueur()) == True*/
EnsBateaux get_EnsBateaux(Joueur J); /*recupere l'ensemble de bateaux d'un joueur*/
int description_Joueur_Actif(Joueur J); /*renvoie le numero d'un joueur*/
int verif_tir(Position Tir, Joueur J); /*renvoie 0 si à l'eau, 1 si touché, 2 si en vue*/
void supprimer_Position(Joueur J, Position P);/* verif_tir(Tir, J) == 1 */
int taille_flotte_joueur(Joueur J);/* recupere le nombre de bateaux non détruits de EnsBateaux d'un joueur J*/
#endif
