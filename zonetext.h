#ifndef ZONETEXT_H
#define ZONETEXT_H
#include <string>
#include <QObject>
using namespace std ;

class zonetext
{
public:
    zonetext(string joueur_1, string joueur_2) ;
    Q_INVOKABLE QString getText(int tours_Jeu, bool issue) ;
    string get_instructions() ;
    void joueur_Actu(string joueur) ;
    void gagnant(int joueur) ;
    void top_Depart() ;
    void dephasage() ;
    void fin() ;
private:
    QString message_Affiche ;
    string Joueur_1, Joueur_2;
} ;

#endif // ZONETEXT_H
