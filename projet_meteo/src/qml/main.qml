import QtQuick 2.2
import QtQuick.Window 2.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4


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
        gradient: Gradient {
            GradientStop { id: radian ;position: 0.0; color: "#1e90ff" }
            GradientStop { position: 1.0; color: "white" }
            }
            //color: "#00008b"
            //color: "#00bfff"

            Text{
                id :msg_titre
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
                id: recdate
                x: 10
                y: 10
                width: rec.width/4
                height: rec.height/20
                anchors.right: rec.right
                color: "transparent"

                Text{
                    id: info
                    text: "<b>"+new Date().toLocaleDateString(Qt.locale("fr_FR"), "ddd dd MM yyyy ") +" "+ new Date().toLocaleTimeString(Qt.locale("fr_FR"),"hh:mm") +"</b>"
                    color: "black"
                    anchors.centerIn: recdate
                    width: recdate.width
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: recdate.height/2
                }

            }
            Rectangle {
                id: recbouton1
                x: 10
                y: 10
                color: "grey"
                width: rec.width/8
                height: rec.height/20
                anchors.left: rec.left

                Text{
                    id: bouton_config
                    text: qsTr("<b>Configuration</b>")
                    anchors.centerIn: recbouton1
                    width: recbouton1.width
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: recbouton1.height/2
                }
                MouseArea{
                    id: buttonMouseArea
                    anchors.fill: recbouton1
                    //onClicked: console.log(" clicked" )
                    onClicked: { popup.open();globalTimer.stop();}
                }

                Popup {
                id:popup;
                width: 175
                height: 130
                x:10
            Column{
                    Text {
                        id: titre_popup
                        color:"#1e90ff"
                        text: qsTr("<b>Configuration :</b>")
                    }
            Row{
                    Text {
                        id: text_ville
                        text: qsTr("<b>Ville : </b>")
                    }
                    TextInput{
                        id: msg_ville
                        color: "black"
                        text: "Toulouse"


                    }

                }
                Row{
                    Text {
                        id: text_alti
                        text: qsTr("<b>Altitude : </b>")
                    }
                    TextInput {
                        color: "black"
                        id: msg_alti
                        text: "151"

                    }

            }
            Row{    width: 30
                    height: 20}
            Row{
            x:100
                Button{
                    id: bouton_ok
                    text: qsTr("<b>ok</b>")
                    width: 40
                    height: 30
                    onClicked: {popup.close()
                                maj_config()
                                }

                }

                }

            }
                }


            }


            Rectangle {
                id:rec1
                x: rec.width /2
                y: 50
                width: rec.width/2
                height: rec.height -50
                anchors.left: rec.left
                color: "transparent"

                Rectangle {
                    id:rec11
                    x:0
                    y:0
                    width: rec1.width
                    height: rec1.height/4
                    color: "transparent"
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
                    height: rec1.height/4
                    color: "transparent"
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
                    height: rec1.height/4
                    color: "transparent"
                    Text {
                        id: msg_humi
                        text: qsTr("<b>Humidité</b><br>%1%")
                        anchors.centerIn: rec13
                        width: rec1.width
                        horizontalAlignment: Text.AlignHCenter
                        font.pixelSize: rec1.height/20
                    }


                }Rectangle {
                    id:rec14
                    x:0
                    y:rec12.height*2.8
                    width: rec1.width
                    height: rec1.height/4
                    color: "transparent"
                    Text {
                        id: msg_altitude
                        text: qsTr("<b>Altitude</b><br>%1%")
                        anchors.centerIn: rec14
                        width: rec1.width/2
                        horizontalAlignment: Text.AlignHCenter
                        font.pixelSize: rec1.height/30
                    }

                }
                /*Rectangle {
                    id:rec15
                    x:2
                    y:rec12.height*3.2
                    width: rec1.width
                    height: rec1.height/4
                    color: "transparent"
                    Text {
                        id: msg_levee_soleil
                        text: qsTr("<b>Lever : </b>7:10  &nbsp; <b>Coucher : </b>22:00")
                        anchors.centerIn: rec15
                        width: rec1.width/2
                        horizontalAlignment: Text.AlignHCenter
                        font.pixelSize: rec1.height/30
                    }

                }*/

            }

            Rectangle {
                id:rec2
                x: rec.width/2
                y: 50
                width: rec.width/2
                height: rec.height -50
                anchors.right: rec.right
                color: "transparent"
                Rectangle {
                    id:rec21
                    x:0
                    y:0
                    width: rec2.width
                    height: rec2.height/2.1
                    color: "transparent"
                    Image {
                        id: image_meteo
                        sourceSize.width: Math.min(rec21.width,rec21.height)
                        sourceSize.height: Math.min(rec21.width,rec21.height)
                        anchors.centerIn: rec21
                        scale: Qt.KeepAspectRatio*1.6
                        source: "img/day.svg"
                    }

                }Rectangle {
                    id:rec22
                    x:0
                    y: rec21.height
                    width: rec2.width
                    height: rec2.height/2.9
                    color: "transparent"
                    Image {
                        id: image_fleche
                        x: 0
                        sourceSize.width: Math.min(rec22.width,rec22.height)
                        sourceSize.height: Math.min(rec22.width,rec22.height)
                        anchors.centerIn: rec22
                        source: "img/Steady.svg"
                        scale: Qt.KeepAspectRatio/2
                        visible: false
                    }
                    ColorOverlay{
                        id:color_fleche
                        scale: Qt.KeepAspectRatio/2
                        anchors.fill: image_fleche
                        source:image_fleche
                        //transform: Rotation { origin.x:rec22.x/2; origin.y:rec22.y/2; angle: 45}
                        color:"red"

                    }

                }Rectangle {
                    id:rec23
                    x:0
                    y: rec21.height*1.69
                    width: rec2.width
                    height: rec2.height/5
                    color: "transparent"
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

           var titre = "<b>Météo à %1</b>"
        var temp = "<b>Température</b><br>%1°C"
        var press = "<b>Pression</b><br>%1hPa"
        var humi = "<b>Humidité</b><br>%1%"
        var desc = "<b>%1</b>"
        var weather= "img/%1.svg"
        var time="%1 %2"
        var fleche="img/%1.svg"
        var col="%1"
        var alti="<b>Altitude</b><br>%1m"
        capt.refresh()
        if(capt.fleche=="Falling"){color_fleche.color="red";}
        if(capt.fleche=="Steady"){color_fleche.color="green";}
        if(capt.fleche=="Rising"){color_fleche.color="yellow";}
        msg_tmp.text = temp.arg(capt.temp.toFixed(0))
        msg_humi.text = humi.arg(capt.humi.toFixed(0))
        msg_press.text = press.arg(capt.press.toFixed(1))
        info.text="<b>"+new Date().toLocaleDateString(Qt.locale("fr_FR"), "ddd dd MM yyyy ") +" "+ new Date().toLocaleTimeString(Qt.locale("fr_FR"),"hh:mm") +"</b>"
        image_fleche.source=fleche.arg(capt.fleche)
        //info.txt=time.arg(new Date().toLocaleDateString(Qt.locale("fr_FR"), "ddd dd MM yyyy "),new Date().toLocaleTimeString(Qt.locale("fr_FR"),"hh:mm"))
        des.text=desc.arg(capt.des)
        image_meteo.source=weather.arg(capt.img)
        radian.color=col.arg(capt.color)
        msg_altitude.text=alti.arg(capt.alti.toFixed(0))
        msg_titre.text=titre.arg(msg_ville.text);
        //console.log("test2"+msg_ville.text);


    }
    function maj_config(){
    var t = "<b>Météo à %1</b>"
    globalTimer.start();
    console.log("test"+msg_alti.text);
    capt.alti=msg_alti.text;
    //msg_titre.text=t.arg(msg_ville.text);
    //msg_titre.text="pink";

    }
    function update_demo() {
    var titre = "<b>Météo à %1</b>"
        var t = "<b>Température</b><br>%1°C"
        var p = "<b>Pression</b><br>%1hPa"
        var h = "<b>Humidité</b><br>%1%"
        var d = "<b>%1</b>"
        var f= "%1.svg"
        var time="%1 %2"
        var img="%1.svg"
        var c="%1"
        capt.refresh_demo()

        msg_tmp.text = t.arg(capt.temp.toFixed(0))
        msg_humi.text = h.arg(capt.humi.toFixed(0))
        msg_press.text = p.arg(capt.press.toFixed(1))
        info.text="<b>"+new Date().toLocaleDateString(Qt.locale("fr_FR"), "ddd dd MM yyyy ") +" "+ new Date().toLocaleTimeString(Qt.locale("fr_FR"),"hh:mm") +"</b>"
        image1.source=img.arg(capt.img)
        //info.txt=time.arg(new Date().toLocaleDateString(Qt.locale("fr_FR"), "ddd dd MM yyyy "),new Date().toLocaleTimeString(Qt.locale("fr_FR"),"hh:mm"))
        des.text=d.arg(capt.des)
        image2.source=f.arg(capt.fleche)
        radian.color=c.arg(capt.color)
        msg_titre.text=titre.arg(msg_tmp.text);
        console.log("test2"+msg_alti);




    }
    function upadate_lever_couche(){
    console.log("okkkkk")
        var leve = "<b>Lever : </b>%1 &nbsp; <b>Coucher : </b>%2"
        var xhr = new XMLHttpRequest();
        var url = "http://api.sunrise-sunset.org/json?lat=36.7201600&lng=-4.4203400";
        xhr.open("GET", url, true);
        xhr.setRequestHeader("Content-Type", "application/json");
        xhr.onreadystatechange = function () {
            if (xhr.readyState === 4 && xhr.status === 200) {
                var json = JSON.parse(xhr.responseText);
                msg_levee_soleil.text=leve.arg(JSON.parse(JSON.stringify(json.results)).sunrise,JSON.parse(JSON.stringify(json.results)).sunset)
                console.log(JSON.parse(JSON.stringify(json.results)).sunrise);

            }
        };

    }

    Timer {
        id: globalTimer
        interval: 1000
        repeat: true
        running: true
        triggeredOnStart: true
        onTriggered: update()
    }
        Timer {
        id: globalTimer2
        interval: 1000
        repeat: true
        running: true
        triggeredOnStart: true
        onTriggered: actu_vec()
    }

}
