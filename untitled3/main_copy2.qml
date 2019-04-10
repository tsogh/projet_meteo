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





        Column {
            id: column
            x: 14
            y: 60
            width: 190
            height: 205
            spacing: 32

            Row {
                id: row
                width: 200
                height: 32

                Text {
                    id: firstText
                    width: 77
                    height: 35
                    text: "temp"
                    font.pixelSize: rectangle.height/20
                    font.family: sansGuiltMB.name
                    color: "#0085CA"
                }

                TextEdit {
                    id: textEdit
                    width: 80
                    height: 20
                    text: qsTr("Text Edit")
                    font.pixelSize: 12
                }
            }

            Row {
                id: row1
                width: 220
                height: 37
                spacing: 12

                Text {
                    id: txt2
                    text: "Pression"
                    font.pixelSize: rectangle.height/20
                    font.family: sansGuiltMB.name
                    color: "#0085CA"
                }

                TextEdit {
                    id: textEdit1
                    width: 80
                    height: 20
                    text: qsTr("Text Edit")
                    font.pixelSize: 12
                }
            }


        }

    }

    Row {
        id: row2
        y: 311
        width: 200
        height: 39
        anchors.left: rectangle.left
        anchors.leftMargin: 7

        Text {
            id: txt3
            text: "humidité"
            anchors.fill: parent
            font.pixelSize: rectangle.height/20
            font.family: sansGuiltMB.name
            color: "#0085CA"
        }

        TextEdit {
            id: textEdit2
            text: qsTr("Text Edit")
            anchors.left: txt3.right
            anchors.leftMargin: -102
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 19
            anchors.right: parent.right
            anchors.rightMargin: 22
            anchors.top: parent.top
            anchors.topMargin: 0
            font.pixelSize: 12
        }
    }

}






































































































/*##^## Designer {
    D{i:2;anchors_y:157}D{i:3;anchors_y:8}D{i:4;anchors_height:19;anchors_width:536;anchors_x:0;anchors_y:8}
D{i:1;anchors_height:372;anchors_width:534;anchors_x:55;anchors_y:55}D{i:13;anchors_height:30;anchors_width:98}
D{i:14;anchors_height:20;anchors_width:80}D{i:12;anchors_x:194}
}
 ##^##*/
