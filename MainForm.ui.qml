import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.3

Item
{
    id: item1
    width: 550
    height: 480
    parent: none.none
    property alias button: button
    property alias rectPPal: rectPPal
    property alias piece9: piece9
    property alias piece8: piece8
    property alias piece7: piece7
    property alias piece6: piece6
    property alias piece5: piece5
    property alias piece4: piece4
    property alias piece3: piece3
    property alias piece2: piece2
    property alias piece1: piece1
    property alias image: image
    property alias text1: text1
    property alias mouseArea: mouseArea
    property alias couleurJ2: couleurJ2
    property alias couleurJ1: couleurJ1
    property alias joueur2: joueur2
    property alias joueur1: joueur1
    property alias mouseArea9: mouseArea9
    property alias mouseArea8: mouseArea8
    property alias mouseArea7: mouseArea7
    property alias mouseArea6: mouseArea6
    property alias mouseArea5: mouseArea5
    property alias mouseArea4: mouseArea4
    property alias mouseArea1: mouseArea1
    property alias mouseArea2: mouseArea2
    property alias mouseArea3: mouseArea3


    Text
    {
        id: joueur1
        x: 129
        y: 14
        width: 117
        height: 40
        text: qsTr("Joueur 1")
        font.bold: true
        font.family: "Times New Roman"
        fontSizeMode: Text.FixedSize
        textFormat: Text.AutoText
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 28
    }



    Text
    {
        id: joueur2
        x: 353
        y: 14
        width: 128
        height: 40
        text: qsTr("Joueur 2")
        font.family: "Times New Roman"
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 28
    }



    Rectangle
    {
        id: couleurJ1
        x: 93
        y: 19
        width: 30
        height: 30
        color: "#00cc99"
        border.color: "#000000"
        border.width: 4
    }


    MouseArea
    {
        id: mouseArea
        anchors.fill: parent

        Button {
            id: button
            x: 444
            y: 419
            width: 70
            height: 53
            text: qsTr("Rejouez")
        }
    }

    Rectangle
    {
        id: couleurJ2
        x: 323
        y: 19
        width: 30
        height: 30
        color: "#ffcc00"
        border.color: "#000000"
        border.width: 4
    }


    Text
    {
        id: text1
        x: 45
        y: 412
        width: 414
        height: 60
        text: vueGame.currentText
        font.italic: true
        font.family: "Times New Roman"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 19
    }


    Rectangle
    {
        id: rectPPal
        x: 62
        y: 93
        width: 440
        height: 313
        color: "#ffffff"

        Image
        {
            id: image
            x: -15
            y: -33
            width: 472
            height: 355
            fillMode: Image.Stretch
            source: "Grille.jpg"
        }

        Rectangle
        {
            id: piece9
            x: 380
            y: 259
            width: 40
            height: 40
            color: vueGame.gameQML[8]
            border.width: 5
            border.color: vueGame.game2QML[8]
            visible: vueGame.game3QML[8]
        }

        Rectangle
        {
            id: piece8
            x: 200
            y: 259
            width: 40
            height: 40
            color: vueGame.gameQML[7]
            border.width: 5
            border.color: vueGame.game2QML[7]
            visible: vueGame.game3QML[7]
        }

        Rectangle
        {
            id: piece7
            x: 15
            y: 259
            width: 40
            height: 40
            color: vueGame.gameQML[6]
            border.width: 5
            border.color: vueGame.game2QML[6]
            visible: vueGame.game3QML[6]
        }

        Rectangle
        {
            id: piece6
            x: 380
            y: 125
            width: 40
            height: 40
            color: vueGame.gameQML[5]
            border.width: 5
            border.color: vueGame.game2QML[5]
            visible: vueGame.game3QML[5]
        }

        Rectangle
        {
            id: piece5
            x: 200
            y: 125
            width: 40
            height: 40
            color: vueGame.gameQML[4]
            border.width: 5
            border.color: vueGame.game2QML[4]
            visible: vueGame.game3QML[4]
        }

        Rectangle
        {
            id: piece4
            x: 16
            y: 125
            width: 40
            height: 40
            color: vueGame.gameQML[3]
            border.width: 5
            border.color: vueGame.game2QML[3]
            visible: vueGame.game3QML[3]
        }

        Rectangle
        {
            id: piece3
            x: 380
            y: -13
            width: 40
            height: 40
            color: vueGame.gameQML[2]
            border.width: 5
            border.color: vueGame.game2QML[2]
            visible: vueGame.game3QML[2]
        }

        Rectangle
        {
            id: piece2
            x: 200
            y: -13
            width: 40
            height: 40
            color: vueGame.gameQML[1]
            border.width: 5
            border.color: vueGame.game2QML[1]
            visible: vueGame.game3QML[1]
        }

        Rectangle
        {
            id: piece1
            x: 16
            y: -13
            width: 40
            height: 40
            color: vueGame.gameQML[0]
            border.width: 5
            border.color: vueGame.game2QML[0]
            visible: vueGame.game3QML[0]
        }

        MouseArea
        {
            id: mouseArea9
            x: 370
            y: 249
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea8
            x: 191
            y: 249
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea7
            x: 6
            y: 254
            width: 60
            height: 55
        }

        MouseArea
        {
            id: mouseArea6
            x: 372
            y: 116
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea5
            x: 191
            y: 116
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea4
            x: 8
            y: 116
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea3
            x: 370
            y: -18
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea2
            x: 190
            y: -18
            width: 60
            height: 60
        }

        MouseArea
        {
            id: mouseArea1
            x: 6
            y: -18
            width: 60
            height: 54
        }
    }
}
