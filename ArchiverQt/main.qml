import QtQuick 2.5
import QtQuick.Window 2.5
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3
import tprk.engine 1.0



ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    minimumHeight: 480
    minimumWidth: 600

    Material.theme: menu.themeSwitch.checked ? Material.Dark : Material.Light
    Material.accent: menu.themeSwitch.checked ? Material.Red : Material.Blue
    flags: menu.isFullscreen.checked ? Qt.FramelessWindowHint : Qt.MSWindowsOwnDC
    visibility: menu.isFullscreen.checked ? Qt.WindowFullScreen : Qt.WindowMinimized

    menuBar: ProjectMenuBar {
        id: menu

    }

    QtView {
        id:core
    }



    Loader{
        id: pageLoader
        anchors.fill: parent
        source: "HomeView.qml"
    }





        Text {

            id: copyright
            text: qsTr("Created by TPRK team. All rights reserved")
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: parent.height*0.03
            anchors.bottomMargin: parent.height*0.04
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            color: Material.accent
            font.bold: true
        }




    title: qsTr("TPRK Архиватор")
}
