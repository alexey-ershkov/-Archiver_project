import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import QtQuick.LocalStorage 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Universal 2.3



Item {


    anchors.fill: parent
    focus: true
    Keys.onUpPressed: show.view.up()
    Keys.onDownPressed: show.view.down()
    ShowFiles {
        id:show
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width*0.8
        height: parent.height*0.6
        view.model: FileModel {
         id:fileShow
        }

    }


    ProjectButton {
        id: choose_button
        x: 109
        y: parent.height*0.6
        width: parent.width*0.7
        height: parent.height*0.15
        text: qsTr("Выбрать файлы")

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
                for (var i = 0; i < fileUrls.length; ++i) {
                    console.log (fileUrls[i])
                    fileShow.append({text: fileUrls[i]})
                }

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
