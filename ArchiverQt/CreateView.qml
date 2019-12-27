
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
        font.pointSize: parent.height*0.05
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
    Keys.onEnterPressed: show.view.enter()
    ShowFiles {
        id:show
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenterOffset: -parent.height*0.165
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width*0.8
        height: parent.height*0.5
        view.model: FileModel {
         id:fileModel
        }

    }




    ProjectButton {
        id: choose_button

        width: parent.width*0.38
        height: parent.height*0.15
        text: qsTr("Выбрать файлы")
        font.pointSize: parent.height*0.03
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
                    fileModel.append({text: fileUrls[i]})
                    core.addFiles(fileUrls[i].toString().replace("file://",""))
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
        width: parent.width*0.38
        height: parent.height*0.15
        text: qsTr("Заархивировать")
        font.pointSize: parent.height*0.03
        anchors.bottomMargin: parent.height*0.1
        anchors.rightMargin: parent.width*0.1
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        enabled: fileModel.count === 0 || core.archive_name === "" ? false :true
        onPressed: {
            save.open();
            console.log ("Archive files event")

        }
    }

    FileDialog {
        id: folder
        title: "Please choose a folder"
        folder: shortcuts.documents
        selectMultiple: false
        selectFolder: true
        onAccepted: {
            console.log("file would be save at: " + fileUrls)
            showPath.clear()
            showPath.append ({text: fileUrl})
            //TODO модель на с++ и отправка файлов в модель
        }
        onRejected: {
            console.log("Canceled")
        }
    }
    PathModel {
        id: showPath

    }

    TextField {
        id: archiverName
        y: 307
        text: qsTr("")
        font.pointSize: parent.height*0.07
        horizontalAlignment: Text.AlignHCenter
        anchors.bottomMargin: parent.height*0.25
        anchors.bottom: parent.bottom
        anchors.leftMargin: parent.width*0.1
        anchors.left: parent.left
        anchors.horizontalCenter: parent.horizontalCenter
        placeholderText: "Введите имя архива"
        onTextChanged: {
            core.archive_name = text
            console.log(core.archive_name)
        }
    }

    FileDialog {
        id: save
        title: "Please choose a folder"
        folder: shortcuts.documents
        selectMultiple: false
        selectFolder: true
        onAccepted: {
            console.log("dearchive at: " + fileUrls)
            showPath.clear()
            showPath.append ({text: fileUrl})
            core.savepath = fileUrl.toString().replace("file://", "")
            core.archiveFiles()
            console.log(core.savepath)
            core.clear()
                if (core.success) {
                    pageLoader.source = "SuccessMessage.qml"
                } else {
                    pageLoader.source = "ErrorMessage.qml"
                }

        }
        onRejected: {
            console.log("Canceled")
        }
    }

}





/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_height:200;anchors_width:200;anchors_x:73;anchors_y:323}
D{i:9;anchors_x:143}
}
##^##*/
