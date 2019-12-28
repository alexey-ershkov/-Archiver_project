import QtQuick 2.0

ListView {

    delegate: Rectangle {
        Text {
            id: filepath
            text: model.text
        }
    }
}
