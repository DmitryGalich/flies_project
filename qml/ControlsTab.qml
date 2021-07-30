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

        onClicked: {

        }
    }

    Button {
        id: stopButton

        icon.source: "res/stop.png"
        icon.color: Material.color(Material.Red)

        onClicked: {

        }
    }

    Rectangle {
        Layout.fillWidth: true
        Layout.minimumWidth: parent.width * 0.1

        opacity: 0
    }

    RowLayout {
        Layout.fillWidth: true

        Label {

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
        Layout.minimumWidth: parent.width * 0.1

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
    D{i:0;height:461;width:636}
}
##^##*/

