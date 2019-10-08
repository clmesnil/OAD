#include <iostream>
#include <fstream>

using namespace std;

const int NMAX_SO = 400;
const int NMAX_SUCC = 400;
/*----------------------------------------------------------------
				Structures
-----------------------------------------------------------------*/

typedef struct T_Graphe {
	int nbSommets;
	int nbSucc[NMAX_SO];
	int Succ[NMAX_SUCC][NMAX_SO];
	int Poids[NMAX_SUCC][NMAX_SO];
	int Tableau[NMAX_SO];
}T_Graphe;

typedef struct T_Chemin {
	int sommet_dep;
	int sommet_fin;
	int date[NMAX_SO];
	int pred[NMAX_SO];
}T_Chemin;

int lire_fichier(string nom_fichier, T_Graphe& graphe) {
	ifstream fichier(nom_fichier);
	fichier >> graphe.nbSommets;
	for (int i = 0; i < graphe.nbSommets; ++i) {
		fichier >> graphe.nbSucc[i];
		for (int j = 0; j < graphe.nbSucc[i]; ++j) {
			fichier >> graphe.Succ[i][j];
			fichier >> graphe.Poids[i][j];
		}
	}
	fichier.close();
	return 1;
}

void lire_fichier_2(string nom_fichier, T_Graphe& graphe){
	ifstream fichier(nom_fichier);
	fichier >> graphe.nbSommets;
	int nb_arc = -1;
	fichier >> nb_arc;
	for (int i = 0; i < nb_arc; ++i) {
		int numero_sommet, sommet, succ, longueur, durée;
		fichier >> numero_sommet;
		fichier >> sommet;
		fichier >> succ;
		fichier >> longueur;
		fichier >> durée;
		graphe.Succ[sommet][graphe.nbSucc[sommet]] = succ;
		//on prend la longueur ou la durée pour calculer la distance dans le graphe
		graphe.Poids[sommet][graphe.nbSucc[sommet]] = longueur;
		graphe.nbSucc[i] ++;
  
	}
}

int decomp_par_niveaux(T_Graphe& graphe) {
	//int Niveaux[graphe.nbS]; // sommet à placer dans les niveaux
	for (int i=0; i<graphe.nbSommets; i++)
	{
		if (graphe.nbSucc[i] == 0)
		{
			
		}
	}
	return 1;
}
/*
int dijkstra(T_Graphe& graphe, T_Chemin chemin){
	// INITIALISATION
	int init = 1;
	chemin.date[init] = 0;
	chemin.pred[init] = 0;
	for (int i=1; i<=graphe.nbSommets; i++)
	{
		chemin.date[i] = 9999999999;
	}
	for (int i=1; i<=graphe.nbSommets; i++)
	{
		graphe.Tableau[i] = 0;
	}
	// FIN INITIALISATION


	// BOUCLES D_ALGO
	for (int i=1; i <= graphe.nbSommets; i++)
	{
		// RECHERCHE DU MINIMUM
		int min = 99999;
		int nmin = -1;
		for (int j=1; j<=graphe.nbSommets;j++)
		{
			if ((chemin.date[j]<min) && (graphe.Tableau[j] == 0))
			{
				min = chemin.date[j];
				nmin = j;
			}
		}

		for (int j=1; j<=graphe.nbSucc[nmin]; j++)
		{
			int k = graphe.Succ[nmin][j];
			if (chemin.date[nmin] + graphe.Poids[nmin][k] < chemin.date[k])
			{
				chemin.date[k] = chemin.date[nmin] + graphe.Poids[nmin][k];
				chemin.pred[k] = nmin;
			}
		}
		graphe.Tableau[nmin] = 1;
	}


	return 0;
}*/


int main() {
	cout << "c parti pr le bojeu" << endl;
	T_Graphe graphe;
	lire_fichier_2("DLP_210.dat", graphe);
	for (int i = 0; i < NMAX_SUCC; ++i) {
		for (int j = 0; j < NMAX_SO; ++j) {
			cout << graphe.Poids[i][j] << " ";
		}
		cout << endl;
	}

	return 1;
}