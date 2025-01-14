import QtQuick 2.4
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.LocalStorage 2.0
import QtQuick.Controls.Material 2.3
Item{
    id: home_view

    width: parent.width
    height: parent.height

    ProjectButton {
        id: new_button
        x: 119
        y: parent.height*0.4
        width: parent.width*0.7
        height: parent.height*0.15
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Создать новый архив")
        font.pointSize: parent.height*0.03


        onClicked: {
            console.log("new_button clicked")
            pageLoader.source = "CreateView.qml"
        }
    }

    ProjectButton {
        id: open_button
        x: 119
        y: parent.height*0.6
        width: parent.width*0.7
        height: parent.height*0.15
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Открыть архив")
        font.pointSize: parent.height*0.03

        onClicked: {
            console.log("open_button clicked")
            pageLoader.source = "ShowView.qml"
        }
    }

    Text {
        id: main
        x: 265
        color: Material.accent

        text: qsTr("TPRK Архиватор")
        renderType: Text.QtRendering
        anchors.topMargin: parent.height*0.2
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        fontSizeMode: Text.Fit
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 50
    }


}




