#ifndef MAIN_HPP
#define MAIN_HPP

const int n_max=50;
const int m_max=50;
const int max = n_max * m_max +2;

/*											    */
/*					STRUCTURES					*/
/*												*/

typedef struct T_instance {
	int nb_piece; //nb pieces
	int nb_machine; //nb machines
	int m[n_max][m_max];
	int p[n_max][m_max];
	int NT = nb_machine * nb_piece; //nb opérations
	int p_prim[max]; //contient les durées que chaque pièce passe sur les machines dans l'ordre où elles rencontrent les machines ex: 10 / 5 / 4 /30
	int m_prim[max]; //contient les numéros des machines (ordonnées) sur lesquelles passent les pièces
	int N[n_max] = { 0 }; //N[i]: nb de fois qu'on a rencontré la pièce i dans le vecteur V;
}T_instance;


typedef struct T_solution {
	int V[11]; //vecteur de Bierwith
	int st[max]; //tableau des starting time
	int pred[max] = { -1 }; //tableau des prédécesseurs
	int cmax;
}T_solution;

/*											    */
/*					PROTOTYPES					*/
/*												*/

int lire_fichier(std::string nom, T_instance& instance);
void evaluer(T_solution& sol, T_instance& instance);
void generer_vecteur_random(T_solution& sol, T_instance& instance);
void recherche_locale(T_solution& sol, T_instance& instance, int nb_iteration);
void afficher_vecteur(T_solution& sol, T_instance & instance);




#endif