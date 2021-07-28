import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13

ApplicationWindow {
    minimumHeight: 480
    minimumWidth: 640

    Material.theme: Material.Dark
    Material.accent: Material.color(Material.Green)

    visible: true

    title: qsTr("Flyes project")

    RowLayout {
        anchors.fill: parent

        ButtonsBar {
            Layout.margins: 2
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.maximumWidth: parent.width * 0.05
        }

        MainField {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

    Drawer {
        id: settingsDrawer

        width: 0.5 * parent.width
        height: parent.height
        interactive: true
        visible: true
        edge: Qt.LeftEdge

        SettingsBar {
            anchors.fill: parent

            Layout.margins: 2
        }


    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:5}
}
##^##*/

