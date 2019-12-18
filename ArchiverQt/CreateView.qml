import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.LocalStorage 2.0
import QtQuick.Dialogs 1.3
Item {






    Button {
        id: button
        x: 246
        y: 278
        text: qsTr("close")
        onClicked: {
            fileDialog.open()
        }
    }


    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)

        }
        onRejected: {
            console.log("Canceled")
            pageLoader.source = "HomeView.qml"
        }
    }

}

