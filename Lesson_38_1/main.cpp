#include <iostream>
#include <QApplication>
#include "ImageButton.h"


int main(int argc, char**argv) {
    QApplication app(argc, argv);

    auto *widget = new QWidget;
    widget->setFixedSize (180, 180);

    auto* colorButton = new ImageButton(widget);
    colorButton->setFixedSize(180, 180);

    widget->show();
    return app.exec();
}
