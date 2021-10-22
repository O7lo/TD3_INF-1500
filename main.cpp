﻿#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
#include "Liste.hpp"
#include "Concepteur.hpp"
#include "Jeu.hpp"
#include "lectureFichierJeux.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//TODO: Vos surcharges d'opérateur <<

ostream& operator<< (ostream& o, const Liste<Jeu>& listeJeux) 
{
	string ligne = "\n\033[35m- - - - - - - - - - - - - - - - - - - - \033[0m\n";
	for (auto i : iter::range(listeJeux.size())) {
		o << ligne << endl;
		o << setw(36) << left << listeJeux[i].getTitre();
		o << "Développeur : " << setw(22) << left << listeJeux[i].getDeveloppeur();
		o << "    Sorti en " << listeJeux[i].getAnneeSortie();
		o << "\n\nConcepteurs du jeu:\n\n" << listeJeux[i].getConcepteurs();
		o << ligne << endl;
	}
	return o;
}

ostream& operator<< (ostream& o, const Liste<Concepteur>& listeConcepteurs)
{
	for (auto i : iter::range(listeConcepteurs.size())) {
		o << setw(26) << left << listeConcepteurs[i].getNom();
		o << "\tné en : " << listeConcepteurs[i].getAnneeNaissance();
		o << "\tpays : " << listeConcepteurs[i].getPays() << endl;
	}
	return o;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi(); 
	#pragma endregion
	
	Liste<Jeu> lj = creerListeJeux("jeux.bin");
	static const string ligneSeparation = "\n\033[92m"
		"══════════════════════════════════════════════════════════════════════════"
		"\033[0m\n";

	//TODO: Les l'affichage et l'écriture dans le fichier devraient fonctionner.
	//cout << ligneSeparation << lj;
	//ofstream("sortie.txt") << lj;

	//TODO: Compléter le main avec les tests demandés.
	//TODO: S'assurer qu'aucune ligne de code est non couverte.
	//NOTE: Il n'est pas nécessaire de couvrir les getters/setters simples fournis; il faut tester si vous en ajoutez ou les modifiez.
	//NOTE: Pour Liste, qui est générique, on demande de couvrir uniquement pour Liste<Jeu>, pas pour tous les types.


	cout << lj << endl;

}