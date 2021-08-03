import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.13

Rectangle {
    function setCellCapacity(cellIndex, capacity) {
        if (BoardModel === null)
            return

        BoardModel.setCellCapacity(cellIndex, capacity)
    }

    GridView {
        id: board
        anchors.fill: parent
        boundsBehavior: Flickable.StopAtBounds
        model: BoardModel

        cellWidth: (BoardModel != null) ? (board.width / BoardModel.gridSide) : 0
        cellHeight: (BoardModel != null) ? (board.height / BoardModel.gridSide) : 0

        delegate: Rectangle {
            id: cell

            function updateData() {
                cellX = cell.x
                cellY = cell.y
                cellWidth = cell.width
                cellHeight = cell.height
            }

            width: board.width / BoardModel.gridSide
            height: board.height / BoardModel.gridSide

            border.color: Material.color(Material.Grey, Material.Shade700)
            color: Material.backgroundColor

            onWidthChanged: {
                updateData()
            }

            onHeightChanged: {
                updateData()
            }

            Label {
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                text: cellCapacity

                color: Material.color(Material.Grey, Material.Shade500)
            }
        }
    }

    GridView {
        id: flies
        anchors.fill: parent
        boundsBehavior: Flickable.StopAtBounds
        model: FliesModel

        delegate: Rectangle {
            id: fly

            Image {
                id: flyImage
                source: flyIcon
                sourceSize.height: board.cellHeight * 0.2
                sourceSize.width: board.cellWidth * 0.2
                x: flyX
                y: flyY
            }
        }
    }

    MouseArea {
        id: cellsArea

        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            BoardModel.openCellSettingsWindow(board.indexAt(mouseX, mouseY))
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

