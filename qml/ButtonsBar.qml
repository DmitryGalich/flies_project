import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13
import QtGraphicalEffects 1.0

RowLayout {

    //    Button {
    //        id: settingsButton

    //        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
    //        Layout.fillWidth: true

    //        icon.source: "res/settings.png"

    //        onClicked: {
    //            settingsDrawer.open()
    //        }
    //    }
    Button {
        id: playButton

        icon.source: "res/play.png"
        icon.color: Material.color(Material.Green)

        visible: (MainWindowHandler === null) ? false : MainWindowHandler.playButtonVisability

        onClicked: {
            MainWindowHandler.playButtonClicked()
        }
    }

    Button {
        id: stopButton

        icon.source: "res/stop.png"
        icon.color: Material.color(Material.Red)

        visible: (MainWindowHandler === null) ? false : MainWindowHandler.stopButtonVisability

        onClicked: {
            MainWindowHandler.stopButtonClicked()
        }
    }
    Rectangle {
        Layout.fillWidth: true
        opacity: 0
    }

    RowLayout {
        //        Layout.minimumWidth: parent.width * 0.2
        Layout.maximumWidth: parent.width * 0.3
        Layout.fillWidth: true

        Label {
            Layout.fillWidth: true

            text: qsTr("Cells:")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        SpinBox {
            Layout.fillWidth: true

            editable: true
            validator: IntValidator {
                bottom: 1
                top: 100
            }
        }
    }

    Rectangle {
        Layout.fillWidth: true
        opacity: 0
    }

    Button {
        id: flyButton

        icon.source: "res/fly.png"

        onClicked: {

        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:5}
}
##^##*/

