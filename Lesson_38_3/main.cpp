#include <iostream>
#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QFileDialog>
#include <QPixmap>
#include <QImage>
#include <QGraphicsBlurEffect>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPainter>


QImage blurImage(QImage &source, int blurValue) {
    if (source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));

    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurValue);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);

    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(),
                 QRectF(0,0, scene.width(), scene.height()));
    return result;
}

void setPicture(QString &src, QLabel *target, int blurRadius) {
    QImage image(src);
    target->setPixmap(QPixmap::fromImage(blurImage(image, blurRadius)).scaled(
            target->width(),
            target->height(),
            Qt::KeepAspectRatio));
}


int main(int argc, char **argv) {
    QApplication app (argc, argv);

    auto *widget = new QWidget;
    auto *layout = new QVBoxLayout(widget);
    auto *imageLabel = new QLabel(widget);
    auto *slider = new QSlider(Qt::Horizontal);
    auto *button = new QPushButton("Open", widget);

    layout->addWidget(imageLabel);
    layout->addWidget(slider);
    layout->addWidget(button);

    slider->setMinimum(0);
    slider->setMaximum(10);

    QString filePath = nullptr;
    QObject::connect(button, &QPushButton::clicked, [&filePath, &imageLabel] {
        filePath = QFileDialog::getOpenFileName(nullptr, "Select image for blur", "./",
                                     "jpg files (*.jpg)");
        setPicture(filePath, imageLabel, 0);
    });

    QObject::connect(slider, &QSlider::valueChanged, [&filePath, &imageLabel, &slider]{
        setPicture(filePath, imageLabel, slider->value());
    });

    widget->setFixedSize(700, 700);
    widget->show();
    return app.exec();
}
