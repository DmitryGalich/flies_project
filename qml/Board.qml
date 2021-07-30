import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13

Rectangle {
    GridView {
        id: board
        anchors.fill: parent
        boundsBehavior: Flickable.StopAtBounds
        model: BoardModel

        cellWidth: (BoardModel != null) ? (board.width / BoardModel.gridSide) : 0
        cellHeight: (BoardModel != null) ? (board.height / BoardModel.gridSide) : 0

        delegate: Rectangle {
            id: cell
            width: board.width / BoardModel.gridSide
            height: board.height / BoardModel.gridSide
            border.color: Material.color(Material.Grey)

            color: Material.backgroundColor

            Label {
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            var x_cell = Math.floor(mouseX / board.cellWidth)
            var y_cell = Math.floor(mouseY / board.cellHeight)

            console.log("X: " + x_cell + " Y: " + y_cell)
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

