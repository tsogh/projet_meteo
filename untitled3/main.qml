import QtQuick 2.9
import QtQuick.Window 2.0

Window {
    id: window
    visible: true
    width: 750
    height: 580

    Rectangle {
        id: rectangle
        x: 187
        y: 83
        width: parent.width-parent.width/2
        height: parent.height-parent.height/3.5
        color: "#ffffff"
        border.color: "#e73737"
        anchors.centerIn: parent


        Image {
            id: image1
            x: 210
            width: rectangle.wight/3
            height: rectangle.height/3
            anchors.top: image.bottom
            anchors.topMargin: 61
            anchors.right: parent.right
            anchors.rightMargin: 35
            source: "fleche.jpg"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image
            x: 257
            width: rectangle.wight/3
            height: rectangle.height/3
            anchors.top: parent.top
            anchors.topMargin: 55
            anchors.right: parent.right
            anchors.rightMargin: 35
            source: "meteo.png"
            fillMode: Image.PreserveAspectFit
        }








        Text {
            id: element
            x: 8
            width: 359
            text: qsTr("Météo Toulouse")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.right: parent.right
            anchors.rightMargin: 8
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 387
            anchors.top: parent.top
            anchors.topMargin: 8
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }

        Row {
            id: row
            x: 9
            y: 63
            width: 200
            height: 172

            Text {
                id: element1
                text: qsTr("Température")
                //font.pixelSize: 12
                font.pixelSize: rectangle.height/20
            }

            TextEdit {
                id: textEdit3
                width: 80
                height: 20
                text: qsTr("44 °c")
                font.pixelSize: rectangle.height/20
            }
        }

        Row {
            id: row2
            x: 9
            y: 140
            width: 200
            height: 172

            Text {
                id: element2
                text: qsTr("Pression")
                //font.pixelSize: 12
                font.pixelSize: rectangle.height/20
            }

            TextEdit {
                id: textEdit4
                width: 80
                height: 20
                text: qsTr("900")
                font.pixelSize: rectangle.height/20
            }
        }
        Row {
            id: row3
            x: 9
            y: 234
            width: 200
            height: 172

            Text {
                id: element3
                text: qsTr("Humidité")
                //font.pixelSize: 12
                font.pixelSize: rectangle.height/20
            }

            TextEdit {
                id: textEdit34
                width: 80
                height: 20
                text: qsTr("33%")
                font.pixelSize: rectangle.height/20
            }
        }



    }



}




























































































































/*##^## Designer {
    D{i:2;anchors_y:157}D{i:3;anchors_y:8}D{i:4;anchors_height:19;anchors_width:536;anchors_x:0;anchors_y:8}
D{i:8;anchors_height:362;anchors_width:233;anchors_x:200;anchors_y:127}D{i:12;anchors_height:30;anchors_width:98}
D{i:13;anchors_height:20;anchors_width:80}D{i:11;anchors_x:194}D{i:1;anchors_height:372;anchors_width:534;anchors_x:55;anchors_y:55}
}
 ##^##*/
