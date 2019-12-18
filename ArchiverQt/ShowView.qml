import QtQuick 2.0
import QtQuick.Dialogs 1.2

Item {
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
        Component.onCompleted: visible = true

    }
}
