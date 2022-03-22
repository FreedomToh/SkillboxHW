#ifndef LESSON_38_1_IMAGEBUTTON_H
#define LESSON_38_1_IMAGEBUTTON_H

#include <QObject>
#include <QTimer>
#include <iostream>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QVBoxLayout>
#include <QSlider>
#include <QMediaPlayer>


class ImageButton : public QPushButton {
    Q_OBJECT
public:
    ImageButton() = default;
    ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    [[nodiscard]] QSize minimumSizeHint() const override;


public slots:
    void setPressed();
    void setUnpressed();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonUnpressedPixmap;
    QPixmap mButtonPressedPixmap;

    QString filePath;
    bool isPressed = false;
    QMediaPlayer player;
};

#endif //LESSON_38_1_IMAGEBUTTON_H
