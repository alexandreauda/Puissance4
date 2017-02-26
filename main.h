#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

/*** Inclusion des bibliothèques ***/
#include<stdio.h>    /*Inclusion de la bibliothèque d'en-tete standard d'entree-sortie*/
#include<stdlib.h>   /*Inclusion de la bibliothèque de fonctions d'allocution memoire, les fonction gérant l'aléatoire,...*/
#include<libsx.h>    /*Inclusion de la bibliothèque graphique libsx*/
#include<time.h>     /*Inclusion de la bibliothèque nécessaire pour les fonctions gérant l'aléatoire*/
#include<unistd.h>




/******** Animation *******/
#define MAXANIML 10
#define MAXANIMH 20
#define DIMDRAWANIM 10
Widget grilleAnim[MAXANIMH][MAXANIML];
/***************************/



#define NBLIGNE 6
#define NBCOLONNE 7
#define NOBODY 0
#define PLAYER 1
#define AI 2
#define winLength 4



#include "math.h"

/**
     * ie on fait un arbre à 8 niveaux
     */
#define MAX_DEPTH 8

/**
     * Le score quand on
     * win.
     */
#define WIN_REVENUE 1

/**
     * Le score quand on
     * perd.
     */
#define LOSE_REVENUE -1

/**
     * Le score quand on n'en sait rien
     */
#define UNCERTAIN_REVENUE 0

#define MIN_VALUE -pow(2,31)


#define MAX_VALUE pow(2,31)-1

/*#define LEVELOFDIFFICULT 1*/

/*Pour la 1 ère fenêtre*/
Widget w_entryLevel;
Widget w_entryNomJoueur;


char *nomDuJoueur;
char *nom2;
char *level;
int grille[NBLIGNE][NBCOLONNE];
int remplissage[7];
int comptCoupJoueur;
int gagneOuPas;
int quiCommence;/*1 si je commence et 0 si l'adversaire commence*/



int metier[6][7];
int recommencer;

void init_metier();
void aide(Widget w,void *d);
void load(Widget w1, void *data);
void save(Widget w, void *data);
void quit(Widget w, void *data);
void real_quit(Widget w, void *data);
char *phraseAuPerdant();
char *phraseAuGagnant();
char *phrasePartieNul();
void afficheGrille(Widget w,int width,int height,void *date);
int action_IA_Basic();
void action_joueur(int colonne);
void button1(Widget w);
void button2(Widget w);
void button3(Widget w);
void button4(Widget w);
void button5(Widget w);
void button6(Widget w);
void button7(Widget w);
void init_display(int argc, char **argv);

int dansGrille(int x,int y);
 int jouable(int x);
 int saisircoup();
  void afficherGrille();
  int estRemplieOuNon();
  int adjacent(int c, int l,int dirV, int dirH);
  int partieEstGagneeOuPas(int c,int l);
  int rand_a_b(int a, int b);
  char *NomIA();
  void jouerPartie(int argc , char **argv,void *d,int nbligne, int nbcolonne);
void initialisergrille();
void initialiserRemplissage();
int saisirCoupLibsx(int choixColonne);
double maxs( double a, double b);
double mins( double a, double b);
int isValidMove(int column);
int makeMove(int column, int player);
int undoMove(int column, int player);
int makeMovePlayer(int column);
int makeMoveAI(int column);
int undoMovePlayer(int column);
int undoMoveAI(int column);
int getWinner();
int isBoardFull();
void jouerPartieIA();

void AnimationFantome(Widget w,int width, int height,Widget *data);
void grilleAnimation();






#endif // MAIN_H_INCLUDED
