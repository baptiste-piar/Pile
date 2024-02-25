#include <iostream>
using namespace std;
#include <cassert>

template <typename T>
struct Noeud {
    T donnees;
    Noeud <T>* suivant;
};

template <typename T>
class Pile {
    private:
        Noeud <T>* entete;
        int compteur;
        Noeud <T>* CreerNoeud (const T& valeur);
     
    public:
        Pile ();
        ~Pile ();
        void push (const T& valeur);
        void pop ();
        T& premier () const;
        void afficher () const;
        int taille () const;
};