/**
* La classe Jeu  definit les jeux et gere les operations qui sont possible de faire sur un objet Jeu
* /fichier	jeu.hpp
* /auteurs	Pascal Gallant et Arthur Panoyan
* /date		26 octobre 2021
* Cr�� le	6 octobre 2021
*/
#pragma once
#include "Liste.hpp"
#include "Concepteur.hpp"
#include <string>
#include <memory>
#include <functional>

class Jeu
{
public:
	//:un constructeur par d�faut et un constructeur param�tr�.
	Jeu() = default;
	Jeu(const std::string& titre, const unsigned& anneeSortie, const std::string& developpeur,const Liste<Concepteur>& listeConcepteurs):titre_(titre),anneeSortie_(anneeSortie),developpeur_(developpeur),listeConcepteurs_(listeConcepteurs) {

	}

	const std::string& getTitre() const { return titre_; }
	void setTitre(const std::string& titre) { titre_ = titre; }
	unsigned getAnneeSortie() const { return anneeSortie_; }
	void setAnneeSortie(unsigned annee) { anneeSortie_ = annee; }
	const std::string& getDeveloppeur() const { return developpeur_; }
	void setDeveloppeur(const std::string& developpeur) { developpeur_ = developpeur; }

	// Pouvoir acc�der � la liste de concepteurs.
	const Liste<Concepteur> getConcepteurs() const {
		return listeConcepteurs_;
	}
	void setConcepteurs(const Liste<Concepteur>& listeConcepteurs) {
		listeConcepteurs_ = listeConcepteurs; 
	}
	// Votre m�thode pour trouver un concepteur selon un crit�re donn� par une lambda, en utilisant la m�thode de Liste.
	template <typename critereLambda>
	std::shared_ptr<Concepteur> trouverConcepteur(const critereLambda& critere) {
		return listeConcepteurs_.trouver(critere);
	}

private:
	std::string titre_ = "NON_DEFINI";
	unsigned anneeSortie_ = 0;
	std::string developpeur_ = "NON_DEFINI";
	// Attribut de la liste des concepteurs du jeu
	Liste<Concepteur> listeConcepteurs_;
};
