#include <QApplication>
#include "qobjects.h"
#include <string>




int main(int argc, char**argv) {
    QApplication app(argc, argv);

    auto *widget = new QWidget;
    widget->setFixedSize (200, 250);

    auto *layout = new QVBoxLayout(widget);

    auto *colorButton = new ImageButton(widget);
    colorButton->setFixedSize(180, 180);
    layout->addWidget(colorButton);

    auto *slider = new QSlider(Qt::Horizontal, widget);
    slider->setFixedSize(180, 25);
    slider->setMinimum(0);
    slider->setMaximum(100);
    QObject::connect(slider, &QSlider::valueChanged, colorButton, [&slider, &colorButton](int newVal){
        if (slider->value() < 33) {
            colorButton->setGreen();
        } else if (slider->value() >= 33 && slider->value() < 66) {
            colorButton->setYellow();
        } else if (slider->value() >= 66) {
            colorButton->setRed();
        }
    });
    layout->addWidget(slider);

    widget->show();

    return app.exec();
}
