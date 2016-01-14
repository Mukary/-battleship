#include <stdio.h>
#include <stdlib.h>
#ifndef POSITION_H
#define POSITION_H

typedef struct Coord Coord; /*Morceau de bateau ou simplement une Position de tir*/
typedef Coord *Position;

Position creerPosition(int x, int y);/*est valide si Position valide.*/
int Position_valide(Position P); /*True si la Position appartient a la grille, False sinon*/

#endif
