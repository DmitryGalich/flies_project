import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13
import QtGraphicalEffects 1.0

ColumnLayout {
    Button {
        id: settingsButton

        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        Layout.fillWidth: true

        icon.source: "res/settings.png"

        onClicked: {
            settingsDrawer.open()
        }
    }

    Rectangle {
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        opacity: 0
    }

    Button {
        id: playButton

        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        Layout.fillWidth: true

        icon.source: "res/play.png"
        icon.color: Material.color(Material.Green)

        visible: (MainWindowHandler === null) ? false : MainWindowHandler.playButtonVisability

        onClicked: {
            MainWindowHandler.playButtonClicked()
        }
    }

    Button {
        id: stopButton

        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        Layout.fillWidth: true

        icon.source: "res/stop.png"
        icon.color: Material.color(Material.Red)

        visible: (MainWindowHandler === null) ? false : MainWindowHandler.stopButtonVisability

        onClicked: {
            MainWindowHandler.stopButtonClicked()
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:5}
}
##^##*/

