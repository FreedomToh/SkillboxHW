#include "ImageButton.h"

ImageButton::ImageButton(QWidget *parent) {
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // Файлы нужно поместить в cmake-build-debug/imgs/
    mButtonUnpressedPixmap = QPixmap("./imgs/red.png");
    mButtonPressedPixmap = QPixmap("./imgs/pushed.png");
    mCurrentButtonPixmap = mButtonUnpressedPixmap;
    setGeometry(mCurrentButtonPixmap.rect());

    connect(this, &QPushButton::clicked, this, &ImageButton::setPressed);

    filePath = QString("./media/click.mp3");
    player.setMedia(QUrl::fromLocalFile(filePath));
    player.setVolume(75);
}

void ImageButton::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::minimumSizeHint() const {
    return QSize(100, 100);
}

void ImageButton::setPressed() {
    if (isPressed) return;
    isPressed = true;

    player.play();
    mCurrentButtonPixmap = mButtonPressedPixmap;
    update();

    QTimer::singleShot(100, this, &ImageButton::setUnpressed);
}

void ImageButton::setUnpressed() {
    isPressed = false;

    mCurrentButtonPixmap = mButtonUnpressedPixmap;
    update();
}

void ImageButton::playClick() {

}