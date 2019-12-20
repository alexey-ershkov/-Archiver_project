import QtQuick 2.5
import QtQuick.Window 2.5
import QtQuick.Controls 2.5



ApplicationWindow {
    visible: true
    width: 640
    height: 480
    minimumHeight: 480
    minimumWidth: 600


    Loader{
        id: pageLoader
        anchors.fill: parent
        source: "CreateView.qml"
    }



    title: qsTr("TPRK Архиватор")
}
