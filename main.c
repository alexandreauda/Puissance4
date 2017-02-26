/*********************************  Projet interface libsx  *****************************************/

/*** Inclusion des bibliothèques ***/
#include "main.h"

/****************************************************************************************/


double maxs(double a, double b){
if(a<b){
return b;
}
else{
    return a;
}
}

double mins(double a, double b){
if(a>b){
return b;
}
else{
    return a;
}
}








    /********************************************************************/
/*BOARD*/

    /**
     *
     * @param column
     *            Nombre de la colonne à verifier.
     *            Index commence a 0
     * @return True si un joueur peut jouer dans la colonne
     *
     */
int isValidMove(int column){

        return remplissage[column] < (NBLIGNE);

    }


int makeMove(int column, int player) {
        if (remplissage[column] < NBLIGNE) {
            int sign;
            if(player==1){
                sign=PLAYER;
            }
            else{
                sign=AI;
            }
grille[column][remplissage[column]++] = sign;
            return 1;
        }
        return 0;
    }



int undoMove(int column, int player) {
        if (remplissage[column] > 0) {
            int sign;
            if(player==1){
                sign=PLAYER;
            }
            else{
                sign=AI;
            }
            if (grille[column][remplissage[column]-1] == sign) {
                grille[column][remplissage[column]-1] =NOBODY;
                (remplissage[column])--;
                return 1;
            }
        }
        return 0;
    }


    /**
     * Met le jeton du joueur dans la colonne donné.
     *
     * @param column
     * @return True si action valide, false
     *         sinon.
     */
    int makeMovePlayer(int column) {
        return makeMove(column, 1);
    }

/**
     * Met le jeton de l'IA dans la colonne donné.
     *
     * @param column
     * @return
     */
    int makeMoveAI(int column) {
        return makeMove(column, 0);
    }



    /**
     *
     * @param column
     * @return True si action a reussit
     */
    int undoMovePlayer(int column) {
        return undoMove(column, 1);
    }

    /**
     *
     * @param column
     * @return True si action a reussit
     */
    int undoMoveAI(int column) {
        return undoMove(column, 0);
    }

    /**
     * Retourne le gagnant de la grille courante
     * state.
     *
     * @return Board.NOBODY si il n'ya pas de gagnant.
     *         Board.AI if l' AI est le gagnant.
     *         Board.PLAYER si le joueur est le
     *         winner.
     */
    int getWinner() {
        int x;
        int y;
        int o;
        for (x = 0; x < NBCOLONNE; x++) {
            for (y = 0; y <=  (NBLIGNE)-(winLength); y++) {
                int playerWin = 1;
                int aiWin = 1;
                for (o = 0; o < winLength; o++) {
                        if(playerWin ==PLAYER && grille[x][y + o]!=PLAYER){
                            playerWin = 0;
                    }
                    if (aiWin==1 && grille[x][y + o] != AI) {
                        aiWin = 0;
                    }
                }
                if (playerWin==1) {
                    return PLAYER;
                } else if (aiWin==1) {
                    return AI;
                }
            }
        }

        for (y = 0; y < NBLIGNE; y++) {
            for (x = 0; x <= (NBCOLONNE)-(winLength); x++) {
                int playerWin = 1;
                int aiWin = 1;
                for (o = 0; o < winLength; o++) {
                    if (playerWin==1 && grille[x + o][y] != PLAYER) {
                        playerWin = 0;
                    }
                    if (aiWin==1 && grille[x + o][y] != AI) {
                        aiWin = 0;
                    }
                }
                if (playerWin==1) {
                    return PLAYER;
                } else if (aiWin==1) {
                    return AI;
                }

    }
        }

        for (x = 0; x <= (NBLIGNE)-(winLength); x++) {
            for (y = 0; y <= (NBLIGNE)-(winLength); y++) {
            int playerWin = 1;
                int aiWin = 1;
                for (o = 0; o < winLength; o++) {
                    if (playerWin==1 && grille[x + o][y + o] != PLAYER) {
                        playerWin = 0;
                    }
                    if (aiWin==1 && grille[x + o][y + o] != AI) {
                        aiWin = 0;
                    }
                }
                if (playerWin==1) {
                    return PLAYER;
                } else if (aiWin==1) {
                    return AI;
                }
            }
        }

        for (x = NBCOLONNE - 1; x >= winLength - 1; x--) {
            for (y = 0; y <= (NBLIGNE)-(winLength); y++) {
                int playerWin = 1;
                int aiWin = 1;
                for (o = 0; o < winLength; o++) {
                    if (playerWin==1 && grille[x - o][y + o] != PLAYER) {
                        playerWin = 0;
                    }
                    if (aiWin==1 && grille[x - o][y + o] != AI) {
                        aiWin = 0;
                    }
                }
                if (playerWin==1) {
                    return PLAYER;
                } else if (aiWin==1) {
                    return AI;
                }
            }
        }

        return NOBODY;
    }



/**
     * Retourne 1 si il y a un winner dans la grille courante
     * state and 0 sinon
     *
     * @return Returns 1 si il y a un winner dans la grille courante
     * state and 0 sinon
     */
int hasWinner() {

        return getWinner() != NOBODY;

    }

    /**
     * Retourne si le joueur a won.
     *
     * @return
     */
    int playerIsWinner() {

        return getWinner() == PLAYER;

    }

    /**
     * Retourne si la grille est complete et qu'il n'y a pas
     * de gagnant
     *
     * @return
     */
    int isTie() {

        return isBoardFull() && getWinner() == NOBODY;

    }


int isBoardFull() {
        int emptyColumnFound = 0;
        int x;
        for (x = 0; x < NBCOLONNE; x++) {
            if ((remplissage[x]) < NBLIGNE) {
                emptyColumnFound = 1;
                break;
            }
        }
        if(emptyColumnFound==0){
        emptyColumnFound=1;
        return emptyColumnFound;
        }
        else{
        emptyColumnFound=0;
            return emptyColumnFound;
        }
    }




     void afficherGrilleIA() {
        int x;
        int y;
        for (x = 0; x < NBCOLONNE; x++) {
            printf("%d ",(x + 1));
        }
        printf("\n");
        for (y = (NBLIGNE) - 1; y >= 0; y--) {
            for (x = 0; x < (NBCOLONNE); x++) {
                if (grille[x][y] == PLAYER) {
                    printf("X ");
                } else if (grille[x][y] == AI) {
                    printf("O ");
                } else {
                    printf(". ");
                }
            }
             printf("\n");
        }
    }



/***********************************************************************************/



        void initialisergrille(){
        int i;
        int j;
        for (i=0;i<6;i++)
         {
            for (j=0;j<7;j++)
            {
                 grille[i][j]=' '; /* on parcours toute la grille et on y met des " "*/
            }
         }
        }

        void initialiserRemplissage(){
        int j;
        for(j=0;j<7;j++)/*pour chaque colonne de la grille*/
            {
         remplissage[j]=0;/* on initialise remplissage à zéro, car 0 est sa premiere valeur ie remplissage est un tableau qui indique le nombre de jeton par colonne. Or, au début, il y a zéro jetons dans chaque colonne */
            }
        }

    /*la fonction prend 2 entiers x et y et renvoie vrai s'il existe une case de coordonnées(x,y)dans grille.*/
    int dansGrille(int x,int y)
      {
          if ((x>=0)&&(x<=5)&&(y>=0)&&(y<=6)){/* x appartient aux six cases d'une colone 0~5
                                               * y appartient aux septs cases d'une ligne 0~6*/
           return 1;                          /*on retourne vrai*/
           }
          else {
                return 0;                      /*on retourne faux*/
          }
      }
     /* fonction qui prend en argument un nombre corespondant à un numéro de colonne x, et qui renvoie vrai s'il est possible
      de poser un jeton dans la colonne x, j'utilise un tableau sur cette fonction*/
    int jouable(int x)
      {

        if (x>=0 && (x<7) &&remplissage[x]>=0 && remplissage[x]<6)
        return 1;
        else return 0;

      }
      /*fonction saisir coup: elle invite à rentrer un numéro de colones et elle teste si la colonne rentrée est jouable ou pas. Si elle est jouable, elle
      retourne le numéro de la colonne saisi.Si la colonne saisi n'est pas jouable (au sens de la fonction jouable implémentée ci-dessus), alors on repose la question
      en invitant à renter une colonne valide.*/
    int saisircoup()
      {
        int z;           /* z colonne*/

            do{

              printf("\t      rentrez une colonne entre <0-6>:\n\t essayez une autre si celle-ci est remplie!\n"); /*on invite l'utilisateur à renter un nombre associé à la colonne qu'il souhaite jouer*/
              scanf("%d",&z); /*on stock le nombre saisi par l'utilisateur dans la variable z*/
              if (jouable(z)==1){/*Si la colonne saisie par l'utilisateur est jouable,(au sens de la fonction jouable implémentée ci-dessus), alors...*/
              return z; /*on retourne le numéro de la colonne saisi*/
              }

              }
            while(jouable(z)!=1); /*tant que la colonne saisie n'est pas jouable, on repose la question*/
return z;
      }

      int saisirCoupLibsx(int choixColonne){
      int z;           /* z colonne*/

             z=choixColonne;
             if (jouable(z)==1){/*Si la colonne saisie par l'utilisateur est jouable,(au sens de la fonction jouable implémentée ci-dessus), alors...*/
              return z; /*on retourne le numéro de la colonne saisi*/
              }
              else{
              return 0;
              }

              }



      /**********************************************************************************************************************************************************************
     **********PARTIE GRAPHIQUE EN CONSOLE*********/

      /*Permet d'afficher la grille*/
      void afficherGrille()
      {
        int i,j;
        printf("\t\t*********Puissance4*******\n\n\n\n");


        for(i=0;i<6;i++){/*permet d'afficher les lignes */
        printf("\t\t\t");
        printf("+-+-+-+-+-+-+-+"); /*on print les lignes*/

        printf("\n");
        printf("\t\t\t");
        for (j=0;j<7;j++){
        printf("|%c",grille[5-i][j]);
        }
        printf("|%d \n",i);/* affiche les numéros horizontalement*/
                        }
        if (i==6){
        printf("\t\t\t");}
        printf("+-+-+-+-+-+-+-+");
        printf("\n");
        printf("\t\t\t");
        for(j=0;j<=6;j++)
                         {
        printf(" %d",j);/* affiche les numéro verticalement*/
                         }
        printf("\n\n\t\t");
    }
