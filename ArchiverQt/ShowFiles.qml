import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import QtQuick.LocalStorage 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Universal 2.3

Item {


    property alias view: view








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

        anchors.margins: 10
        anchors.fill: parent
        spacing: 5
        keyNavigationEnabled: true
        clip: false

        highlight: Rectangle {
            color: "skyblue"
        }
        highlightFollowsCurrentItem: true

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
            height: 40

            Rectangle {
                focus: true
                anchors.margins: 5
                anchors.fill: parent
                radius: height / 2
                color: Universal.color(Universal.Emerald)
                border {
                    color: "black"
                    width: 1
                }

                Text {
                    anchors.centerIn: parent
                    color: "white"
                    renderType: Text.NativeRendering
                    text: model.text.replace(new RegExp("file:\/\/\/([A-Za-z0-9\-_~ ]+\/)+"),"")
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: view.currentIndex = model.index
                }

            }
        }
    }
}
