import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import QtQuick.LocalStorage 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Universal 2.3

Item {
    id: create_view_item
    width: parent.width
    height: parent.height

    ListModel {
        id: fileShow

    }

    Column {

        anchors.fill: parent
        model: fileShow

        ListView{
            id: view
            width: parent.width
            height: parent.height
            delegate: Rectangle{
                color: "red"
                width:view.width
                height: 40
                Text {
                  anchors.centerIn: parent
                  renderType: Text.NativeRendering
                  text: model.text || "old"
                  }

            }

        }
    }

    RoundButton{
        id: choose_button
        x: 109
        y: parent.height*0.6
        width: parent.width*0.7
        height: parent.height*0.15
        text: qsTr("Выбрать файлы")
        wheelEnabled: false
        spacing: 8
        hoverEnabled: true
        anchors.horizontalCenter: parent.horizontalCenter
        flat: false
        highlighted: true

        onClicked: {
            console.log("choose_button clicked")
            fileDialog.open();

        }


    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.documents
        selectMultiple: true
        onAccepted: {
            console.log("You chose: ")
            for (var i = 0; i < fileUrls.length; ++i)
                console.log (fileUrls[i])
            //TODO модель на с++ и отправка файлов в модель
        }
        onRejected: {
            console.log("Canceled")
        }
     }
 }





}


/*##^##
Designer {
    D{i:1;anchors_height:200;anchors_width:200;anchors_x:73;anchors_y:323}
}
##^##*/
