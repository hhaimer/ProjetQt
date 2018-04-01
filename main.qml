import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3


ApplicationWindow{
    visible: true
    width: 550
    height: 580
    title: qsTr("Morpion")

    SwipeView{
        id:swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        InstructionsForm {

        }

        MainForm{

                    button.onClicked: {
                        vueGame.newpiece();
                    }
                    mouseArea1 {
                    onClicked: vueGame.pilotage(0);
                    }
                    mouseArea2{
                        onClicked: vueGame.pilotage(1);
                    }
                    mouseArea3 {
                        onClicked: vueGame.pilotage(2);
                        }
                    mouseArea4{
                        onClicked: vueGame.pilotage(3);
                    }
                    mouseArea5 {
                        onClicked: vueGame.pilotage(4);
                        }
                    mouseArea6{
                        onClicked: vueGame.pilotage(5);
                    }
                    mouseArea7 {
                        onClicked: vueGame.pilotage(6);
                        }
                    mouseArea8{
                        onClicked: vueGame.pilotage(7);
                    }
                    mouseArea9 {
                        onClicked: vueGame.pilotage(8);
                        }
                    }
            }

        header: TabBar{
        id:tabBar
        currentIndex: swipeView.currentIndex
        TabButton{
            text: qsTr("Instructions")
        }
        TabButton{
            text: qsTr("Jouer")
        }
    }

}


