import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: general

    minimumHeight: 480
    minimumWidth: 640

    Material.theme: Material.Dark
    Material.accent: Material.color(Material.Green)

    visible: true

    title: qsTr("Flies project")

    Connections {
        target: FliesModel

        onOpenFlyAdditionWindow: {
            flySettings.visible = true
        }
    }

    ColumnLayout {
        anchors.fill: parent

        ControlsTab {
            Layout.rightMargin: 5
            Layout.leftMargin: 5
            Layout.margins: 2
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Board {
            id: board
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

    CellSettings {
        width: 400
        height: 120

        x: parent.width * 0.5 - width * 0.5
        y: parent.height * 0.5 - height * 0.5

        onSetCellCapacity: {
            board.setCellCapacity(cellIndex, value)
        }
    }

    FlySettings {
        id: flySettings

        visible: true

        width: 400
        height: 240

        x: parent.width * 0.5 - width * 0.5
        y: parent.height * 0.5 - height * 0.5
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

