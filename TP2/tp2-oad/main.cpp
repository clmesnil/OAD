#include <iostream>
#include <fstream>
#include <time.h>
#include "Jobshop.hpp"

using namespace std;


int main() {
	srand(time(0));
	T_instance instance;
	T_solution sol;
	lire_fichier("test.txt", instance); //fonctionnel
	afficher_instance(instance); //fonctionnel
	creer_prime(instance); //fonctionnel
	
	generer_vecteur_alea(sol, instance);
	afficher_vecteur(sol, instance);
	return 1;
}