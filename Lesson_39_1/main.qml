import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
            id: scene
            anchors.fill: parent
            state: "LeftState"

            Rectangle {
                id: leftRect
                x: 100
                y: 200
                color: "lightGrey"
                width: 100
                height: 100
                border.color: "black"
                border.width: 3
                radius: 5

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if (roundRect.x > parent.x + 5) {
                            roundText.text = "move to LeftState"
                            scene.state = "LeftState"
                        } else {
                            roundText.text = "return"

                            roundRect.x = rightRect.x - roundRect.width
                            scene.state = "OtherState"
                            scene.state = "LeftState"
                        }
                    }
                }
            }

            Rectangle {
                id: rightRect
                x: 300
                y: 200
                color: "lightGrey"
                width: 100
                height: 100
                border.color: "black"
                border.width: 3
                radius: 5

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if (roundRect.x < parent.x) {
                            roundText.text = "move to RightState"
                            scene.state = "RightState"
                        } else {
                            roundText.text = "return"

                            roundRect.x = leftRect.x + leftRect.width
                            scene.state = "OtherState"
                            scene.state = "RightState"
                        }
                    }
                }
            }

            Rectangle {
                id: roundRect
                x: leftRect.x + 5
                y: leftRect.y + 5
                color: "yellow"
                width: leftRect.width - 10
                height: leftRect.height - 10
                border.color: "black"
                border.width: 3
                radius: 50

                Text {
                    id: roundText
                    text: ""
                    anchors.centerIn: parent

                }
            }

            states: [
                State {
                    name: "LeftState"
                    PropertyChanges {
                        target:  roundRect
                        x: leftRect.x + 5
                    }
                },

                State {
                    name: "RightState"
                    PropertyChanges {
                        target:  roundRect
                        x: rightRect.x + 5
                    }
                },

                State {
                    name: "OtherState"
                    PropertyChanges {
                        target:  roundRect
                        x: roundRect.x
                    }
                }
            ]

            transitions: [
                Transition {
                    from: "LeftState"
                    to: "RightState"


                    NumberAnimation {
                        properties: "x,y"
                        duration: 1000
                        easing.type: Easing.InOutQuad
                    }
                },

                Transition {
                    from: "RightState"
                    to: "LeftState"


                    NumberAnimation {
                        properties: "x,y"
                        duration: 1000
                        easing.type: Easing.InOutQuad
                    }
                },


                Transition {
                    from: "OtherState"
                    to: "LeftState"


                    NumberAnimation {
                        properties: "x,y"
                        duration: 1000
                        easing.type: Easing.InOutQuad
                    }
                },

                Transition {
                    from: "OtherState"
                    to: "RightState"


                    NumberAnimation {
                        properties: "x,y"
                        duration: 1000
                        easing.type: Easing.InOutQuad
                    }
                }

            ]
        }
}