/******************************************************************************************************************************************************************
*/
    int estRemplieOuNon()
    {
         int x,comp=0;
         for(x=0;x<=6;x++)/*pour chaque colonne...*/
         {
         if(jouable(x)) /*on vérifie ue la colonne en question est jouable*/
          {
               comp=comp+1; /*si la colonne est jouable, on fait comp+1 donc comp!=0 par la suite (cela signifie que si une colonne est joouable, alors la grille n'est pas remplie)*/
          }
         }
         if (comp==0){   /*si comp ==0 ie si aucune colonne n'est jouable,...*/
          return 1; /*...cela signifie que la grille est remplie et donc on renvoie 1 pour dire que la grille est remplie*/
          }

         else{ /*sinon, si comp!=0, cela signifie que certaines colonnes sont jouables et donc cela signifie que la grille est totalement remplie*/
            return 0; /*on retourne 0 pour dire que la grille n'est pas remplie*/
         }

    }

/*Cette fonction prend en paramètre un numéro de colonne et de ligne qui sera le point de départ de la recherche et 2 int qui demande la direction dans lequel on veut chercher
dirV pour la direction verticale et dirH pour la direction horizontale. dirV=0:recherche horizontale uniquement. dirV=1;recherche vers le bas. dirV=-1:recherche vers le haut.
dirH=0:recherche verticale uniquement. dirH=1;recherche vers la droite. dirH=-1:recherche vers la gauche.
elle retourne le nombre de jetons que l'on a trouvé en faisant la recherche comme spécifiée en paramètre */
    int adjacent(int c, int l,int dirV, int dirH)
    {
        int n=0; /*n est la variable qui permet de stocker le nombre de jeton adjacent selon la direction spécifié par les arguments en paramètre*/

         if(dirV==0)
            {
            if(dirH==1)
               {
               while((grille[l][c])==(grille[l][c+1])&&(grille[l][c]!=' ')) /*on fait une recherche horizontale uniquement et vers la droite et tant que l'on trouve des jetons on incrémente n qui stock le nombre de jeton adjacent selon la direction indiquée*/
                  {
                  n++; /*on incrémente le nombre de jeton adjacents*/
                  c++; /*pour aller vers la droite, il faut incrémenter le numéro de colonne*/
                  }
               }
             else if(dirH==-1)
               {
               while((grille[l][c])==(grille[l][c-1])&&(grille[l][c]!=' '))/*on fait une recherche horizontale uniquement et vers la gauche et tant que l'on trouve des jetons on incrémente n qui stock le nombre de jeton adjacent selon la direction indiquée*/

                  {
                  n++;
                  c--; /*pour aller vers la gauche, il faut décrémenter le numéro de colonne*/
                  }
               }
            }
         if(dirV==1)
            {
            if(dirH==0)
               {
               while((grille[l][c])==(grille[l+1][c])&&(grille[l][c]!=' '))/*on fait une recherche verticale uniquement et vers le bas et tant que l'on trouve des jetons on incrémente n qui stock le nombre de jeton adjacent selon la direction indiquée*/
                  {
                  n++;/*on incrémente le nombre de jeton adjacents*/
                  l++;  /*pour aller vers le bas, il faut incrémenter le numéro de ligne*/
                  }
               }
            else if(dirH==1)
               {
               while((grille[l][c])==(grille[l+1][c+1])&&(grille[l][c]!=' '))/*on fait une recherche verticale vers le bas et la droite(on va donc en diagonale) et tant que l'on trouve des jetons on incrémente n qui stock le nombre de jeton adjacent selon la direction indiquée*/

                  {
                  n++; /*on incrémente le nombre de jeton adjacents*/
                  c++;  /*pour aller vers la droite, il faut incrémenter le numéro de colonne*/
                  l++;  /*pour aller vers le bas, il faut incrémenter le numéro de ligne*/
                  }
               }
               else if(dirH==-1)
                  {
                  while((grille[l][c])==(grille[l+1][c-1])&&(grille[l][c]!=' '))/*on fait une recherche verticale vers le bas et vers la gauche(on va donc en diagonale) tant que l'on trouve des jetons on incrémente n qui stock le nombre de jeton adjacent selon la direction indiquée*/
                     {
                     n++; /*on incrémente le nombre de jeton adjacents*/
                     c--; /*pour aller vers la gauche, il faut décrémenter le numéro de colonne*/
                     l++; /*pour aller vers le bas, il faut incrémenter le numéro de ligne*/
                     }
                  }
            }
         if(dirV==-1)
            {
            if(dirH==0)
               {
               while((grille[l][c])==(grille[l-1][c])&&(grille[l][c]!=' ')) /*on fait une recherche verticale uniquement vers le haut tant que l'on trouve des jetons on incrémente n qui stock le nombre de jeton adjacent selon la direction indiquée*/
                  {
                  n++; /*on incrémente le nombre de jeton adjacents*/
                  l--;  /*pour aller vers le haut, il faut décrémenter le numéro de ligne*/
                  }
               }
            else if(dirH==-1)
                  {
                  while((grille[l][c])==(grille[l-1][c-1])&&(grille[l][c]!=' ')) /*on fait une recherche verticale vers le haut et vers la gauche(on va donc en diagonale) tant que l'on trouve des jetons on incrémente n qui stock le nombre de jeton adjacent selon la direction indiquée*/

                     {
                     n++;  /*on incrémente le nombre de jeton adjacents*/
                     c--; /*pour aller vers la droite, il faut décrémenter le numéro de colonne*/
                     l--;  /*pour aller vers le haut, il faut décrémenter le numéro de ligne*/
                     }
                  }
                  else if(dirH==1)
                  {
                  while((grille[l][c])==(grille[l-1][c+1])&&(grille[l][c]!=' ')) /*on fait une recherche verticale vers le haut et vers la droite(on va donc en diagonale) tant que l'on trouve des jetons on incrémente n qui stock le nombre de jeton adjacent selon la direction indiquée*/

                     {
                     n++; /*on incrémente le nombre de jeton adjacents*/
                     c++;  /*pour aller vers la droite, il faut décrémenter le numéro de colonne*/
                     l--;  /*pour aller vers le haut, il faut décrémenter le numéro de ligne*/
                     }
                  }
            }
         return(n); /* on renvoie le nombre de jetons ajacents dans la direction spécifiée en paramètre*/

    }

/*Fonction prenant en paramètre un numéro de ligne et de colonne et retourne vrai(ie 1) si la partie est gagnée (à savoir s'il y a 4 jetons en lignes. Retourne faux (ie 0) sinon.*/
    int partieEstGagneeOuPas(int c,int l)
    {
      if  ((adjacent(c,l,0,1)+adjacent(c,l,0,-1))>=3 ||
      (adjacent(c,l,1,0)+adjacent(c,l,-1,0))>=3 ||
      (adjacent(c,l,1,1)+adjacent(c,l,-1,-1))>=3 ||
      (adjacent(c,l,1,-1) + adjacent(c,l,-1,1)>=3))
      {return 1;}
      else{ return 0;}

    }









