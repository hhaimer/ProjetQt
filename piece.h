#ifndef PIECE_H
#define PIECE_H

class piece
{
public:
    piece() ;
    piece(int player) ;
    piece(int player,int pos) ;
    //Les Setters et les getters
    void setPosition(int num_position) ;
    int getJoueur() ;
    int getPosition() ;
    bool getSelected() ;
    void setSelected(bool selection) ;
private:
    int joueur, position ; //recoivent le joueur et les numéros
    bool piece_Select ;
} ;

#endif // PIECE_H
