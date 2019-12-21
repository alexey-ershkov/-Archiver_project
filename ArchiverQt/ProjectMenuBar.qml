import QtQuick 2.0
import QtQuick.Controls 2.5



MenuBar {
    property var themeSwitch: themeSwitch
    property var isFullscreen: isFullscreen

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
        Action {
            id: isFullscreen
            text: qsTr("На весь экран")
            checkable: true
        }

    }
    Menu {
        title: qsTr("Cправка")
        Action { text: qsTr("Исходники")
            onTriggered:  Qt.openUrlExternally("https://github.com/alexey-ershkov/Archiver_project")
        }
        Menu {
            title: qsTr("О нас")
            Action { text: qsTr("Алексей Ершков")
                onTriggered:  Qt.openUrlExternally("https://vk.com/ershkov_alex")
            }
            Action { text: qsTr("Александр Долгавин")
                onTriggered:  Qt.openUrlExternally("https://vk.com/alexandr_879")
            }
            Action { text: qsTr("Артем Давтян")
                onTriggered:  Qt.openUrlExternally("https://vk.com/davtart")
            }
        }
    }

}