/***********************************************************************************************************/
/*IA*/
/* On suppose a<b, permet de générer des nombres aléatoires entre a inclu en b exclu*/
int rand_a_b(int a, int b){
    srand(time(NULL)); /* initialisation de rand*/
    return rand()%(b-a) +a;
}

char *NomIA(){
    char *nom2[11]={"deep blue","skynet","ultron","matrix","Multivac","The Engine","ODIN","Puisssance4++","The Ox","HAL 9000","Jarvis"};
    int nombre_aleatoire;
    nombre_aleatoire=rand_a_b(0,11);
    switch(nombre_aleatoire){
    case 0:return nom2[0];
           break;

    case 1:return nom2[1];
           break;

    case 2:return nom2[2];
           break;

    case 3:return nom2[3];
           break;

    case 4:return nom2[4];
           break;

    case 5:return nom2[5];
           break;

    case 6:return nom2[6];
           break;

    case 7:return nom2[7];
           break;

    case 8:return nom2[8];
           break;

    case 9:return nom2[9];
           break;

    case 10:return nom2[10];
           break;

     case 11:return nom2[11];
           break;

     default:return "IA non Identifiee";break;}
}



    double alphabeta(int depth, double alpha, double beta, int maximizingPlayer) {
        int hasWinners = hasWinner();  /*hasWinner est un boolean qui dit si le tableau est gagnant.*/
        /* All these conditions lead to a
         termination of the recursion*/
        if (depth == 0 || hasWinners==1) { /*si la profondeur est null ou qu'il y a un gagnant...*/
            double score = 0;
            if (hasWinners==1) { /*S'il y a un gagnant dans la grille, ...*/
                /*on met le score à -1 si l'IA a perdu et le score à +1 si l'IA a gagné.*/
                score = (playerIsWinner()==1) ? LOSE_REVENUE : WIN_REVENUE;
            } else { /*Si il n'y a pas de gagnant dans la grille...*/
                score = UNCERTAIN_REVENUE; /*le score est incertain.*/
            }

            return score/(MAX_DEPTH - depth + 1);
        }

        if (maximizingPlayer==1) { /*si il s'agit du MaximazerPlayer ie l'IA (ie s'il s'agit des caré dans le tutoriel sur alpha-béta)*/
                int column;
            for (column = 0; column < NBCOLONNE; column++) { /*pour chaque colonne...*/
                if (isValidMove(column)==1) { /*si la colonne en question n'est pas remplie...*/
                    makeMoveAI(column); /*on joue le coup dans cette colonne*/
                    /*on calcule alpha car les carrés modifient les alphas. (cf tutoriel)*/
                    alpha = maxs(alpha, alphabeta(depth - 1, alpha, beta,0)); /*récursion: l'apha du carré vaut le max entre son l'apha actuel et le béta du niveau en dessous.(cf tutoriel si besoin est)*/
                                                                                      /*Or pour avoir le béta du niveau en dessous, il suffit de faire alphaBéta du niveau d'en dessous car au niveau en dessous,
                                                                                      il s'agit d'un cercle, donc en faisant alphaBéta à partir de ce cercle, on va modifié la valeur du béta de ce cercle car un cercle va modifié les bétas.
                                                                                      Ainsi alpha béta du niveau d'en dessous va permettre de trouver le béta du niveau en dessous, ce qui va nous permettre de faire le calcul.
                                                                                      Imaginons un arbre à 3 niveau avec un carré pour racine. Alors On veut avoir le alpha de la racine. Cela va donc executer ce block qui va demander de calculer le alpha béta du niveau en dessous.
                    or le niveau d'en dessous, ce sont des cercle donc c'est le block d'en dessous qui est exécuté, mais le block en dessous veut caluler le alpha d'en desssous et pour cela, il appel le alpha béta du niveau d'en dessous(le troisiéme niveau).
                    mais ce troisième niveau ce sont des carrés et cette fois, la profondeur est =0, donc on effectue le block précédent qui retourne la fonction d'évaluation ce qui met à jour le alpha du niveau 3 et on va pouvoir remonter par récursion pour trouver le apha du root.*/
                    undoMoveAI(column);/*on retire le coup que l'on a effectué.*/
                    if (beta <= alpha) {/*si béta <=alpha, alors on coupe la recherche*/
                        break;
                    }
                }
            }
            return alpha;
        } else { /*si il ne s'agit pas du MaximazerPlayer ie le joueur (ie s'il s'agit des rond dans le tutoriel sur alpha-béta)*/
             int column;
            for (column = 0; column < NBCOLONNE; column++) { /*pour chaque colonne...*/
                if (isValidMove(column)==1) {  /*si la colonne en question n'est pas remplie...*/
                    makeMovePlayer(column); /*on joue le coup dans cette colonne*/
                    beta = mins(beta, alphabeta(depth - 1, alpha, beta, 1)); /*idem que ci-dessus mais c'est l'inverse.*/
                    undoMovePlayer(column);
                    if (beta <= alpha) { /*si béta <=alpha, alors on coupe la recherche*/
                        break;
                    }
                }
            }
            return beta;
        }
    }

double moveValue(int column) {
        /* Pour determiner la valeur de l'action, faire
         un deplacement, estimer le coup, l'enlever et
         repeter l'operation.*/
        makeMoveAI(column); /*on fait le mouvement dans la colonne indiqué
        On calcule la valeur du coup "à terme" ie si le coup sera avantageux pour le futur grace à apha-béta*/
        double val=0;
        val =alphabeta(MAX_DEPTH, MIN_VALUE, MAX_VALUE, 0); /*MIN_VALUE représente -l'infinie et MAX_VALUE représente +l'infini. De plus, comme on a jouer, le coup à évaluer est un cercle donc ce n'est pas le maximizingPlayer: false.
                                                            l'alpha-béta va donc évaluer le béta du coup (qui est un cercle) et ce béta sera donc la valeur de ce cercle (car il s'agit d'un cercle) et donc on détermine la valeur du coup.*/
        undoMoveAI(column); /*on enlève le coup que l'on a fait.*/
        return val; /*on retourne la valeur du coup effectuer. (Bien sur, à terme, il faut faire tout les coup que l'on peut faire dans les colonne; stocker les valeurs des coup et prendre le coup qui possède la plus grande valeur).*/
    }


/**
     * Gere les tours.
     *
     */
    int makeTurn() { /*faire jouer le tour de l'IA.*/
        double maxValue = 2.0 * MIN_VALUE; /*minValue représente -l'infini*/
        int move = 0;

        int column=0;
        double value;
        for(column = 0; column < NBCOLONNE; column++) { /*pour chaque colonne...*/
            if (isValidMove(column)==1) { /*si le coup dans la colonne est autorisé...*/
                /* Compare le score de ce
                 coup particulier avec the
                 coups max*/
                value = moveValue(column); /*on détermine la valeur du coup(à terme bien sur) et on stock la valeur dans value*/
                if (value > maxValue) { /*si la valeur du coup est plus élevé que la valeur maximal des précédents coup, alors...*/
                    maxValue = value; /*la valeur du coup est stocker dans maxValue qui est une variable destiné à avoir la valeur du coup la plus grande.*/
                    move = column; /*le mouvement sera fait dans la colonne où la valeur du coup dans cette colonne est la plus grande.*/
                    if (value == WIN_REVENUE) { /*si la valeur représente un coup gagnant, on arrete de chercher dans les autres colonnes*/
                        break;
                    }
                }
            }
        }
        /* Make the move*/
        makeMoveAI(move); /*on effectue le mouvement dans la colonne où la valeur du coup est la plus grande.*/
        return move; /*on retourne la valeur de la colonne où il faut jouer.*/
    }




/***********************************************************************************************************/

  void jouerPartieIA(){
   printf("Welcome to 4 wins!\n");
printf("------------------\n");


printf("The game starts now \n");
int turn=rand_a_b(0,2);
if(turn){
printf("You are first to go! \n");
}
else {
printf("Your opponent has the first move! \n"); /*si ce n'est pas le joueur qui commence, alors on affiche le fait que l'IA comence.*/
        }
int column = 0; /*on initialise une variable colomn à 0*/
        while (hasWinner()!=1 && isTie()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
            afficherGrilleIA();
            if (turn) { /*si c'est au joueur de jouer...*/
                do {
                    printf("In which column do you want to place your stone?"); /*on demande au joueur de placer son jeton dans une colonne*/
                    column = saisircoup() - 1; /*on rentre la colomn que l'on veut (-1 car on commence la grille à 0)*/
                    if (isValidMove(column)!=1) { /*si la colonne que l'on a choisit ne peut être choisit...*/
                        printf("You cannot place your stone in that column!"); /*on affiche un message l'indiquant*/
                    }
                } while (isValidMove(column)!=1); /*tant que l'on ne choisit pas une colomn valide*/
                makeMovePlayer(column); /*on effectue le mouvement dans la colonne valide que l'on a choisit*/
            } else { /*si ce n'est pas au tour du joueur de jouer (si c'est au tour de l'IA).*/
                int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
                printf("Your opponent placed in column %d\n",(aiColumn + 1)); /*on affiche la colonne qu'a choisit l'IA*/
            }
            /*on change de tour*/
            if(turn==0){
                turn=1;
            }
            else{
                turn=0;
            }

        }

        afficherGrilleIA();
        if (playerIsWinner()) { /*si le joueur gagne...*/
            printf("You win! Congratulations!"); /*on affiche un message de félicitation*/
        } else if (isTie()) { /*si il s'agit d'un égalité...*/
            printf("It's a tie, I think that is the best you can do!"); /*on affiche un message informant de l'égalité*/
        } else { /*sinon, c'est que le joueur a perdu*/
            printf("You lose! Try again!"); /*on affiche un message indiquant que le joueur a perdu*/
        }
    }


