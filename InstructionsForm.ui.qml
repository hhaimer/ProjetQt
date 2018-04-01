import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    width: 500
    height: 580

    Text {
        id: text1
        x: 63
        y: 65
        text: qsTr("Bienvenue au jeu d'arraignée")
        font.bold: true
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        elide: Text.ElideRight
        font.pixelSize: 25
    }

    Text {
        id: text2
        x: 63
        y: 116
        color: "#017b79"
        text: qsTr("Première phase :")
        font.bold: true
        font.pixelSize: 12
    }

    Text {
        id: text3
        x: 63
        y: 156
        text: qsTr("Dans la phase de placement, les joueurs déposent alternativement ")
        font.pixelSize: 12
    }

    Text {
        id: text4
        x: 63
        y: 176
        text: qsTr("chacun leurs 3 pions en tentant de les aligner,ce qui est en généralement ")
        font.pixelSize: 12
    }

    Text {
        id: text5
        x: 63
        y: 196
        text: qsTr("impossible si les joueurs sont réveillés.")
        font.pixelSize: 12
    }

    Text {
        id: text6
        x: 63
        y: 234
        color: "#da0d07"
        text: qsTr("Pour placer vos pions, il faut simplement cliquer sur les carreaux de la grille")
        font.pixelSize: 12
    }

    Text {
        id: text7
        x: 63
        y: 284
        color: "#017b79"
        text: qsTr("Deuxième phase :")
        font.bold: true
        font.pixelSize: 12
    }

    Text {
        id: text8
        x: 63
        y: 321
        text: qsTr("Dans la phase de déplacement, les joueurs déplacent alternativement ")
        font.pixelSize: 12
    }

    Text {
        id: text9
        x: 66
        y: 341
        text: qsTr("leurs pions le long des segments accessibles. Le premier qui aligne ")
        font.pixelSize: 12
    }

    Text {
        id: text10
        x: 66
        y: 361
        text: qsTr("3 pions a gagné.")
        font.pixelSize: 12
    }

    Text {
        id: text11
        x: 63
        y: 395
        color: "#da0d07"
        text: qsTr("Pour déplacer vos pions, il faut simplement cliquer sur le pions que vous ")
        font.pixelSize: 12
    }

    Text {
        id: text12
        x: 63
        y: 415
        color: "#da0d07"
        text: qsTr("voulez déplacez, ensuite vous cliquez sur où vous voulez le remetre")
        font.pixelSize: 12
    }
}
