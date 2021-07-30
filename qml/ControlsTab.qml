import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13

RowLayout {
    Button {
        id: playButton

        icon.source: "res/play.png"
        icon.color: Material.color(Material.Green)

        //        visible: (MainWindowHandler === null) ? false : MainWindowHandler.playButtonVisability
        onClicked: {

            //            MainWindowHandler.playButtonClicked()
        }
    }

    Button {
        id: stopButton

        icon.source: "res/stop.png"
        icon.color: Material.color(Material.Red)

        //        visible: (MainWindowHandler === null) ? false : MainWindowHandler.stopButtonVisability
        onClicked: {

            //            MainWindowHandler.stopButtonClicked()
        }
    }

    Rectangle {
        Layout.fillWidth: true
        opacity: 0
    }

    RowLayout {
        Layout.maximumWidth: parent.width * 0.3
        Layout.fillWidth: true

        Label {
            Layout.fillWidth: true

            text: qsTr("Cells in side:")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        SpinBox {
            Layout.fillWidth: true

            value: (BoardModel != null) ? BoardModel.gridSide : 0

            editable: true
            validator: IntValidator {
                bottom: 1
                top: 100
            }

            onValueChanged: {
                if (BoardModel != null)
                    BoardModel.gridSide = value
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
