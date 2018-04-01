#include "jeu.h"
#include "piece.h"
#include "joueur.h"
#include "zonetext.h"
#include <iostream>
using namespace std ;

jeu::jeu(string nom_Joueur1, string nom_Joueur2, QObject *parent): QObject(parent),Joueur1(nom_Joueur1,true),Joueur2(nom_Joueur2,false),message(nom_Joueur1,nom_Joueur2)
{
    tours_compt = 0 ;
    pieceListe = new piece[6] ;
    victoire_jeu = false ;
}

void jeu::pilotage(int slot)
{
    bool existsalready = false;
    if(victoire_jeu == false) // si la partie n'est pas encore gagnée
    {
        if (tours_compt < 6) //si nous avons pas mis tous les pions sur la grille
        {
            for(int i = 0 ; i < tours_compt ; i++)
            {
                if(slot == pieceListe[i].getPosition()) //recuperer les positions et les intialisés par true
                    existsalready = true ;
            }
            if (existsalready == false) // à chaque tours on place un nouveau pion
            {
                premiere_Etape(slot) ;
                tours_compt++ ;
            }
        }
        else
        {
            jeu::second_Etape(slot) ;
        }
        // à la fin de chaque tours, on teste si quelqu'un à gagner et on change les différents paramètres.
        victoire() ;
        changePos() ;
        changeBord() ;
        changeVis() ;
        changeTexte() ;

    }
}
void jeu::newpiece(){
    //si on veut relancer une partie, on reintialise les paramètres par defaut

    delete[] pieceListe;
    pieceListe = new piece[6];
    tours_compt = 0 ;
    victoire_jeu = false;

    changePos() ;
    changeBord() ;
    changeVis() ;
    changeTexte() ;

}

void jeu::premiere_Etape(int slot)
{
    pieceListe[tours_compt] = piece(tours_compt % 2, slot) ;
}

void jeu::second_Etape(int slot)
{
    bool existsalready = false, occupiedalready = false ;
    for(int i = 0 ; i < 6 ; i++) // Première etape selectionné le pion qu'on veut déplacer
                                 //Parcourir la grille, et changer la proporièté du pion selectionné de false to true
    {
       if(slot == pieceListe[i].getPosition() && tours_compt % 2 == i % 2)
       {
           existsalready = true ; //Des que le pion selectionné est trouvé, nous allons changé la valeur de sa position qu'il existe dans cet endroit
           for(int j = 0 ; j < 6 ; j++)
           {
               if(pieceListe[j].getSelected() == true)
               {
                   pieceListe[j].setSelected(false) ;
               }
           }
           pieceListe[i].setSelected(true) ;
        }
    }
    if (existsalready == false) //deuxieme etape lors du deplacement du pion, si la place choisi est vide
    {
        for(int k = 0 ; k < 6 && k < tours_compt ; k++)
        {
            if(slot == pieceListe[k].getPosition())
                occupiedalready = true ;
        }
        if(occupiedalready == false)
        {
            for(int l = 0 ; l < 6 ; l++)
            {
                if(pieceListe[l].getSelected() == true)
                {
                    pieceListe[l].setPosition(slot) ;
                    tours_compt++ ;
                }
            }
        }
    }
}

QList<QString> jeu::readPos()
{
    QList<QString> positions ;
    for(int i = 0 ; i < 9 ; i++)
    {
        positions << "#ffffff" ;
    }
    for(int j = 0 ; j < 6 && j < tours_compt ; j++)
    {
        if(j % 2 == 0)
        {
            positions[pieceListe[j].getPosition()] = "#00cc99" ;
        }
        else
        {
            positions[pieceListe[j].getPosition()] = "#ffcc00" ;
        }
    }
    return positions ;
}

QList<QString> jeu::readBord()
    {
        QList<QString> bordure ;
        for(int i = 0 ; i < 9 ; i++)
        {
            bordure << "#ffffff" ;
        }
        for(int j = 0 ; j < 6 && j < tours_compt ; j++)
        {
            if(j % 2 == 0)
            {
                bordure[pieceListe[j].getPosition()] = "#000000" ;
            }
            else
            {
                bordure[pieceListe[j].getPosition()] = "#000000" ;
            }
        }
        return bordure ;
    }

QList<bool> jeu::readVis()
{
    QList<bool> visible ;
    for(int i = 0 ; i < 9 ; i++)
    {
        visible << false ;
    }
    for(int j = 0 ; j < 6 && j < tours_compt ; j++)
    {
        visible[pieceListe[j].getPosition()] = true ;
    }
    return visible ;
}

int jeu::getTour()
{
    return tours_compt ;
}

bool jeu::victoire()
{
    int i ;
    int* caseJ1 = new int[3] ;
    int* caseJ2 = new int[3] ;
    if(tours_compt >= 5)
    {
        for(int j = 0 ; j < 6 && j < tours_compt ; j++)
        {
            i = j / 2 ;

            if(j % 2 == 0) //on recupère la position des pions pour le joueur 1
            {
                caseJ1[i] = pieceListe[j].getPosition() ;
            }
            else //on recupère la position des pions pour le joueur 2
            {
                caseJ2[i] = pieceListe[j].getPosition() ;
            }
        }
        //on teste si quelqu'un a gagné
        if (tours_compt % 2 == 1) return testVictoire(caseJ1) ;
        else return testVictoire(caseJ2) ;
        delete[] caseJ1 ;
        delete[] caseJ2;
    }
}

bool jeu::testVictoire(int *pPos)
{
    int a ;
    //on trie le tableau des positions
    if (pPos[0] > pPos[1])
    {
        a = pPos[0] ;
        pPos[0] = pPos[1] ;
        pPos[1] = a ;
    }
    if (pPos[1] > pPos[2])
    {
        a = pPos[2] ;
        pPos[2] = pPos[1] ;
        pPos[1] = a ;
    }
    if (pPos[0] > pPos[1])
    {
        a = pPos[0] ;
        pPos[0] = pPos[1] ;
        pPos[1] = a ;
    }
    //puis on teste tous les possibilité si les pions sont allignés
    if (pPos[0] % 3 == pPos[1] % 3 && pPos[0] % 3 == pPos[2] % 3)
    {
        victoire_jeu = true ;
    }
    else if (pPos[0] / 3 == pPos[1] / 3 && pPos[0] / 3 == pPos[2] / 3)
    {
        victoire_jeu = true ;
    }
    else if (pPos[0] == 2 && pPos[1] == 4 && pPos[2] == 6)
    {
        victoire_jeu = true ;
    }
    else if (pPos[0] == 0 && pPos[1] == 4 && pPos[2] == 8)
    {
        victoire_jeu = true ;
    }

    return victoire_jeu;
}

QString jeu::currentText()
{
    return message.getText(tours_compt, victoire_jeu) ;
}
