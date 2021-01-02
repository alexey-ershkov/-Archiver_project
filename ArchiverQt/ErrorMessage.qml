import QtQuick 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Material 2.3

Item {
    id: element
    anchors.fill: parent

    Image {
        id: image
        x: 270
        width: parent.width*0.7
        height: parent.height*0.5
        anchors.topMargin: parent.height*0.05
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        source: "Error.png"
        fillMode: Image.PreserveAspectFit
    }

    ProjectButton {
        id: success_button
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width*0.6
        height: parent.height*0.15
        text: core.message
        font.pointSize: parent.height*0.03
        anchors.bottomMargin: parent.height*0.15
        anchors.bottom: parent.bottom
        onClicked: {
            pageLoader.source = "HomeView.qml"
        }
    }
}


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_y:156}
}
##^##*/
