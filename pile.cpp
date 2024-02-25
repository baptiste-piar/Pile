#include "pile.hpp"

template <typename T>
Pile <T> :: Pile ():entete (NULL), compteur (0) {}
 
template <typename T>
Pile <T> :: ~Pile () {
    Noeud <T>* del = entete;
    while (entete) {
        entete = entete -> suivant;
        delete del;
        del = entete;
    }
}

template <typename T>
void Pile <T> :: push (const T& valeur) {
    Noeud <T>* nouveau = CreerNoeud (valeur);
    nouveau -> suivant = entete;
    entete = nouveau;
    compteur++;
}

template <typename T>
void Pile <T> :: pop () {
    if (compteur == 0) {
        cout << "Erreur! La pile est vide." << endl;
        return;
    }
    Noeud <T>* del = entete;
    entete = entete -> suivant;
    delete del;
    compteur--;
}

template <typename T>
T& Pile <T> :: premier () const {
    if (compteur == 0) {
        cout << "Erreur ! La pile est vide";
        assert (false);
    }
    return entete -> donnees;
}

template <typename T>
void Pile <T> :: afficher () const {
    if (compteur == 0) {
        cout << "La pile est vide !" << endl;
        return;
    }
    Noeud <T>* courant = entete;
    while (courant != 0) {
        cout << courant -> donnees << endl;
        courant = courant -> suivant;
    }
}
 
template <typename T>
int Pile <T> :: taille () const {
    return compteur;
}