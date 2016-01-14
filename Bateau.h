#include <stdio.h>
#include <stdlib.h>
#ifndef BATEAU_H
#define BATEAU_H
#include "Position.h"

typedef struct Boat Boat;
typedef Boat *Bateau;

Bateau creerBateau(int tailleB); /* déclare un bateau vide avec une taille T, un bateau ne peut pas ne pas avoir de taille*/
int estVide_bateau(Bateau B); /*True si le bateau est dit "vide" cad que toues ses cases ont été touchées, Faux sinon*/
int est_detruit_bateau(Bateau B); /*renvoie True si l'ensemble des Positions du bateau est vide <=> estVide_bateau(bateau) == True*/
void ajouter_Position(Bateau B, Position P); /*Ajoute seulement si la position est Position valide*/
int get_taille_bateau_init(Bateau B); /* recupere la taille initiale d'un bateau */
int get_taille_bateau_en_cours(Bateau B); /* recupere la taille d'un bateau au cours de la partie, cad le nombre de position encore valide du bateau */


#endif
