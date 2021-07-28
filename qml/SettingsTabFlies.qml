import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13

ColumnLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true

    RowLayout {
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        Layout.fillWidth: true
        Layout.fillHeight: true

        Label {
            Layout.fillWidth: true

            text: qsTr("Flies count:")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
            font.italic: false
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        SpinBox {
            Layout.fillWidth: true
            Layout.maximumWidth: parent.width * 0.5

            value: (FliesModel === null) ? false : FliesModel.fliesCount

            editable: true
            validator: IntValidator {
                bottom: 1
                top: 100
            }

            onValueChanged: {
                if (FliesModel != null)
                    FliesModel.setFliesCount(value)
            }
        }
    }

    RowLayout {
        Layout.bottomMargin: 10
        Layout.fillWidth: true
        Layout.fillHeight: true

        Label {
            Layout.fillWidth: true

            text: qsTr("Name")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
            font.italic: true
            font.bold: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Label {
            Layout.fillHeight: false
            Layout.fillWidth: true
            Layout.maximumWidth: parent.width * 0.5

            text: qsTr("Stupidity")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
            font.italic: true
            font.bold: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }

    ListView {
        id: listView
        boundsMovement: Flickable.StopAtBounds
        Layout.fillWidth: true
        Layout.fillHeight: true

        Layout.margins: 2
        topMargin: 2

        boundsBehavior: Flickable.StopAtBounds
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        model: FliesModel

        delegate: RowLayout {
            anchors.left: parent.left
            anchors.right: parent.right

            TextEdit {
                Layout.fillWidth: true
                Layout.minimumWidth: parent.width * 0.5
                Layout.maximumWidth: parent.width * 0.5

                text: name

                color: "white"

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.WordWrap
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                onTextChanged: {
                    if (FliesModel != null)
                        FliesModel.setFlyName(index, text)
                }
            }

            SpinBox {
                Layout.fillWidth: true
                Layout.minimumWidth: parent.width * 0.5

                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                editable: true

                value: stupidity

                validator: IntValidator {
                    bottom: 0
                    top: 100
                }

                onValueChanged: {
                    if (FliesModel != null)
                        FliesModel.setFlyStupidity(index, value)
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

