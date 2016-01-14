#include <stdio.h>
#include <stdlib.h>
#ifndef PARTIE_H
#define PARTIE_H
#include "EnsJoueurs.h"


typedef struct Game Game;
typedef Game *Partie;

Partie creerPartie(EnsJoueurs EJ, int tour);/* EJ n'est pas vide et contient exactement 2 joueurs, la partie commence au tour 0 */
Partie changer_tour(Partie P); /* passe du tour T au tour T+1, T < T+1, T un entier >= 0 */
Joueur joueur_actif(Partie P); /*détermine le joueur actif pendant le tour T.*/
Joueur joueur_inactif(Partie P); /*détermine le joueur inactif pendant le tour T.*/
int partie_terminee(Partie P); /* Renvoie si la partie est terminée ou pas */
int gagnant(Partie P); /* renvoie l'identifiant(numero) du joueur gagnant*/
int perdant(Partie P); /* renvoie l'identifiant(numero) du joueur perdant */
int get_Tour(Partie P); /* recupere le tour courant ou initial d'une partie*/
int verif_tir(Position Tir, Joueur J); /*renvoie 0 si à l'eau, 1 si touché, 2 si en vue, vérification faite sur le joueur inactif*/
int est_touche(int resTir); /* True si on a touché un bateau du joueur inactif, False sinon */
int est_en_vue(int resTir); /* True si on a un bateau du joueur inactif en vue, False sinon */
int est_a_leau(int resTir); /* True si on a tiré dans l'eau, False sinon */
void supprimer_Position(Joueur J, Position P);/* verif_tir(Tir, J) == 1, suppression faite sur le joueur inactif*/
#endif
