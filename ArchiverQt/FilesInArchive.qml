import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import QtQuick.LocalStorage 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Material 2.3



Rectangle{


    property alias view: view


    border {
        width: 2
        color: Material.accent

    }

    ListView {
        id: view
        signal up()
        signal down()

        onUp: {
            if (view.currentIndex > 0) {
                currentIndex -= 1
            }
        }

        onDown: {
            if (view.currentIndex < view.count - 1) {
                currentIndex += 1;
            }
        }


        anchors.fill: parent
        spacing: 5
        keyNavigationEnabled: true
        clip: true



        flickableDirection: Flickable.VerticalFlick
        boundsBehavior: Flickable.StopAtBounds

        ScrollBar.vertical: ScrollBar {
            policy: ScrollBar.AsNeeded
            anchors.top: parent.top
            anchors.left: parent.right
            anchors.bottom: parent.bottom
        }
        delegate: Item {
            id: listDelegate

            property var view: ListView.view
            property var isCurrent: ListView.isCurrentItem

            width: view.width
            height: parent.parent.height*0.15

            Rectangle {

                focus: true
                anchors.margins: 5
                anchors.fill: parent
                color: isCurrent ? Material.accent : "white"
                border {
                    color: Material.accent
                    width: 1
                }

                Text {
                    font.pointSize: parent.height*0.5
                    anchors.centerIn: parent
                    color: isCurrent ? "white" : Material.accent
                    renderType: Text.NativeRendering
                    text: modelData
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: view.currentIndex = model.index
                }

            }
        }
    }
}
