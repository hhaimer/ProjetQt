#ifndef JEU_H
#define JEU_H
#include "piece.h"
#include "joueur.h"
#include "zonetext.h"
#include <string>
using namespace std ;

class jeu : public QObject //Permet l'intéraction avec l'interface graphique
{
    Q_OBJECT
public:
    explicit jeu(string nom_Joueur1, string nom_Joueur2, QObject *parent = 0) ;
    Q_INVOKABLE void pilotage(int slot) ; //On l'appele à chaque coup pour piloter le jeu et afficher les pions sur la positions souhaitées
    void premiere_Etape(int slot) ; //gère la parti quand les 6 jetons ne sont pas encore mis
    Q_INVOKABLE QList<QString> readPos() ; //liste des positions utilisées
    Q_INVOKABLE QList<QString> readBord() ;//liste des bordures
    Q_INVOKABLE QList<bool> readVis() ;
    Q_PROPERTY(QList<QString> gameQML READ readPos NOTIFY changePos) ; //avec les mains : a chaque fois qu'on appelera depuis une fonction la signal "gameChanged", on appelera la fonction "readPos" (qui rend une Qliste actualisé des positions des jetons) et cette liste sera utilisé par l'interface sous le nom "gameQML"
    Q_PROPERTY(QList<QString> game2QML READ readBord NOTIFY changeBord) ;
    Q_PROPERTY(QList<bool> game3QML READ readVis NOTIFY changeVis) ;
    Q_INVOKABLE int getTour() ;
    Q_PROPERTY(QString currentText READ currentText NOTIFY changeTexte) ;
    bool victoire() ;
    Q_INVOKABLE void newpiece();
    bool testVictoire(int *pPos) ;
    Q_INVOKABLE QString currentText() ;
signals:
    void changePos() ; //signal qui sert à communiquer avec le jeu et changer la position des pions
    void changeBord() ; //signal pour changer les Bordures
    void changeVis() ; //signal pour changer la visibiité des pions
    void changeTexte() ; //signal pour changer le texte (le tour dequel joueur)
public slots:

private:
    int tours_compt ; //compteur des coups déjà faits, afin de savoir dans quelle partie du jeu on est
    zonetext message ; //objects avec les texts, joueurs
    joueur Joueur1, Joueur2 ; //Création de deu joueur
    piece *pieceListe ; //Liste des 6 pions
    bool victoire_jeu ; //Tester si la partie est fini ou non
} ;

#endif // JEU_H
