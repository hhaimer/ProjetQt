#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
using namespace std ;

class joueur
{
public:
    joueur(string nom_Joueur, bool etat = false) ;
    void activation_Joueur() ;
    void desactivation_Joueur() ;
    bool etat_Actif() ;
    //Setter de nom
    string getNom() ;
private:
    bool joueur_Actuel ;
    string nom ;
} ;

#endif // JOUEUR_H