/************************************************************************************/
void AnimationFantome(Widget w,int width, int height,Widget *data){
SetFgColor(w,WHITE);
SetBorderColor(w,WHITE);
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
int a=4;
int b=2;
int c=2;
int d=2;
int e=2;
int f=2;
int g=4;

int colors=RED;
int colors2=BLUE;

for(a=4;a<7;a++){
SetFgColor(grilleAnim[5][a],colors);
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
}  /*pixels de de la colonne 0*/

SetFgColor(grilleAnim[6][3],colors);   /*pixels de de la colonne 1*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
SetFgColor(grilleAnim[6][4],colors);   /*pixels de de la colonne 1*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);

SetFgColor(grilleAnim[7][0],colors);   /*pixels de de la colonne 2*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
for(b=2;b<7;b++){
SetFgColor(grilleAnim[7][b],colors);
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);}  /*pixels de de la colonne 2*/

SetFgColor(grilleAnim[8][1],colors);   /*pixels de de la colonne 3*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
SetFgColor(grilleAnim[8][2],colors);   /*pixels de de la colonne 3*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
SetFgColor(grilleAnim[8][4],colors);   /*pixels de de la colonne 3*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
SetFgColor(grilleAnim[8][3],colors2);  /*pixels de de la colonne 3 (yeux)*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
SetFgColor(grilleAnim[8][5],colors);   /*pixels de de la colonne 3*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
SetFgColor(grilleAnim[8][7],colors);   /*pixels de de la colonne 3*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);

for(c=2;c<6;c++){
SetFgColor(grilleAnim[9][c],colors);
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);}  /*pixels de de la colonne 4*/
SetFgColor(grilleAnim[9][7],colors);   /*pixels de de la colonne 4*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);

for(d=2;d<6;d++){
SetFgColor(grilleAnim[10][d],colors);
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);}  /*pixels de de la colonne 5*/

for(e=2;e<6;e++){
SetFgColor(grilleAnim[11][e],colors);
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);}  /*pixels de de la colonne 6*/
SetFgColor(grilleAnim[11][7],colors);   /*pixels de de la colonne 6*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);

SetFgColor(grilleAnim[12][1],colors);   /*pixels de de la colonne 7*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
SetFgColor(grilleAnim[12][2],colors);   /*pixels de de la colonne 7*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
SetFgColor(grilleAnim[12][3],colors2);  /*pixels de de la colonne 7 (yeux)*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
SetFgColor(grilleAnim[12][4],colors);   /*pixels de de la colonne 7*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
SetFgColor(grilleAnim[12][5],colors);   /*pixels de de la colonne 7*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
SetFgColor(grilleAnim[12][7],colors);   /*pixels de de la colonne 7*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);

SetFgColor(grilleAnim[13][0],colors);   /*pixels de de la colonne 8*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
for(f=2;f<7;f++){
SetFgColor(grilleAnim[13][f],colors);
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);}   /*pixels de de la colonne 8*/

SetFgColor(grilleAnim[14][3],colors);   /*pixels de de la colonne 9*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);
SetFgColor(grilleAnim[14][4],colors);   /*pixels de de la colonne 9*/
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);

for(g=4;g<7;g++){
SetFgColor(grilleAnim[15][g],colors);
DrawFilledBox(0,0,DIMDRAWANIM+10,DIMDRAWANIM+10);}  /*pixels de de la colonne 10*/

}

/*********************************************************************/


/***********************  Grille Animation  **********************************************/

void grilleAnimation(){
int i, j;
grilleAnim[0][0]=MakeDrawArea(DIMDRAWANIM,DIMDRAWANIM,AnimationFantome, NULL);
for(j=1; j<MAXANIMH; j++){
grilleAnim[j][0]=MakeDrawArea(DIMDRAWANIM,DIMDRAWANIM,AnimationFantome, NULL);
SetWidgetPos(grilleAnim[j][0], PLACE_RIGHT, grilleAnim[j-1][0], NO_CARE, NULL);
}
for(i=1; i<MAXANIML; i++){
grilleAnim[0][i]=MakeDrawArea(DIMDRAWANIM,DIMDRAWANIM,AnimationFantome, NULL);
SetWidgetPos(grilleAnim[0][i], PLACE_UNDER, grilleAnim[0][i-1], NO_CARE, NULL);
}
for(i=1;i<MAXANIML;i++){
for(j=1;j<MAXANIMH;j++){
grilleAnim[j][i]=MakeDrawArea(DIMDRAWANIM,DIMDRAWANIM,AnimationFantome, NULL);
SetWidgetPos(grilleAnim[j][i], PLACE_UNDER, grilleAnim[j-1][i-1], PLACE_RIGHT, grilleAnim[j-1][i-1]);
}
}
}
/*******************************************************************************/




/******************************************************1 ère fenêtre*****************************************************************************/


void stringEntryfunc(Widget w, char *string, void *data)
     {

     }


void quitfenetre1(Widget w, void *data)
{
nomDuJoueur=strdup(GetStringEntry(w_entryNomJoueur));
level=strdup(GetStringEntry(w_entryLevel));
  CloseWindow();
  ExitMainLoop();
}

void real_quitfenetre1(Widget w, void *data)
{
  exit(0);
}

void toggle1Act(Widget w, void *data)
     {
quiCommence=1; printf("%d\n",quiCommence);
     }

     void toggle2Act(Widget w, void *data)
     {
quiCommence=0; printf("%d\n",quiCommence);
     }



/*******************************************************Fenetre Principale**********************************************************************/

/*Texte contenue dans l'aide*/
char *texte_aide="\t\tBienvenue dans notre jeu de puissance 4!\n\n\nBut:\nLe but du jeu est d'aligner 4 pions sur une grille comportant 6 lignes\net 7 colonnes. Chaque joueur dispose de 21 pions d'une couleur\n(Ici, vos jeton seront des jetons jaunes et votre adversaire aura\ndes jetons rouges). Tour a tour, les deux joueurs placent un pion\ndans la grille, dans la colonne de leur choix, le pion coulisse alors\njusqu'a la position la plus basse possible dans ladite colonne a la \nsuite de quoi c'est a l'adversaire de jouer. Le vainqueur est le joueur\nqui realise le premier un alignement (horizontal, vertical ou diagonal)\nd'au moins quatre pions de sa couleur.\n(pour vous un alignement de quatre jetons jaunes)\nSi, alors que toutes les cases de la grille de jeu sont remplies,\naucun des deux joueurs n'a realise un tel alignement, la partie est\ndeclaree nulle.\n\n\nNote: Le jeu a ete resolu de facon exacte en 1988, par James\nD. Allen, et independamment par Victor Allis1, a quelques jours\nd'intervalle (1er et 16 octobre 1988), avec des calculs informatiques.\nLe premier joueur (celui qui commence la partie) peut s'assurer la\nvictoire s'il joue les coups adequats.\n\n\nLes auteurs: Alexandre AUDA\n\t     Remy AUDA\n\n\n\n\n\nEditeur du jeu <<Puissance 4>>:\nCompagnie Hasbro (tout droit commercial reserve)";
/****************************************/

/*Fonction initialisant la grille à 0*/
void init_metier()
{
  int i,j;
  for(i=0;i<6;i++)      /*Parcourt des lignes*/
    for(j=0;j<7;j++)    /*Parcourt des colonnes*/
      metier[i][j]=0;   /*Chaque element prend la valeur 0*/
}

void init_grille()
{
  int i,j;
  for(i=0;i<6;i++)      /*Parcourt des lignes*/
    for(j=0;j<7;j++)    /*Parcourt des colonnes*/
      grille[i][j]=0;   /*Chaque element prend la valeur 0*/
}

void init_remplissage(){
int i;
for(i=0;i<7;i++){
remplissage[i]=0;
}
}

