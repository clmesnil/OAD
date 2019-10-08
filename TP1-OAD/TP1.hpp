#ifndef MODULE_GRAPHE
#define MODULE_GRAPHE

const int NMAX_SO 20;
const int NMAX_SUCC 5;

/*----------------------------------------------------------------
				Structures
-----------------------------------------------------------------*/

typedef struct T_Graphe {
	int nb_Sommets;
	int nb_Succ[NMAX_SO];
	int Succ[NMAX_SUCC][NMAX_SO];
	int Poids[NMAX_SUCC][NMAX_SO];
}T_Graphe;

typedef struct T_Chemin {
	int sommet_dep;
	int sommet_fin;
	int date[NMAX_SO];
	int pred[NMAX_SO];
}T_Chemin;

/*----------------------------------------------------------------
Prototypes
---------------------------------------------------------------- - */

#endif

