import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13
import QtGraphicalEffects 1.0

RowLayout {
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

    ColumnLayout {
        Layout.fillWidth: true
        Layout.fillHeight: true

        Label {
            Layout.fillWidth: true
            Layout.fillHeight: true

            text: qsTr("Flies project")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
            font.capitalization: Font.AllUppercase
            textFormat: Text.AutoText
            font.bold: true
            font.pointSize: 15

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            color: Material.accentColor
        }
        Label {
            Layout.fillWidth: true
            Layout.fillHeight: true

            text: qsTr("version 0.1")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
            font.bold: true
            font.pointSize: 8

            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }
}
