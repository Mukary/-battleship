#include <stdio.h>
#include <stdlib.h>
#include "Bateau.h"
#include "EnsBateaux.h"
#include "EnsJoueurs.h"
#include "Joueur.h"
#include "Partie.h"
#include "Position.h"

/* FONCTIONS GRAPHIQUE */

void message_ajout_bateau(){
  printf("Le bateau a bien été ajouté à la flotte\n");
}

void message_ajout_position(){
  printf("La position a bien été ajoutée au bateau\n");
}

EnsJoueurs init_data(){

  /*Initialisation des ensemble de bateaux de J1 et J2*/
  EnsBateaux EnsBJ1 = creer_EnsBateau();
  EnsBateaux EnsBJ2 = creer_EnsBateau();


  /*Construction des bateaux pour chaque joueur*/
  int taille_bateau[5] = {1,2,3,3,4}; /* taille des bateaux obligatoire pour cette version du jeu*/
  /* Creation des bateaux de J1*/
  int i =0;
  for(i=0;i<5;i++){ /* BEGIN FOR1*/
    Bateau bateau=creerBateau(taille_bateau[i]);
    int morceau=taille_bateau[i];
    for(morceau=taille_bateau[i];morceau>0;morceau--){ /* BEGIN FOR2, INIT BATEAU J1*/
      int position_x =0;
      int position_y =0;
      printf("Entrez l'abscisse x:");
      scanf("%d",&position_x); /* Saisie de l'abscisse*/
      printf("Entrez l'abscisse y:");
      scanf("%d",&position_y); /* Saisie de l'ordonnee*/
      Position position=creerPosition(position_x,position_y);
      /*Controle de la validité de la position créee*/
      while(!(Position_valide(position))){
        printf("Votre coordonnee n'est pas valide, veuillez en entrer une valide SVP !!!\n");
        printf("Entrez l'abscisse x:");
        scanf("%d",&position_x);
        printf("Entrez l'abscisse y:");
        scanf("%d",&position_y);
        Position position=creerPosition(position_x,position_y);

      } /*Condition d'arrêt: Position_valide(position) == true*/
      ajouter_Position(bateau, position); /* On peut ajouter la position créee car Position_valide(position) == true*/
      message_ajout_position();
    } /* END FOR2*/
    ajouterBateau(bateau, EnsBJ1);
    message_ajout_bateau();
  } /* END FOR1*/

  printf("La flotte du joueur J1 a bien été créee, un peu de patience...\n");

  /* Creation des bateaux de J2*/

  for(i=0;i<5;i++){ /* FOR1*/
    Bateau bateau=creerBateau(taille_bateau[i]);
    int morceau=taille_bateau[i];
    for(morceau=taille_bateau[i];morceau>0;morceau--){ /* FOR2 */
      int position_x =0;
      int position_y =0;
      printf("Entrez l'abscisse x:");
      scanf("%d",&position_x); /* Saisie de l'abscisse*/
      printf("Entrez l'abscisse y:");
      scanf("%d",&position_y); /* Saisie de l'ordonnee */
      Position position=creerPosition(position_x,position_y);
      /*Controle de la validité de la position créee */
      while(!(Position_valide(position))){
        printf("Votre coordonnee n'est pas valide, veuillez en entrer une valide SVP !!!\n");
        printf("Entrez l'abscisse x:");
        scanf("%d",&position_x);
        printf("Entrez l'abscisse y:");
        scanf("%d",&position_y);
        Position position=creerPosition(position_x,position_y);
      } /* Condition d'arrêt: Position_valide(position) == true */
      ajouter_Position(bateau, position); // On peut ajouter la position créee car Position_valide(position) == true
      message_ajout_position();

    } /* END FOR2 */
    ajouterBateau(bateau, EnsBJ2);
    message_ajout_bateau();
  } /* END FOR1 */

  printf("La flotte du joueur J2 a bien été créee, c'est parti !\n");

  /*Initialisation des joueurs J1 et J2 avec leur ensemble de bateaux */
  Joueur JoueurJ1 = creerJoueur(EnsBJ1,1);
  Joueur JoueurJ2 = creerJoueur(EnsBJ2,2);
  /*Initialisation de l'ensemble de joueurs*/
  EnsJoueurs EJ = creer_EnsJoueurs();
  ajouterJoueur(JoueurJ1, EJ);
  ajouterJoueur(JoueurJ2, EJ);

return EJ;
}

Position demander_tir(){ /* Interface de saisie du tir*/
  printf("Entrez l'abscisse du tir:\n");
  int x = 0;
  scanf("%d",&x);
  printf("Entrez l'ordonnée du tir:\n");
  int y = 0;
  scanf("%d",&y);
  Position recup_tir_joueur = creerPosition(x,y);
  return recup_tir_joueur;

}

void message_a_leau(){
  printf("A l'eau ! :(\n");
}

void message_touche(){
  printf("Touché !! :D\n");
}

void message_en_vue(){
  printf("Bateau en vue ! :0\n");
}

void resultat_partie(int winner, int loser){

  printf("Le joueur J%d a gagné, on t'offre le droit de coder les ARN :D\n", winner);
  printf("Le joueur J%d a perdu, si tu nous donnes 20EUR tu peux gagner ;)\n", loser);
}



/* PROG PRINCIPAL */
int main(){

      EnsJoueurs EnsJ = init_data(); /* Initialisation des données nécessaire à la partie */
      Partie partie_bataille_navale=creerPartie(EnsJ,0); /* Creation de la partie */

      /* DEBUT DE LA PARTIE */
      while(!partie_terminee(partie_bataille_navale)){
        /*Determination du joueur actif */
        Joueur joueur_Actif = joueur_actif(partie_bataille_navale);
        Joueur joueur_Inactif = joueur_inactif(partie_bataille_navale);
        /* Informations sur le joueur actif */
        description_Joueur_Actif(joueur_Actif);

        /*Demander de tir*/
        Position tir_joueur_actif = demander_tir(); /* interface graphique */
        int resTir = verif_tir(tir_joueur_actif, joueur_Inactif);
        /*le tir est a l'eau, on change de joueur*/
        if(est_a_leau(resTir)){
          /* Message au joueur */
          message_a_leau();
          changer_tour(partie_bataille_navale); /*on passe au joueur suivant*/
        }
        /*on a touché un bateau*/
        else if(est_touche(resTir)){
          /*on supprime ce morceau*/
          supprimer_Position(joueur_Inactif, tir_joueur_actif);
          /* Message au joueur */
          message_touche();
          changer_tour(partie_bataille_navale);
        }
        /* bateau en vue */
        else if(est_en_vue(resTir)){
          /* Message au joueur */
          message_en_vue();
          /* on change de tour, on passe au joueur suivant */
          changer_tour(partie_bataille_navale);

        }

      } /* Condition d'arrêt de la partie: partie_terminee(partie_bataille_navale) == TRUE */
      /* FIN DE LA PARTIE */
      resultat_partie(gagnant(partie_bataille_navale), perdant(partie_bataille_navale)); /* Donne les résultats de la partie, le gagnant, le perdant, interface graphique*/

      return 0;

}