/***********************************************/
/**CallBack**/
/*function pour l'affichage de l'aide*/
void aide(Widget w,void *d)
{
  Widget f[3];
  FILE *fp=fopen("Aide.txt","r");
  if(fp==NULL)
    {
      fprintf(stderr,"erreur\n");
      exit(0);
    }
  f[0]=MakeWindow("Aide",NULL,1);
  f[2]=MakeTextWidget(texte_aide,0,0,500,500);
  f[1]=MakeButton("Fermer le jeu",quit,d);
  SetWidgetPos(f[1],PLACE_UNDER,f[2],NO_CARE,NULL);
  ShowDisplay();
}

char *switchCoup(int nbcoups){
switch(comptCoupJoueur){
case 4: return "4";break;
case 5: return "5";break;
case 6: return "6";break;
case 7: return "7";break;
case 8: return "8";break;
case 9: return "9";break;
case 10: return "10";break;
case 11: return "11";break;
case 12: return "12";break;
case 13: return "13";break;
case 14: return "14";break;
case 15: return "15";break;
case 16: return "16";break;
case 17: return "17";break;
case 18: return "18";break;
case 19: return "19";break;
case 20: return "20";break;
case 21: return "21";break;


}

}

/**CallBack**/
/*function pour l'affichage des statistiques*/
void statCoupJoueur(Widget w,void *d)
{
 FILE* fichier = NULL;

    fichier = fopen("StatCoupJoueur.txt", "a+");

    if (fichier != NULL)
    {

        /*On l'écrit dans le fichier*/
        fprintf(fichier, "%d\n", comptCoupJoueur);
        fclose(fichier);
        }

    int score[10000] = {0}; /*Tableau des 3 meilleurs scores*/

    fichier = fopen("StatCoupJoueur.txt", "r");

    if (fichier != NULL)
    {
        fscanf(fichier, "%d %d %d %d %d %d %d %d %d %d", &score[0], &score[1], &score[2], &score[3], &score[4], &score[5], &score[6], &score[7], &score[8], &score[9], &score[10]);
        printf("Vous avez gagne les 10 dernières partie en respectivement: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d coups", score[0], score[1], score[2], score[3], score[4], score[5], score[6], score[7], score[8], score[9], score[10]);

        fclose(fichier);
    }
/*char *nbstatcoup= switchCoup(comptCoupJoueur);*/

  Widget f[3];


  f[0]=MakeWindow("Nombre de coups avant la fin de la partie",NULL,1);
  char *reportStat="Cliquer sur le bouton ci-dessous et regarder la console: vous y trouverez\n les statistiques: ";
  f[2]=MakeTextWidget(reportStat,0,0,500,500);
  /*SetTextWidgetText(f[2],"StatCoupJoueur.txt",TRUE);*/
  f[1]=MakeButton("Fermer le jeu",quit,d);
  SetWidgetPos(f[1],PLACE_UNDER,f[2],NO_CARE,NULL);
  ShowDisplay();
}

void load(Widget w1, void *data)
{

}


void save(Widget w, void *data)
{

}


 void quit(Widget w, void *data)
{
  CloseWindow();
  ExitMainLoop();
}

void real_quit(Widget w, void *data)
{
  GetOkay("Merci! Et a bientot!");
  exit(0);
}


void newPartie(Widget w, int argc, char **argv, void *data){
CloseWindow();
ExitMainLoop();
comptCoupJoueur=0;/*le nombre de coup du joueur en début de partie est nul.*/
MakeWindow("Puissance 4 ", NULL, NONEXCLUSIVE_WINDOW);
  init_metier(metier[6][7]);
  init_grille();
  init_remplissage();
  afficherGrilleIA();
  init_display(argc,argv);
  MainLoop();
}

/******************************************************************************/
/*Fonction gérant les messages de fin en cas de partie perdu*/
char *phraseAuPerdant(){
char *phrase[13]={"Vous avez perdu!\n\nIA: C'est tout ce que vous pouvez faire?","Vous avez perdu!\n\nIA: Try again!","Vous avez perdu!\n\nIA: Alors,on a le moral dans les chaussettes?","Vous avez perdu!\n\nIA: Merci d'avoir jouer!","Vous avez perdu!\n\nIA: Essayez encore!","Vous avez perdu!\n\nIA: Ce sera pour une autre fois!","Vous avez perdu!\n\nIA: Game over!","Vous avez perdu!\n\nIA: A la prochaine!","Vous avez perdu!\n\nIA: On s'en refait une?","Vous avez perdu!\n\nIA: Alors, c'est qui le maitre?","Vous avez perdu!\n\nIA: Ah, que voulez vous...L'espoir fait vivre!","Vous avez perdu!\n\nIA: Vous pensiez vraiment pouvoir me battre?","Vous avez perdu!\n\nIA: 1 point ; Joueur: KO!"};
    int nombre_aleatoire;
    nombre_aleatoire=rand_a_b(0,13);
    switch(nombre_aleatoire){
    case 0:return phrase[0];
           break;

    case 1:return phrase[1];
           break;

    case 2:return phrase[2];
           break;

    case 3:return phrase[3];
           break;

    case 4:return phrase[4];
           break;

    case 5:return phrase[5];
           break;

    case 6:return phrase[6];
           break;

    case 7:return phrase[7];
           break;

    case 8:return phrase[8];
           break;

    case 9:return phrase[9];
           break;

    case 10:return phrase[10];
           break;

    case 11:return phrase[11];
           break;

    case 12:return phrase[12];
           break;

    case 13:return phrase[13];
           break;

     default:return "Erreur! Situation non identifiee";break;}
}

/*Fonction gérant les messages de fin en cas de partie gagne*/
char *phraseAuGagnant(){
char *phrase[13]={"Vous avez gagne!\n\nIA: Felicitation!","Vous avez gagne!\n\nIA: Vous etes un maitre!","Vous avez gagne!\n\nIA: On s'en refait une?","Vous avez gagne!\n\nIA: Grrr! Je veux une revanche!","Vous avez gagne!\n\nIA: Je suis tombe sur plus fort que moi a ce que vois. Je m'incline!","Vous avez gagne!\n\nIA: Heu...Je n'etais pas concentre! La prochaine fois sera la bonne!","Vous avez gagne!\n\nIA: Heu... c'est surement du a un court circuit dans mon unite centrale!","Vous avez gagne!\n\nIA: Bravo! Et a la prochaine!","Vous avez gagne!\n\nIA: Vous etes trop fort pour moi! Je ferais peut etre bien de me retirer...","Vous avez gagne!\n\nIA: Incroyable!","Vous avez gagne!\n\nIA: Les legendes minimisent vos competances!","Vous avez gagne!\n\nIA: Heu...On n'avait rien parie hein?","Vous avez gagne!\n\nIA: Joueur: 1 point ; IA: KO!"};
    int nombre_aleatoire;
    nombre_aleatoire=rand_a_b(0,13);
    switch(nombre_aleatoire){
    case 0:return phrase[0];
           break;

    case 1:return phrase[1];
           break;

    case 2:return phrase[2];
           break;

    case 3:return phrase[3];
           break;

    case 4:return phrase[4];
           break;

    case 5:return phrase[5];
           break;

    case 6:return phrase[6];
           break;

    case 7:return phrase[7];
           break;

    case 8:return phrase[8];
           break;

    case 9:return phrase[9];
           break;

    case 10:return phrase[10];
           break;

    case 11:return phrase[11];
           break;

    case 12:return phrase[12];
           break;

    case 13:return phrase[13];
           break;

     default:return "Erreur! Situation non identifiee";break;}
}

/*Fonction gérant les messages de fin en cas de partie nul*/
char *phrasePartieNul(){
char *phrase[9]={"Match nul\n\nIA: Match nul, balle au centre!","Match nul\n\nIA: On s'en refait une?","Match nul\n\nIA: On parie que je gagne la prochaine?","Match nul\n\nIA: Nous nous sommes bien echauffes...Si on commencait les choses serieuse?","Match nul\n\nIA: Hum, voila un adversaire qui vaut le detour!","Match nul\n\nIA: Hum...nous finirons bien par nous departager!","Match nul\n\nIA: Incroyable, vous avez reussi a me tenir tete!","Match nul\n\nIA: Merci! A la prochaine!","Match nul\n\nIA: Merci d'avoir jouer! Si vous voulez nous departager vous savez ou me trouver!"};
    int nombre_aleatoire;
    nombre_aleatoire=rand_a_b(0,9);
    switch(nombre_aleatoire){
    case 0:return phrase[0];
           break;

    case 1:return phrase[1];
           break;

    case 2:return phrase[2];
           break;

    case 3:return phrase[3];
           break;

    case 4:return phrase[4];
           break;

    case 5:return phrase[5];
           break;

    case 6:return phrase[6];
           break;

    case 7:return phrase[7];
           break;

    case 8:return phrase[8];
           break;

    case 9:return phrase[9];
           break;

     default:return "Erreur! Situation non identifiee";break;}
}



