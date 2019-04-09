import QtQuick 2.0
import QtQuick.Window 2.0

Window
{
    visible: true
    width: 300
    height: 240
    color: "black"
    
    
    Rectangle {
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        color: "white"
        Text{
            id: msg
            y: 20
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 20
            text: "<b>Météo à Toulouse (France)</b>"
            color: "red"
        }
        
    }
    Rectangle {
        id: rect1
        x: parent.width /2
        y: parent.height /10
        width: parent.width /2
        height: parent.height
        anchors.left: parent.left
        anchors.topMargin: 50
        anchors.bottomMargin: 50
        color: "black"
        
        Rectangle {
            id: rect2
            x: rect1.width /2
            y: 30
            width: rect1.width /2
            height: rect1.height /8
            anchors.horizontalCenter: rect1.horizontalCenter
            anchors.topMargin: rect1.topMargin
            color: "blue"
        }
        
        Rectangle {
            id: rect3
            x: parent.width /2
            y: 30
            width: parent.width /2
            height: parent.height /8
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            color: "violet"
        }
        
        Rectangle {
            id: rect4
            x: rect1.width /2
            y: parent.bottomMargin
            width: rect1.width /2
            height: rect1.height /8
            //anchors.horizontalCenter: parent.horizontalCenter
            anchors { horizontalCenter: rect1.horizontalCenter; top: rect1.top; topMargin: 180 }
            color: "green"
        }
    }
    
    Rectangle {
        x: parent.width /2
        y: parent.height /10
        width: parent.width /2
        height: parent.height
        anchors.right: parent.right
        color: "magenta"
    }
    /*  Rectangle {
     *   x: 0
     *   y: 0
     *   width: parent.width
     *   height: parent.height /2
     *   color: "darkmagenta"
}
*/
}
