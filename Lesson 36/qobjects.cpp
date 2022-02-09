#include "qobjects.h"

ImageButton::ImageButton(QWidget *parent) {
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // Файлы нужно поместить в cmake-build-debug/imgs/
    mButtonGreenPixmap = QPixmap("./imgs/green.png");
    mButtonYellowPixmap = QPixmap("./imgs/yellow.png");
    mButtonRedPixmap = QPixmap("./imgs/red.png");
    mCurrentButtonPixmap = mButtonGreenPixmap;
    setGeometry(mCurrentButtonPixmap.rect());

    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
}

void ImageButton::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}


QSize ImageButton::minimumSizeHint() const {
    return QSize(100, 100);
}

void ImageButton::setGreen() {
    mCurrentButtonPixmap = mButtonGreenPixmap;
    update();
}

void ImageButton::setYellow() {
    mCurrentButtonPixmap = mButtonYellowPixmap;
    update();
}

void ImageButton::setRed() {
    mCurrentButtonPixmap = mButtonRedPixmap;
    update();
}
