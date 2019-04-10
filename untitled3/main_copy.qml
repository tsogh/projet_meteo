import QtQuick 2.9
import QtQuick.Window 2.0

Window {
    visible: true
    width: 650
    height: 480

    Rectangle {
        id: rectangle
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        clip: true
        border.color: "#df2525"

        Text {
            id: firstText
            x: 16
            y: 114
            text: "temp"
            font.pixelSize: rectangle.height/20
            font.family: sansGuiltMB.name
            color: "#0085CA"
        }

        Text {
            id: txt2
            x: 16
            y: 187
            text: "Pression"
            font.pixelSize: rectangle.height/20
            font.family: sansGuiltMB.name
            color: "#0085CA"
        }
        Text {
            id: txt3
            x: 16
            y: 267
            width: 98
            height: 30
            text: "humidité"
            font.pixelSize: rectangle.height/20
            font.family: sansGuiltMB.name
            color: "#0085CA"
        }

        Image {
            id: image
            x: 326
            y: 56
            width: rectangle.wight/5
            height: rectangle.height/5
            source: "meteo.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image1
            x: 445
            y: 254
            width: rectangle.wight/5
            height: rectangle.height/5
            source: "fleche.jpg"
            fillMode: Image.PreserveAspectFit
        }
    }
}












/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_height:489;anchors_width:640;anchors_x:0;anchors_y:0}
}
 ##^##*/
