import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13

ColumnLayout {
    anchors.fill: parent

    RowLayout {
        Layout.fillHeight: true
        Layout.fillWidth: true

        Label {
            text: qsTr("Кол-во ячеек:")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: true
        }

        SpinBox {
            editable: true

            validator: IntValidator {
                bottom: 0
                top: 100
            }
        }
    }

    RowLayout {
        Layout.fillHeight: true
        Layout.fillWidth: true

        Label {
            text: qsTr("Кол-во мух:")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillWidth: true
        }

        SpinBox {
            editable: true

            validator: IntValidator {
                bottom: 0
                top: 100
            }
        }
    }

    ListView {
        Layout.fillHeight: true
        Layout.fillWidth: true

        model: FliesModel
        delegate: RowLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Label {
                text: name

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.WordWrap
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.fillWidth: true
            }

            SpinBox {
                Layout.fillWidth: true

                editable: true

                value: stupidity

                validator: IntValidator {
                    bottom: 0
                    top: 100
                }
            }
        }
    }

    Rectangle {
        Layout.fillHeight: true
        Layout.fillWidth: true
        opacity: 0
    }
}
/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

