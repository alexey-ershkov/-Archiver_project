import QtQuick 2.0
import QtQuick.Controls 2.5



MenuBar {
    property var themeSwitch: themeSwitch
    Menu {
        title: qsTr("Файл")
        Action {
            text: qsTr("Создать архив")
            onTriggered: pageLoader.source = "CreateView.qml"
        }
        Action {
            text: qsTr("Открыть архив")
            onTriggered: pageLoader.source = "ShowView.qml"
        }
        MenuSeparator { }
        Action { text: qsTr("Выйти")
            onTriggered: Qt.quit()
        }
    }
    Menu {
        title: qsTr("Вид")
        Action {

            id: themeSwitch
            text: qsTr("Темная тема")
            checkable: true
        }
    }
    Menu {
        title: qsTr("Cправка")
        Action { text: qsTr("Исходники")
            onTriggered:  Qt.openUrlExternally("https://github.com/alexey-ershkov/Archiver_project")
        }
        Action { text: qsTr("О нас") }
    }
    MenuSeparator{}
    Menu {
        title: qsTr("Home")

    }
}
