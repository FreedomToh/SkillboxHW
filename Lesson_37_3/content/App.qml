import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import Lesson_37_3 1.0

Window {
    width: Constants.width
    height: Constants.height
    minimumWidth: Constants.width
    minimumHeight: Constants.height
    maximumHeight: Constants.height
    maximumWidth: Constants.width

    visible: true
    title: "Lesson_37_3 TV control"

    Rectangle {
        width: Constants.width
        height: Constants.height

        color: Constants.backgroundColor

        GridView {
            id: gridView

            x: 20
            y: 50
            width: 220
            height: 250
            cellHeight: 80

            delegate: Item {
                x: 5
                height: 70
                Column {
                    RoundButton {
                        width: 60
                        height: 60
                        anchors.horizontalCenter: parent.horizontalCenter
                        onClicked: {
                            if (value >= 0 && value <= 9) {
                                channelText.text = name
                            } else if (name === ">") {
                                if (parseInt(channelText.text) < 9) {
                                    channelText.text = parseInt(channelText.text) + 1
                                } else {
                                    channelText.text = 0
                                }
                            } else if (name === "<") {
                                if (parseInt(channelText.text) > 0) {
                                    channelText.text = parseInt(channelText.text) - 1
                                } else {
                                    channelText.text = 9
                                }
                            }

                        }

                        Text {
                            x: 0
                            text: name
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                        }
                    }

                    spacing: 5
                }
            }
            cellWidth: 70
            model: ListModel {
                ListElement {
                    name: "1"
                    value: 1
                    colorCode: "grey"
                }

                ListElement {
                    name: "2"
                    value: 2
                    colorCode: "grey"
                }

                ListElement {
                    name: "3"
                    value: 3
                    colorCode: "grey"
                }

                ListElement {
                    name: "4"
                    value: 4
                    colorCode: "grey"
                }

                ListElement {
                    name: "5"
                    value: 5
                    colorCode: "grey"
                }

                ListElement {
                    name: "6"
                    value: 6
                    colorCode: "grey"
                }

                ListElement {
                    name: "7"
                    value: 7
                    colorCode: "grey"
                }

                ListElement {
                    name: "8"
                    value: 8
                    colorCode: "grey"
                }

                ListElement {
                    name: "9"
                    value: 9
                    colorCode: "grey"
                }

                ListElement {
                    name: "<"
                    value: -1
                    colorCode: "yellow"
                }

                ListElement {
                    name: "0"
                    value: 0
                    colorCode: "grey"
                }

                ListElement {
                    name: ">"
                    value: -1
                    colorCode: "red"
                }
            }
        }

        RoundButton {
            id: volumeUpB
            x: 20
            y: gridView.y + gridView.height + 75
            width: 60
            height: 60
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                if (parseInt(volumeText.text) < 100) {

                    volumeText.text = (parseInt(volumeText.text) + 10) + "%"
                }
            }

            Text {
                x: 0
                text: "+"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.bold: true
            }
        }

        RoundButton {
            id: volumeDownB
            x: 20
            y: volumeUpB.y + volumeUpB.height + 10
            width: 60
            height: 60
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                if (parseInt(volumeText.text) > 0) {

                    volumeText.text = (parseInt(volumeText.text) - 10) + "%"
                }
            }

            Text {
                x: 0
                text: "-"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.bold: true
            }
        }

        Rectangle {
            id: statusTextBlock
            color: "white"

            x: 20
            y: volumeDownB.y + volumeUpB.height + 10
            width: gridView.width - 20
            height: 50

            Text {
                id: channelTextLabel
                x: 5
                y: 5
                text: "channel:"
            }

            Text {
                id: channelText
                x: 100
                y: 5
                text: "1"
            }

            Text {
                id: volumeTextLabel
                x: 5
                y: 25
                text: "volume:"
            }

            Text {
                id: volumeText
                x: 100
                y: 25
                text: "100%"
            }
        }
    }


}
