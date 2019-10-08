#include <iostream>
#include <fstream>
#include <time.h>
#include "Jobshop.hpp"

using namespace std;

int lire_fichier(string nom_fichier, T_instance& instance) {
	ifstream fichier(nom_fichier);
	fichier >> instance.nb_piece;
	fichier >> instance.nb_machine;

	for (int i = 0; i < instance.nb_piece; ++i) {
		for (int j = 0; j < instance.nb_machine; ++j) {
			fichier >> instance.m[i][j];
			fichier >> instance.p[i][j];
		}
	}
	fichier.close();
	return 1;
}


void afficher_instance(T_instance& instance) {
	cout << "nombre de pieces : " << instance.nb_piece << endl;
	cout << "nombre de machines : " << instance.nb_machine << endl;

	cout << "tableau des durees" << endl;
	for (int i = 0; i < instance.nb_piece; ++i) {
		for (int j = 0; j < instance.nb_machine; ++j) {
			cout << instance.m[i][j] << " ";
		}
		cout << endl;
	}

	cout << "tableau des poids" << endl;
	for (int i = 0; i < instance.nb_piece; ++i) {
		for (int j = 0; j < instance.nb_machine; ++j) {
			cout << instance.p[i][j] << " ";
		}
		cout << endl;
	}
}


void creer_prime(T_instance& instance) {
	for (int i = 0; i < instance.nb_piece; ++i) {
		for (int j = 0; j < instance.nb_machine; ++j) {
			instance.m_prim[j + i * instance.nb_machine] = instance.m[i][j];
			instance.p_prim[j + i * instance.nb_machine] = instance.p[i][j];
		}
	}
}


void evaluer(T_solution& sol, T_instance& instance) {
	int j;
	for (int i = 1; i <= instance.NT; i++) {
		j = sol.V[i];
		instance.N[j] = sol.V[j] + 1;
	}/*à finir*/
}


void recherche_locale(T_solution& sol, T_instance& instance, int nb_iteration) {
	int i = 0;

}


void generer_vecteur_alea(T_solution& sol, T_instance& instance) {

	int nb_restant = instance.nb_piece;
	int x; //var aléatoire entre 1 et nb_restant
	int indice = 0;
	int TN[m_max]; //TN[i] = i
	int NN[m_max]; //tableau contenant le nb de fois qu'il reste à appeler la pièce i

	for (int i = 0; i < instance.nb_piece; i++) { //initialisation du tableau TN
		TN[i] = i + 1;
		NN[i] = instance.nb_machine;
	}
	cout << endl;

	while (nb_restant > 0) {

		x = rand() % nb_restant + 1;
		sol.V[indice] = TN[x - 1];
		indice++;
		NN[x - 1]--;

		if (NN[x - 1] == 0) { //si une case est vide on "reduit" la taille du tableau

			TN[x - 1] = TN[nb_restant - 1];
			NN[x - 1] = NN[nb_restant - 1];
			nb_restant--;
		}
	}
}


void afficher_vecteur(T_solution& sol, T_instance& instance) { // affiche le vecteur de Bierwith de la solution
	cout << "V= ";
	for (int i = 0; i < 9; i++) {
		cout << sol.V[i] << " ";
	}
	cout << endl;
}