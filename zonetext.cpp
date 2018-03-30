#include "zonetext.h"
#include <string>
#include <iostream>
using namespace std ;

zonetext::zonetext(string joueur_1 , string joueur_2)
{
    Joueur_1 = joueur_1 ;
    Joueur_2 = joueur_2 ;
    joueur_Actu(Joueur_1) ;
}

QString zonetext::getText(int tours_Jeu, bool issue)
{
    message_Affiche.clear() ;
    if(issue == true) //si la partie a finie avec une victoire 'true'
    {
        gagnant(tours_Jeu % 2) ;
    }
    else if (tours_Jeu <= 5) //si les 6 tours ne sont pas encore terminés
    {
        if (tours_Jeu % 2 == 0) joueur_Actu(Joueur_1) ;
        else joueur_Actu(Joueur_2) ;
    }
    if(tours_Jeu == 6 && issue == false){ //si personne n'a gagné
        finpartie();
    }
    return message_Affiche ;
}

void zonetext::joueur_Actu(string joueur)
{
    message_Affiche.append(QString::fromStdString(joueur)) ;
    message_Affiche.append(" c'est votre tour.") ;
}
void zonetext::finpartie()
{
    message_Affiche.append("Personne n'a gagné, fin de la partie");
}

void zonetext::gagnant(int joueur)
{
    string gagnant ;
    if (joueur == 1)
    {
        gagnant = Joueur_1 ;
    }
    if (joueur == 0)
    {
        gagnant = Joueur_2 ;
    }

    message_Affiche.append(QString::fromStdString(gagnant)) ;
    message_Affiche.append(" a gagné !") ;

}
