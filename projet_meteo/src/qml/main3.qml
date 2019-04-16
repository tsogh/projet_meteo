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
            //anchors.topMargin: 8
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
                    id: msg_tmp
                    text: qsTr("<b>Température</b><br>%1°")
                    anchors.centerIn: rec11
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
                    id: msg_press
                    text: qsTr("<b>Pression</b><br>%1hPa")
                    anchors.centerIn: rec12
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
                    id: msg_humi
                    text: qsTr("<b>Humidité</b><br>%1%")
                    anchors.centerIn: rec13
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
                    id: des
                    text: qsTr("<b>description du temps</b>")
                    x: 0
                    //y: element5.y +50
                    width: rec2.width
                    anchors.centerIn: rec23
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: rec2.height/20
                }


            }
        }
    }

	function update() {
	var t = "<b>Température</b><br>%1°C"
        var p = "<b>Pression</b><br>%1hPa"
        var h = "<b>Humidité</b><br>%1%"
        var d = "<b>%1</b>"
        var f= "%1.svg"
	var img="%1.svg"
        capt.refresh()
        msg_tmp.text = t.arg(capt.temp.toFixed(2))
        msg_humi.text = h.arg(capt.humi)
        msg_press.text = p.arg(capt.press.toFixed(2))
	image1.source=img.arg(capt.img)
        des.text=d.arg(capt.des)
        image2.source=f.arg(capt.fleche)
    }
	Timer {
		id: globalTimer
		interval: 1000
		repeat: true
		running: true
		triggeredOnStart: true
		onTriggered: update()
	}
}
