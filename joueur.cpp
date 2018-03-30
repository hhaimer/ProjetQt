#include "joueur.h"
#include <string>
#include <iostream>
using namespace std ;

joueur::joueur(string nom_Joueur, bool etat)
{
    nom = nom_Joueur ;
    if(etat)
    {
        activation_Joueur() ;
    }
    else
    {
        desactivation_Joueur() ;
    }
}

void joueur::activation_Joueur()
{
    joueur_Actuel = true ;
}

void joueur::desactivation_Joueur()
{
    joueur_Actuel = false ;
}

bool joueur::etat_Actif()
{
    return joueur_Actuel ;
}

string joueur::getNom()
{
    return nom ;
}
