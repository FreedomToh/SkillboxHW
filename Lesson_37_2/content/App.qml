import QtQuick
import QtQuick.Window
import QtQuick.Controls
import Lesson_37_2

Window {
    width: Constants.width
    height: Constants.height
    minimumWidth: Constants.minimumWidth
    minimumHeight: Constants.minimumHeight


    visible: true
    title: "Lesson_37_2"

    Image {
        id: image
        x: 0
        y: 0
        width: parent.width
        height: parent.height - row.height - 10
        source: "./bmp.bmp"
        fillMode: Image.PreserveAspectFit
    }


    Row {
        id: row
        width: parent.width
        height: 70

        x: 0
        y: image.height + 10


        Button {
            id: playB
            x: 10
            y: 0
            width: Constants.buttonWidth
            height: Constants.buttonHeight
            font.pointSize: 18
            text: "▶️"


        }

        Button {
            id: pauseB
            text: "⏸️"

            width: Constants.buttonWidth
            height: Constants.buttonHeight
            font.pointSize: 18

            x: playB.x + playB.width + 10
            y: playB.y

        }

        Button {
            id: stopB
            text: "⏹"

            width: Constants.buttonWidth
            height: Constants.buttonHeight
            font.pointSize: 18

            x: pauseB.x + pauseB.width + 10
            y: playB.y
        }

        Button {
            id: rewindB
            text: "⏪️"

            width: Constants.buttonWidth
            height: Constants.buttonHeight
            font.pointSize: 18

            x: stopB.x + stopB.width + 10
            y: playB.y
        }

        Button {
            id: forwardB
            text: "⏩️"

            width: Constants.buttonWidth
            height: Constants.buttonHeight
            font.pointSize: 18

            x: rewindB.x + rewindB.width + 10
            y: playB.y
        }

        ProgressBar {
            value: 0.2

            x: forwardB.x + 20
            y: forwardB.y

            height: Constants.buttonHeight
            width: parent.width - x
        }
    }
}

