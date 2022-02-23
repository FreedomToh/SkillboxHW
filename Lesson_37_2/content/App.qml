/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Quick Studio Components.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick
import QtQuick.Window
import QtQuick.Controls
import Lesson_37_2_2

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

        anchors.top: parent

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

            x: rewindB.x + strewindBopB.width + 10
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

