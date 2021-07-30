import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13
import QtQuick.Dialogs 1.2

Popup {
    property var cellIndex: 0

    signal setCellCapacityValue(int cellIndex, int value)

    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

    Connections {
        target: BoardModel

        onSignalTopenCellSettingWindow: {
            cellIndex = cell_index
            capacitySpinBox.value = current_capacity
            visible = true
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
                text: "Cell settings"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                font.pointSize: 12
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }

            Button {
                icon.source: "res/close.png"
                onClicked: close()
            }
        }

        RowLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true

            Label {

                text: qsTr("Flies capacity:")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.WordWrap

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }

            SpinBox {
                id: capacitySpinBox
                Layout.fillWidth: true

                editable: true
                validator: IntValidator {
                    bottom: 1
                    top: 100
                }

                onValueChanged: {
                    setCellCapacityValue(cellIndex, value)
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

