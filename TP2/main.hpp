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
	int NT = nb_machine * nb_piece; //nb op�rations
	int p_prim[max]; //contient les dur�es que chaque pi�ce passe sur les machines dans l'ordre o� elles rencontrent les machines ex: 10 / 5 / 4 /30
	int m_prim[max]; //contient les num�ros des machines (ordonn�es) sur lesquelles passent les pi�ces
	int N[n_max] = { 0 }; //N[i]: nb de fois qu'on a rencontr� la pi�ce i dans le vecteur V;
}T_instance;


typedef struct T_solution {
	int V[11]; //vecteur de Bierwith
	int st[max]; //tableau des starting time
	int pred[max] = { -1 }; //tableau des pr�d�cesseurs
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