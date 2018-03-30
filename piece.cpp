#include "piece.h"
#include <iostream>
using namespace std ;

piece::piece()
{
    joueur = 0 ;
    position = 0 ;
}

piece::piece(int num_joueur, int num_position)
{
    //on récupère le nom du joueur actuel et la position de son pion
    if(num_joueur == 1 || num_joueur == 2) joueur = num_joueur ;
    if(num_position <= 8 && num_position >= 0) position = num_position ;
    piece_Select = false ;
}

piece::piece(int num_joueur)
{
    if(num_joueur == 1 || num_joueur == 2) joueur = num_joueur ;
    piece_Select = false ;
}

void piece::setPosition(int num_position)
{
    if(num_position <= 8 && num_position >= 0) position = num_position ;
    piece_Select = false ;
}

int piece::getJoueur()
{
    return joueur ;
}

int piece::getPosition()
{
    return position ;
}

bool piece::getSelected()
{
    return piece_Select ;
}

void piece::setSelected(bool select)
{
    piece_Select = select ;
}
