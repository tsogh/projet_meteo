import QtQuick 2.0
import QtQuick.Window 2.0

Window
{
    visible: true
    width: 750
    height: 550

    Rectangle{
        id:rec
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        color: "transparent"
        Text{
            id : element
            x: 8
            width: 476
            text: qsTr("<b>Météo à Toulouse</b>")
            anchors.bottomMargin: 74
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.top: parent.top
            anchors.topMargin: 8
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: rec.height/20
            color:"black"
        }
        Rectangle {
            id: recbouton1
            x: 10
            y: 10
            color: "grey"
            width: rec.width/8
            height: rec.height/20

            Text{
                id: buttonLabel
                text: qsTr("<b>Courbes</b>")
                color: "black"
                anchors.centerIn: recbouton1
                width: recbouton1.width
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: recbouton1.height/2
            }
            MouseArea{
                id: buttonMouseArea
                anchors.fill: recbouton1
                onClicked: console.log(buttonLabel.text + " clicked" )
            }
        }

        Rectangle {
            id:rec1
            x: rec.width /2
            y: 50
            width: rec.width/2
            height: rec.height -50
            anchors.left: rec.left
            color: "black"

            Rectangle {
                id:rec11
                x:0
                y:0
                width: rec1.width
                height: rec1.height/3
                color: "blue"
                Text {
                    id: element1
                    text: qsTr("<b>Température</b>")
                    anchors.centerIn: rec11
                    width: rec1.width
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: rec1.height/20
                }
                Text {
                    id: element2
                    text: qsTr("<b>44°C</b>")
                    x: 0
                    y: element1.y +50
                    width: rec1.width
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: rec1.height/20
                }

            }Rectangle {
                id:rec12
                x:0
                y:rec12.height
                width: rec1.width
                height: rec1.height/3
                color: "grey"
                Text {
                    id: element3
                    text: qsTr("<b>Pression atmosphérique</b>")
                    anchors.centerIn: rec12
                    width: rec1.width
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: rec1.height/20
                }
                Text {
                    id: element4
                    text: qsTr("<b>1030 hPa</b>")
                    x: 0
                    y: element3.y +50
                    width: rec1.width
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: rec1.height/20
                }

            }Rectangle {
                id:rec13
                x:0
                y:rec12.height*2
                width: rec1.width
                height: rec1.height/3
                color: "orange"
                Text {
                    id: element5
                    text: qsTr("<b>Taux d'humidité</b>")
                    anchors.centerIn: rec13
                    width: rec1.width
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: rec1.height/20
                }
                Text {
                    id: element6
                    text: qsTr("<b>77%</b>")
                    x: 0
                    y: element5.y +50
                    width: rec1.width
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: rec1.height/20
                }


            }

        }

        Rectangle {
            id:rec2
            x: rec.width/2
            y: 50
            width: rec.width/2
            height: rec.height -50
            anchors.right: rec.right
            color: "white"
            Rectangle {
                id:rec21
                x:0
                y:0
                width: rec2.width
                height: rec2.height/2.5
                color: "yellow"
                Image {
                    id: image1
                    sourceSize.width: Math.min(rec21.width,rec21.height)
                    sourceSize.height: Math.min(rec21.width,rec21.height)
                    anchors.centerIn: rec21
                    scale: Qt.KeepAspectRatio*1.5
                    source: "soleil.svg"
                }

            }Rectangle {
                id:rec22
                x:0
                y:rec22.height
                width: rec2.width
                height: rec2.height/2.5
                color: "pink"
                Image {
                    id: image2
                    x: 0
                    sourceSize.width: Math.min(rec22.width,rec22.height)
                    sourceSize.height: Math.min(rec22.width,rec22.height)
                    anchors.centerIn: rec22
                    source: "flecheascendante.svg"
                    scale: Qt.KeepAspectRatio/2
                }

            }Rectangle {
                id:rec23
                x:0
                y: rec22.height*2
                width: rec2.width
                height: rec2.height/5
                color: "violet"
                Text {
                    id: element7
                    text: qsTr("<b>description du temps</b>")
                    x: 0
                    //y: element5.y +50
                    width: rec2.width
                    anchors.centerIn: rec23
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: rec2.height/20
                }


            }
            /*Button{
                id: bouton1
                width:
                height:
                color:"red"

            }
            Button{
                id: bouton2
                width:
                height:
                color:"green"

            }*/
        }
    }
}
