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

    Connections {
        target: FliesModel

        onOpenFlyAdditionWindow: {
            visible = true

            nameWidget.text = default_name
            cellWidget.to = cells_max
            ageWidget.text = "0"
            stupidityWidget.to = stupidity_max
        }
    }

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
                Layout.fillHeight: true

                text: "Fly settings"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.capitalization: Font.AllUppercase
                font.bold: true
                font.pointSize: 12
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }

            Button {
                Layout.fillHeight: true

                icon.source: "res/close.png"
                onClicked: close()
            }
        }

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
                id: nameWidget

                Layout.fillWidth: true
                Layout.minimumWidth: parent.width * 0.5
                Layout.fillHeight: true

                color: "white"
                selectedTextColor: Material.color(Material.accent)
                selectionColor: Material.color(Material.accent)

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

                text: qsTr("Stupidity:")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.WordWrap
                Layout.fillHeight: true

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }

            SpinBox {
                id: stupidityWidget

                height: nameWidget.height

                Layout.fillWidth: true
                Layout.minimumWidth: parent.width * 0.5

                from: 1

                editable: true
                validator: IntValidator {}

                onValueChanged: {
                    if (value < 1)
                        value = 1

                    if (value > to)
                        value = to
                }

                onValueModified: {
                    if (value < 1)
                        value = 1

                    if (value > to)
                        value = to
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
                Layout.fillHeight: true

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }

            SpinBox {
                id: cellWidget

                function configure(cellsCount) {
                    to = cellsCount
                    validator.top = cellsCount
                }

                height: nameWidget.height

                Layout.fillWidth: true
                Layout.minimumWidth: parent.width * 0.5

                editable: true
                validator: IntValidator {
                    id: cellWidgetValidator
                }

                onValueModified: {
                    if (value > to)
                        value = to
                }

                onValueChanged: {
                    if (value > to)
                        value = to
                }
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
                id: ageWidget

                Layout.fillWidth: true
                Layout.minimumWidth: parent.width * 0.5

                height: nameWidget.height

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.WordWrap
                color: Material.color(Material.Grey)

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }
        }

        RowLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true

            Button {
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: qsTr("Apply")

                enabled: (nameWidget.text.length > 0)

                onClicked: {
                    FliesModel.addFly(nameWidget.text, stupidityWidget.value,
                                      cellWidget.value)
                    onClicked: close()
                    BoardModel.updateModel()
                }
            }

            Button {
                Layout.fillHeight: true
                Layout.fillWidth: true
                text: qsTr("Cancel")

                onClicked: close()
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

