
import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import QtQuick.LocalStorage 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Material 2.3




Item {
    id: element



    Text {
        color: Material.accent
        text: qsTr("Выбранные файлы")
        font.pointSize: 20
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.topMargin: parent.height*0.02
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }


    anchors.fill: parent
    focus: true
    Keys.onUpPressed: show.view.up()
    Keys.onDownPressed: show.view.down()
    ShowFiles {
        id:show
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenterOffset: -parent.height*0.
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width*0.8
        height: parent.height*0.5
        view.model: FileModel {
         id:fileShow
        }

    }


    ProjectButton {
        id: choose_button

        width: parent.width*0.35
        height: parent.height*0.15
        text: qsTr("Выбрать файлы")
        anchors.leftMargin: parent.width*0.1
        anchors.left: parent.left
        anchors.bottomMargin: parent.height*0.1
        anchors.bottom: parent.bottom

        onClicked: {
            theme: Material.Dark
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

    ProjectButton {
        id: archive_button
        x: -9
        y: 346
        width: parent.width*0.35
        height: parent.height*0.15
        text: qsTr("Зархивировать")
        anchors.bottomMargin: parent.height*0.1
        anchors.rightMargin: parent.width*0.1
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        enabled: fileShow.count === 0 ? false :true
        onPressed: {
            folder.open()
            console.log ("Archive files event")


        }
    }

    FileDialog {
        id: folder
        title: "Please choose a file"
        folder: shortcuts.documents
        selectMultiple: false
        selectFolder: true
        onAccepted: {
            console.log("file would be save at: " + fileUrl)

            pageLoader.source = "HomeView.qml"
            //TODO модель на с++ и отправка файлов в модель
        }
        onRejected: {
            console.log("Canceled")
        }
    }
}





/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_height:200;anchors_width:200;anchors_x:73;anchors_y:323}
}
##^##*/
