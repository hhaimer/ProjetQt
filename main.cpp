#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "jeu.h"
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv) ;
    jeu morpion("Joueur 1", "Joueur 2") ;
    QQmlApplicationEngine engine ;
    engine.rootContext()->setContextProperty("vueGame", &morpion) ; //on envoie int pour pouvoir appeler la fonction depuis l'interface
    engine.load(QUrl(QStringLiteral("qrc:/main.qml"))) ;

    return app.exec() ;



}
