#include <iostream>
#include <fstream>
#include "main.hpp"

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

void creer_prime(T_instance& instance) {
	for (int i = 0; i < instance.nb_piece; ++i) {
		for (int j = 0; j < instance.nb_machine; ++j) {
			instance.m_prim[j + 1 + i * instance.nb_machine] = instance.m[i][j] + 1;
			instance.p_prim[j + 1 + i * instance.nb_machine] = instance.p[i][j] + 1;
		}
	}
}


void evaluer(T_solution& sol, T_instance& instance) {
	int j;
	for (int i = 1; i <= instance.NT; i++)
	{
		j = sol.V[i];
		instance.N[j] = sol.V[j] + 1;
	}/*à finir*/
}

void recherche_locale(T_solution& sol, T_instance& instance, int nb_iteration) {
	int i = 0;

}

void generer_vecteur_random(T_solution& sol, T_instance& instance) {
	int nb_restant = instance.nb_piece;
	cout << "nb restant = " << nb_restant << endl;
	int x, indice=0;
	int TN[instance.nb_piece]; //TN[i]=i
	int NN[instance.nb_piece]; //tableau contenant le nb de fois qu'il reste à appeler la pièece i
	cout << "NN[] = ";
	for (int i = 0; i < instance.nb_piece; i++) //initialisation du tableau TN
	{
		NN[i] = instance.nb_machine;
		TN[i] = i + 1;
		cout << NN[i] << " ";
	}
	cout << endl;






	while (nb_restant > 0)
	{
		x = rand() % nb_restant + 1;
		cout << "x= " << x << endl;
		sol.V[indice] = x;
		indice++;
		NN[x - 1]--;
		if (NN[x-1] == 0)
		{
			TN[x-1] = TN[nb_restant-1];
			NN[x-1] = NN[nb_restant-1];
			nb_restant--;
		}
		cout << NN[0] << " " << NN[1] << " " << NN[2] << endl;
	}
}
void afficher_vecteur(T_solution &sol, T_instance &instance) {
	cout << "V= ";
	for (int i=0; i< 9; i++)
	{
		cout << sol.V[i];
	}
	cout << endl;
}
int main() {
	srand(time(0));
	T_instance instance;
	T_solution sol;
	lire_fichier("test_lax.txt", instance);
	creer_prime(instance);
	/*for (int i = 0; i < 10; ++i) {
		cout << instance.p_prim[i] << endl;
	}*/
	
	generer_vecteur_random(sol, instance);
	afficher_vecteur(sol, instance);
	return 1;
}