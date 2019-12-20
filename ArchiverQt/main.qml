import QtQuick 2.5
import QtQuick.Window 2.5
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3




ApplicationWindow {
    visible: true
    width: 640
    height: 480
    minimumHeight: 480
    minimumWidth: 600

    Material.theme: menu.themeSwitch.checked ? Material.Dark : Material.Light
    Material.accent: menu.themeSwitch.checked ? Material.Red : Material.Blue

    menuBar: ProjectMenuBar {
        id: menu

    }


    Loader{
        id: pageLoader
        anchors.fill: parent
        source: "CreateView.qml"
    }









    title: qsTr("TPRK Архиватор")
}
