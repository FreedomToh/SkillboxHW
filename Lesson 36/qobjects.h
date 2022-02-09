#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include <QTimer>
#include <iostream>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QVBoxLayout>
#include <QSlider>


class ImageButton : public QPushButton {
    Q_OBJECT
public:
    ImageButton() = default;
    ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize minimumSizeHint() const override;

public slots:
    void setGreen();
    void setYellow();
    void setRed();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonGreenPixmap;
    QPixmap mButtonYellowPixmap;
    QPixmap mButtonRedPixmap;
};
#endif // OBJECT_H