/***************************************************************/
/*Trace la grille*/
void afficheGrille(Widget w,int width,int height,void *date)
{
  int i,j;
  ClearDrawArea();      /*On efface tout a l'ecran*/
  SetBgColor(w,GetNamedColor("BLACK")); /*On colore le fond en noir*/
  SetColor(GetNamedColor("BLUE"));      /*On colore ce qui sera en premier plan en bleu*/
  SetLineWidth(10);       /*On definit la largeur des lignes que l'on va tracer*/
  /******Dessine les lignes**************/
  for(i=0;i*50<=300;i++)
    {
      DrawLine(0,i*50,350,i*50);
    }
  /********Dessine les colonnes**********/
  for(j=0;j*50<=350;j++)
    {
      DrawLine(j*50,0,j*50,300);
    }
  /****Dessine les cercles***************/

  for(i=0;i<7;i++)
    for(j=0;j<6;j++)
      DrawArc(i*50,j*50,50,50,0,360);

       if(quiCommence==0){
     /*si le niveau de difficulté est 0, alors l'IA ne joue jamais ntelligemment: elle joue tout le temps de manière aléatoire*/
        if(strcmp(level,"0")==0){ printf("action de l'IA programmee en aleatoire\n");
       int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }
        /*si le niveau de difficulté est 1, alors l'IA joue intelligeament 1 fois sur 2*/
        else if(strcmp(level,"1")==0){
        int nb_aleatoire=rand_a_b(0,2);
        if(nb_aleatoire==0){ printf("action aleatoire\n");
         int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }
        else{printf("action refechi\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
        }
        }
        /*si le niveau de difficulté est autre que les précédents, alors l'IA joue tout le temps intelligemment*/
        else{printf("action de l'IA experte\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
            }
            }
}
/************************************************************************/

/*Action de l'IA de base*/
int action_IA_Basic()
{
  int i=0;
  srand(time(NULL));
  int m=rand()%7;
  while(i<6)
    {
      if(metier[i][m]==0)
    {
      SetColor(GetNamedColor("RED"));
      DrawFilledArc(m*50+5,5+i*50,40,40,0,360);
      SetColor(GetNamedColor("BLACK"));
      if(i+1<6)
        if(metier[i+1][m]==0)
          {
        usleep(150000);
        DrawFilledArc(5+m*50,5+i*50,40,40,0,360);
        i++;
          }
        else break;
      else break;
    }
      else m=rand()%7;
      }
  metier[i][m]=2;
  ShowDisplay();
  return m;
}



/*Action de l'IA experte*/
void action_IA_Expert(int colonne)
{
  int i=0;
  while(i<6)
    {
      if(metier[i][colonne]==0)
    {
      SetColor(GetNamedColor("RED"));
      DrawFilledArc(colonne*50+5,5+i*50,40,40,0,360);
      SetColor(GetNamedColor("BLACK"));
      if(i+1<6)
        if(metier[i+1][colonne]==0)
          {
        usleep(150000);
        DrawFilledArc(5+colonne*50,5+i*50,40,40,0,360);
        i++;
          }
        else break;
      else break;
    }
      }
  metier[i][colonne]=2;
  ShowDisplay();
}






/*pour choisir la colonne,la colonne l=1,2,3,4,5,6,7*/
void action_joueur(int colonne)
{
  int i=0;
  GetStandardColors();
  while(i<6)
    {
      if(metier[i][colonne-1]==0)
    {
      SetColor(GetNamedColor("YELLOW"));
      DrawFilledArc((colonne-1)*50+5,5+i*50,40,40,0,360);
      if(i+1<6)
        if(metier[i+1][colonne-1]==0)
        {
          SetColor(GetNamedColor("BLACK"));
          usleep(150000);
          DrawFilledArc((colonne-1)*50+5,5+i*50,40,40,0,360);
          i++;
        }
      else break;
    else break;
      }
    else break;
      }
  metier[i][colonne-1]=1;
  ShowDisplay();
}



/*Gere les actions du bouton 1*/
void button1(Widget w)
{
 char *annonceDeFin;
int EstValideMove=0;
  int column = 0; /*on initialise une variable colomn à 0*/
if(hasWinner()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
     if(isTie()!=1){
     if (isValidMove(column)==1) { /*si la colonne que l'on a choisit ne peut être choisit...*/
      makeMovePlayer(column); /*on effectue le mouvement dans la colonne valide que l'on a choisit*/
      action_joueur(column+1);
      comptCoupJoueur++;
      EstValideMove=1;
      }
      }
      else{annonceDeFin=phrasePartieNul();
      GetOkay (annonceDeFin);
      }
      }
      else{annonceDeFin=phraseAuPerdant();
      GetOkay(annonceDeFin);
      }

      if(EstValideMove==1){
      if(hasWinner()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
       if(isTie()!=1){
        /*si le niveau de difficulté est 0, alors l'IA ne joue jamais ntelligemment: elle joue tout le temps de manière aléatoire*/
        if(strcmp(level,"0")==0){ printf("action de l'IA programmee en aleatoire\n");
       int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }
        /*si le niveau de difficulté est 1, alors l'IA joue intelligeament 1 fois sur 2*/
        else if(strcmp(level,"1")==0){
        int nb_aleatoire=rand_a_b(0,2);
        if(nb_aleatoire==0){ printf("action aleatoire\n");
         int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }
        else{printf("action refechi\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
        }
        }
        /*si le niveau de difficulté est autre que les précédents, alors l'IA joue tout le temps intelligemment*/
        else{printf("action de l'IA experte\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
            }


        }
        else{annonceDeFin=phrasePartieNul();
      GetOkay (annonceDeFin);
      }
        }
        else{annonceDeFin=phraseAuGagnant();
        GetOkay (annonceDeFin);

        }
}

 afficherGrilleIA();
}


/*Gere les actions du bouton 2*/
void button2(Widget w)
{
 char *annonceDeFin;
 int EstValideMove=0;
  int column = 1; /*on initialise une variable colomn à 0*/
if(hasWinner()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
     if(isTie()!=1){
     if (isValidMove(column)==1) { /*si la colonne que l'on a choisit ne peut être choisit...*/
      makeMovePlayer(column); /*on effectue le mouvement dans la colonne valide que l'on a choisit*/
      action_joueur(column+1);
      comptCoupJoueur++;
      EstValideMove=1;
      }
      }
    else{annonceDeFin=phrasePartieNul();
      GetOkay (annonceDeFin);
      }
      }
      else{annonceDeFin=phraseAuPerdant();
      GetOkay (annonceDeFin);
      }

      if(EstValideMove==1){
      if(hasWinner()!=1 && isTie()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
        if(isTie()!=1){
        /*si le niveau de difficulté est 0, alors l'IA ne joue jamais ntelligemment: elle joue tout le temps de manière aléatoire*/
        if(strcmp(level,"0")==0){printf("action de l'IA programmee en aleatoire\n");
       int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }

        /*si le niveau de difficulté est 1, alors l'IA joue intelligeament 1 fois sur 2*/
        else if(strcmp(level,"1")==0){
        int nb_aleatoire=rand_a_b(0,2);
        if(nb_aleatoire==0){printf("action aleatoire\n");
         int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }
        else{printf("action reflechi\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
        }
        }
        /*si le niveau de difficulté est autre que les précédents, alors l'IA joue tout le temps intelligemment*/
        else{printf("action de l'IA experte\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
            }
        }
        else{annonceDeFin=phrasePartieNul();
      GetOkay (annonceDeFin);
      }
}
        else{annonceDeFin=phraseAuGagnant();
        GetOkay (annonceDeFin);

        }
 }
 afficherGrilleIA();
}


/*Gere les actions du bouton 3*/
void button3(Widget w)
{
 char *annonceDeFin;
 int EstValideMove=0;
  int column = 2; /*on initialise une variable colomn à 0*/
if(hasWinner()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
     if(isTie()!=1){
     if (isValidMove(column)==1) { /*si la colonne que l'on a choisit ne peut être choisit...*/
      makeMovePlayer(column); /*on effectue le mouvement dans la colonne valide que l'on a choisit*/
      action_joueur(column+1);
      comptCoupJoueur++;
      EstValideMove=1;
      }
      }
              else{annonceDeFin=phrasePartieNul();
      GetOkay (annonceDeFin);
      }
      }
          else{annonceDeFin=phraseAuPerdant();
          GetOkay(annonceDeFin);
          }

      if(EstValideMove==1){
      if(hasWinner()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
        if(isTie()!=1){
        /*si le niveau de difficulté est 0, alors l'IA ne joue jamais ntelligemment: elle joue tout le temps de manière aléatoire*/
        if(strcmp(level,"0")==0){printf("action de l'IA programmee en aleatoire\n");
       int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }

        /*si le niveau de difficulté est 1, alors l'IA joue intelligeament 1 fois sur 2*/
        else if(strcmp(level,"1")==0){
        int nb_aleatoire=rand_a_b(0,2);
        if(nb_aleatoire==0){printf("action aleatoire\n");
         int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }
        else{printf("action réflechi\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
        }
        }
        /*si le niveau de difficulté est autre que les précédents, alors l'IA joue tout le temps intelligemment*/
        else{printf("action de l'IA experte\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
            }
        }
            else{annonceDeFin=phrasePartieNul();
      GetOkay (annonceDeFin);
      }
}
        else{annonceDeFin=phraseAuGagnant();
        GetOkay (annonceDeFin);

        }
 }
 afficherGrilleIA();
}


/*Gere les actions du bouton 4*/
void button4(Widget w)
{
 char *annonceDeFin;
 int EstValideMove=0;
  int column = 3; /*on initialise une variable colomn à 0*/
if(hasWinner()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
     if(isTie()!=1){
     if (isValidMove(column)==1) { /*si la colonne que l'on a choisit ne peut être choisit...*/
      makeMovePlayer(column); /*on effectue le mouvement dans la colonne valide que l'on a choisit*/
      action_joueur(column+1);
      comptCoupJoueur++;
      EstValideMove=1;
      }
      }
         else{annonceDeFin=phrasePartieNul();
      GetOkay (annonceDeFin);
      }
      }
           else{annonceDeFin=phraseAuPerdant();
           GetOkay(annonceDeFin);
           }

      if(EstValideMove==1){
      if(hasWinner()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
        if(isTie()!=1){
        /*si le niveau de difficulté est 0, alors l'IA ne joue jamais ntelligemment: elle joue tout le temps de manière aléatoire*/
        if(strcmp(level,"0")==0){printf("action de l'IA programmee en aleatoire\n");
       int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }

        /*si le niveau de difficulté est 1, alors l'IA joue intelligeament 1 fois sur 2*/
        else if(strcmp(level,"1")==0){
        int nb_aleatoire=rand_a_b(0,2);
        if(nb_aleatoire==0){printf("action aleatoire\n");
         int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }
        else{printf("action reflechi\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
        }
        }
        /*si le niveau de difficulté est autre que les précédents, alors l'IA joue tout le temps intelligemment*/
        else{printf("action de l'IA experte\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
            }
        }
           else{annonceDeFin=phrasePartieNul();
      GetOkay (annonceDeFin);
      }
}
        else{annonceDeFin=phraseAuGagnant();
        GetOkay (annonceDeFin);

        }
 }
 afficherGrilleIA();
}


/*Gere les actions du bouton 5*/
void button5(Widget w)
{
  char *annonceDeFin;
  int EstValideMove=0;
  int column = 4; /*on initialise une variable colomn à 0*/
if(hasWinner()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
     if(isTie()!=1){
     if (isValidMove(column)==1) { /*si la colonne que l'on a choisit ne peut être choisit...*/
      makeMovePlayer(column); /*on effectue le mouvement dans la colonne valide que l'on a choisit*/
      action_joueur(column+1);
      comptCoupJoueur++;
      EstValideMove=1;
      }
      }
     else{annonceDeFin=phrasePartieNul();
      GetOkay (annonceDeFin);
      }
      }
           else{annonceDeFin=phraseAuPerdant();
           GetOkay (annonceDeFin);
           }

      if(EstValideMove==1){
      if(hasWinner()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
        if(isTie()!=1){
        /*si le niveau de difficulté est 0, alors l'IA ne joue jamais ntelligemment: elle joue tout le temps de manière aléatoire*/
        if(strcmp(level,"0")==0){printf("action de l'IA programmee en aleatoire\n");
       int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }

        /*si le niveau de difficulté est 1, alors l'IA joue intelligeament 1 fois sur 2*/
        else if(strcmp(level,"1")==0){
        int nb_aleatoire=rand_a_b(0,2);
        if(nb_aleatoire==0){printf("action aleatoire\n");
         int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }
        else{printf("action reflechi\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
        }
        }
        /*si le niveau de difficulté est autre que les précédents, alors l'IA joue tout le temps intelligemment*/
        else{printf("action de l'IA experte\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
            }
        }
           else{annonceDeFin=phrasePartieNul();
      GetOkay (annonceDeFin);
      }
}
       else{annonceDeFin=phraseAuGagnant();
        GetOkay (annonceDeFin);

        }
}
 afficherGrilleIA();
}


/*Gere les actions du bouton 6*/
void button6(Widget w)
{
 char *annonceDeFin;
 int EstValideMove=0;
  int column = 5; /*on initialise une variable colomn à 0*/
if(hasWinner()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
     if(isTie()!=1){
     if (isValidMove(column)==1) { /*si la colonne que l'on a choisit ne peut être choisit...*/
      makeMovePlayer(column); /*on effectue le mouvement dans la colonne valide que l'on a choisit*/
      action_joueur(column+1);
      comptCoupJoueur++;
      EstValideMove=1;
      }
      }
     else{annonceDeFin=phrasePartieNul();
      GetOkay (annonceDeFin);
      }
      }
           else{annonceDeFin=phraseAuPerdant();
           GetOkay (annonceDeFin);
           }

      if(EstValideMove==1){
      if(hasWinner()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
        if(isTie()!=1){
        /*si le niveau de difficulté est 0, alors l'IA ne joue jamais ntelligemment: elle joue tout le temps de manière aléatoire*/
        if(strcmp(level,"0")==0){printf("action de l'IA programmee en aleatoire\n");
       int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }

        /*si le niveau de difficulté est 1, alors l'IA joue intelligeament 1 fois sur 2*/
        else if(strcmp(level,"1")==0){
        int nb_aleatoire=rand_a_b(0,2);
        if(nb_aleatoire==0){printf("action aleatoire\n");
         int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }
        else{printf("action reflechi\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
        }
        }
        /*si le niveau de difficulté est autre que les précédents, alors l'IA joue tout le temps intelligemment*/
        else{printf("action de l'IA experte\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
            }
        }
        else{annonceDeFin=phrasePartieNul();
      GetOkay (annonceDeFin);
      }
}
       else{annonceDeFin=phraseAuGagnant();
        GetOkay (annonceDeFin);

        }
}
 afficherGrilleIA();
}

/*Gere les actions du bouton 7*/
void button7(Widget w)
{
 char *annonceDeFin;
 int EstValideMove=0;
  int column = 6; /*on initialise une variable colomn à 0*/
if(hasWinner()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
     if(isTie()!=1){
     if (isValidMove(column)==1) { /*si la colonne que l'on a choisit ne peut être choisit...*/
      makeMovePlayer(column); /*on effectue le mouvement dans la colonne valide que l'on a choisit*/
      action_joueur(column+1);
      comptCoupJoueur++;
      EstValideMove=1;
      }
      }
     else{annonceDeFin=phrasePartieNul();
      GetOkay (annonceDeFin);
      }
      }
     else{annonceDeFin=phraseAuPerdant();
     GetOkay(annonceDeFin);
     }

      if(EstValideMove==1){
      if(hasWinner()!=1) {/*tant qu'il n'y a pas de vainqueur ou qu'il n'y a pas d'égalité...*/
       if(isTie()!=1){
       /*si le niveau de difficulté est 0, alors l'IA ne joue jamais ntelligemment: elle joue tout le temps de manière aléatoire*/
        if(strcmp(level,"0")==0){printf("action de l'IA programmee en aleatoire\n");
       int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }

        /*si le niveau de difficulté est 1, alors l'IA joue intelligeament 1 fois sur 2*/
        else if(strcmp(level,"1")==0){
        int nb_aleatoire=rand_a_b(0,2);
        if(nb_aleatoire==0){printf("action aleatoire\n");
         int colonneJouer=action_IA_Basic();
       makeMoveAI(colonneJouer);
        }
        else{printf("action reflechi\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
        }
        }
        /*si le niveau de difficulté est autre que les précédents, alors l'IA joue tout le temps intelligemment*/
        else{printf("action de l'IA experte\n");
        int aiColumn = makeTurn(); /*la colonne que l'on choisit est la colonne que renvoit la fonction minimax(apha-béta) de l'IA*/
        action_IA_Expert(aiColumn);
            }
        }
       else{annonceDeFin=phrasePartieNul();
      GetOkay (annonceDeFin);
      }
}
       else{annonceDeFin=phraseAuGagnant();
        GetOkay (annonceDeFin);

        }
}
 afficherGrilleIA();
}





/*Gere l'affichage et les actions de la grille de jeu*/
void init_display(int argc, char **argv){
/*nomDuJoueur="MOI";*/
nom2=NomIA();
Widget w[100], form1, form2, form3, form4,form5;
   OpenDisplay(argc, argv);
  w[0]  = MakeMenu("File");
  w[1]  = MakeMenuItem(w[0], "Load...",  load,NULL);
  w[2]  = MakeMenuItem(w[0], "Save...",  save,NULL);
  w[3]  = MakeMenuItem(w[0], "Quit",     quit,NULL);
  w[22] = MakeMenu("statistiques");
  w[23] = MakeMenuItem(w[22], "stats des nombres de coups avant fin partie",statCoupJoueur,NULL);
  w[21] = MakeButton("Aide", aide,NULL);
   form1 = MakeForm(TOP_LEVEL_FORM);
   SetWidgetPos(form1, PLACE_UNDER, w[0], NO_CARE, NULL);
  w[20]=MakeDrawArea(350,300,afficheGrille,NULL);


   SetForm(TOP_LEVEL_FORM);
SetWidgetPos(w[22],PLACE_RIGHT,w[0], NO_CARE, NULL);
SetWidgetPos(w[21],PLACE_RIGHT,w[22], NO_CARE, NULL);


  form2 = MakeForm(TOP_LEVEL_FORM);
  SetWidgetPos(form2, PLACE_UNDER, form1, NO_CARE, NULL);
   w[4] = MakeButton("   1  ", button1, NULL);
   w[5] = MakeButton("  2  ", button2, NULL);
   w[6] = MakeButton("  3  ", button3, NULL);
   w[7] = MakeButton("  4  ", button4, NULL);
   w[8] = MakeButton("  5  ", button5, NULL);
   w[9] = MakeButton("  6  ", button6, NULL);
   w[10] = MakeButton("   7  ", button7, NULL);
   w[11] = MakeButton("      Coup en Arriere     ", NULL, NULL);

  SetWidgetPos(w[5], PLACE_RIGHT, w[4], NO_CARE, NULL);
  SetWidgetPos(w[6], PLACE_RIGHT, w[5], NO_CARE, NULL);
  SetWidgetPos(w[7], PLACE_RIGHT, w[6], NO_CARE, NULL);
  SetWidgetPos(w[8], PLACE_RIGHT, w[7], NO_CARE, NULL);
  SetWidgetPos(w[9], PLACE_RIGHT, w[8], NO_CARE, NULL);
  SetWidgetPos(w[10], PLACE_RIGHT, w[9], NO_CARE, NULL);
  SetWidgetPos(w[11], PLACE_UNDER, w[4], PLACE_RIGHT, w[4]);
  SetForm(TOP_LEVEL_FORM);

  form3 = MakeForm(TOP_LEVEL_FORM);
  SetWidgetPos(form3, PLACE_RIGHT, form1, NO_CARE, NULL);
  w[12] =  MakeLabel("Votre nom:          ");
  w[13] =  MakeLabel(nomDuJoueur);
  w[14] =  MakeLabel("Le nom de l'IA:     ");
  w[15] =  MakeLabel(nom2);
  w[16] =  MakeLabel("Difficulte: ");
  w[17] =  MakeLabel(level);


  SetWidgetPos(w[13], PLACE_RIGHT, w[14], NO_CARE, NULL);
  SetWidgetPos(w[14], PLACE_UNDER, w[12], NO_CARE, NULL);
  SetWidgetPos(w[15], PLACE_RIGHT, w[14], PLACE_UNDER, w[12]);
  SetWidgetPos(w[16], PLACE_UNDER, w[14], NO_CARE, NULL);
  SetWidgetPos(w[17], PLACE_RIGHT, w[16], PLACE_UNDER, w[15]);

  SetForm(TOP_LEVEL_FORM);

  form4 = MakeForm(TOP_LEVEL_FORM);
  SetWidgetPos(form4, PLACE_UNDER, form3, PLACE_RIGHT, form1);

  w[18] = MakeButton("Nouvelle partie", newPartie, NULL);
  w[19] = MakeButton("Quitter", real_quit, NULL);

  SetWidgetPos(w[19], PLACE_UNDER, w[18], NO_CARE, NULL);

  /*************************  Pixels fantome  ***********************************/
form5=MakeForm(TOP_LEVEL_FORM);
SetWidgetPos(form5, PLACE_UNDER, form4, PLACE_RIGHT, form1);
grilleAnimation();


SetForm(TOP_LEVEL_FORM);
/*************************************************************************/


  /*
   * Now actually put the display on the screen.
   */
  ShowDisplay();

  /*
   * Get some colors for drawing with.
   */
  GetStandardColors();

  SetBgColor(w[0], GREEN);
  SetBgColor(form1, BLUE);
  SetBgColor(w[20],BLACK);
  SetBorderColor(w[20],BLUE);
  SetBgColor(form2, YELLOW);
  SetBgColor(form3, BLUE);
  SetBgColor(form4, RED);
  SetBgColor(w[21], GREEN);
  SetBgColor(w[22],GREEN);
  SetBorderColor(form5,WHITE);

}



/*******************************   Main   ************************************/
int main(int argc,char **argv)
{

  if(OpenDisplay(argc,argv)==0)
    {
      fprintf(stderr,"erreur\n");
      return EXIT_FAILURE;
    }


/********1ERE FENETRE***********/
    /*affichage de la première fenêtre*/

 MakeWindow("Puissance 4 (Informations)", NULL, EXCLUSIVE_WINDOW);
quiCommence=1;
  Widget w0[25], form01, form02,form04;


/*form pour les paramètres du jeu*/
  form01 = MakeForm(TOP_LEVEL_FORM);
  SetWidgetPos(form01, NO_CARE, NULL, NO_CARE, NULL);

  w0[0] = MakeLabel("Difficulte du jeu:\n0=facile ; 1=moyen ; 2=difficile ");
  w_entryLevel = MakeStringEntry("2", 40, stringEntryfunc, NULL);

  w0[2] = MakeLabel("Voulez-vous commencer?(vous commencerez par defaut)\nCliquer sur oui pour commencer.\nCliquer sur non pour que l'IA commence.");
  w0[3] = MakeToggle("  Oui  ", FALSE,  NULL,  toggle1Act, NULL);
  w0[4] = MakeToggle("  Non  ", FALSE,  w0[3],  toggle2Act, NULL);
  /*
  if(GetToggleState(w0[3])==1){
SetToggleState(w0[4],FALSE);
}
else{
SetToggleState(w0[3],FALSE);
}
*/


  SetWidgetPos(w_entryLevel, PLACE_UNDER, w0[0], NO_CARE, NULL);
  SetWidgetPos(w0[2], PLACE_UNDER, w_entryLevel, NO_CARE, NULL);
  SetWidgetPos(w0[3], PLACE_UNDER, w0[2], NO_CARE, NULL);
  SetWidgetPos(w0[4], PLACE_RIGHT, w0[3], PLACE_UNDER, w0[2]);

  SetForm(TOP_LEVEL_FORM);

  form02 = MakeForm(TOP_LEVEL_FORM);
  SetWidgetPos(form02, PLACE_RIGHT, form01, NO_CARE, NULL);
  w0[7] = MakeLabel("Saisissez votre nom: ");
  w_entryNomJoueur = MakeStringEntry("Joueur1", 150, NULL, NULL);
  SetWidgetPos(w_entryNomJoueur, PLACE_RIGHT, w0[7], NO_CARE, NULL);

  SetForm(TOP_LEVEL_FORM);



form04 = MakeForm(TOP_LEVEL_FORM);
  SetWidgetPos(form04, PLACE_UNDER, form02, PLACE_RIGHT, form01);

  w0[12] = MakeButton("   Jouer   ", quitfenetre1, NULL);
  w0[13] = MakeButton("Quitter", real_quitfenetre1, NULL);

  SetWidgetPos(w0[13], PLACE_RIGHT, w0[12], NO_CARE, NULL);

  /*
   * Now actually put the display on the screen.
   */
  ShowDisplay();

  /*
   * Get some colors for drawing with.
   */
  GetStandardColors();

  SetBgColor(form01, BLUE);
  SetBgColor(form02, YELLOW);
SetBgColor(w0[12],GREEN);
SetBgColor(w0[13],RED);
SetBorderColor(form04,WHITE);

  MainLoop();


/***********FENETRE PRINCIPALE***************/
comptCoupJoueur=0; /*le nombre de coup du joueur est nul en début de partie.*/
  /*pour le 1eme partie,on utilise un tableau de 2 dimensions comme le metier*/
MakeWindow("Puissance 4 ", NULL, NONEXCLUSIVE_WINDOW);
  init_metier(metier[6][7]);
   afficherGrilleIA();
  init_display(argc,argv);
  MainLoop();

  return 0;
}

