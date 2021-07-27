import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13
import QtGraphicalEffects 1.0

ApplicationWindow {
    minimumHeight: 480
    minimumWidth: 640

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    visible: true

    title: qsTr("Flyes project")

    RowLayout {
        anchors.fill: parent

        ColumnLayout {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.maximumWidth: parent.width * 0.05

            Button {
                id: settingsButton

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillWidth: true

                icon.source: "res/settings.png"
            }

            Button {
                id: playButton

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillWidth: true

                icon.source: "res/play.png"
                icon.color: Material.color(Material.Green)

                visible: (MainWindowHandler
                          === null) ? false : MainWindowHandler.playButtonVisability

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

                visible: (MainWindowHandler
                          === null) ? false : MainWindowHandler.stopButtonVisability

                onClicked: {
                    MainWindowHandler.stopButtonClicked()
                }
            }
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:5}
}
##^##*/

