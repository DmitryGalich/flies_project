import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13
import QtGraphicalEffects 1.0

ColumnLayout {
    anchors.fill: parent

    RowLayout {
        Layout.margins: 5
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.minimumHeight: parent.height * 0.1
        Layout.maximumHeight: parent.height * 0.1

        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        Image {
            id: icon
            verticalAlignment: Image.AlignBottom
            Layout.fillWidth: true
            Layout.fillHeight: true
            source: "res/fly.png"
            fillMode: Image.PreserveAspectFit

            ColorOverlay {
                anchors.fill: icon
                source: icon
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                color: Material.accent
            }
        }

        Label {
            Layout.fillWidth: true

            text: qsTr("Flies project 0.1")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
            Layout.bottomMargin: 5
            font.bold: true
            font.pointSize: 15

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            color: Material.accentColor
        }
    }

    TabBar {
        id: tabBar
        Layout.fillWidth: true

        TabButton {
            text: qsTr("Flyes")
        }
        TabButton {
            text: qsTr("Board")
        }
    }

    StackLayout {
        Layout.fillWidth: true
        Layout.fillHeight: true

        currentIndex: tabBar.currentIndex

        SettingsTabFlies {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        SettingsTabBoard {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

