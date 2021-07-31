import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13
import QtQuick.Dialogs 1.2

Popup {
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

    ColumnLayout {
        anchors.fill: parent

        RowLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true

            Rectangle {
                Layout.fillWidth: true
                opacity: 0
            }

            Label {
                Layout.fillWidth: true
                text: "Fly settings"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.capitalization: Font.AllUppercase
                font.bold: true
                font.pointSize: 12
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }

            Button {
                icon.source: "res/close.png"
                onClicked: close()
            }
        }

        ColumnLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.maximumHeight: parent.height * 0.8

            RowLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true

                Label {
                    Layout.fillWidth: true
                    Layout.minimumWidth: parent.width * 0.4
                    Layout.fillHeight: true

                    text: qsTr("Name:")
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WordWrap

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                TextEdit {
                    Layout.fillWidth: true
                    Layout.minimumWidth: parent.width * 0.5
                    Layout.fillHeight: true

                    color: "white"
                    selectedTextColor: Material.color(Material.accent)
                    selectionColor: Material.color(Material.accent)

                    text: "kek"
                    font.pixelSize: 15
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WordWrap
                    font.bold: false
                    font.italic: true

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }
            }

            RowLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true

                Label {
                    Layout.fillWidth: true
                    Layout.minimumWidth: parent.width * 0.4
                    Layout.fillHeight: true

                    text: qsTr("Age:")
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WordWrap

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                Label {
                    Layout.fillWidth: true
                    Layout.minimumWidth: parent.width * 0.5
                    Layout.fillHeight: true

                    text: qsTr("KEK")
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WordWrap

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }
            }

            RowLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true

                Label {
                    Layout.fillWidth: true
                    Layout.minimumWidth: parent.width * 0.4

                    text: qsTr("Stupidity:")
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WordWrap

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                SpinBox {
                    id: capacitySpinBox

                    Layout.fillWidth: true
                    Layout.minimumWidth: parent.width * 0.5

                    editable: true
                    validator: IntValidator {
                        bottom: 1
                        top: 10
                    }

                    onValueChanged: {
                        if (value < 1)
                            value = 1

                        if (value > 10)
                            value = 10
                    }
                }
            }

            RowLayout {
                Layout.fillHeight: true
                Layout.fillWidth: true

                Label {
                    Layout.fillWidth: true
                    Layout.minimumWidth: parent.width * 0.4

                    text: qsTr("Cell:")
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WordWrap

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                }

                SpinBox {
                    id: cellChooser

                    Layout.fillWidth: true
                    Layout.minimumWidth: parent.width * 0.5

                    editable: true
                    validator: IntValidator {
                        bottom: 1
                        top: 10
                    }

                    onValueChanged: {
                        if (value < 1)
                            value = 1

                        if (value > 10)
                            value = 10
                    }
                }
            }

            Rectangle {
                Layout.fillHeight: true
                Layout.fillWidth: true
                opacity: 0
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

