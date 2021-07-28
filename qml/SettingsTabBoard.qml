import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13

ColumnLayout {
    RowLayout {
        Layout.fillWidth: true
        Layout.fillHeight: true
        
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        
        Label {
            Layout.fillWidth: true
            
            text: qsTr("Cells in row:")
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
            
            font.italic: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
        
        SpinBox {
            Layout.fillWidth: true
            Layout.maximumWidth: parent.width * 0.5
            
            editable: true
            validator: IntValidator {
                bottom: 1
                top: 100
            }
        }
    }
}
