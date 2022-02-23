
#include <QApplication>
#include "CalcMainWindow.h"
#include <Lesson37_1_autogen/include/ui_design_37_1.h>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    CalcMainWindow window(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&window);

    window.lineEdit = caller.lineEdit;
    window.lineEdit_2 = caller.lineEdit_2;
    window.label_3 = caller.label_3;

    window.resize(250, 500);
    window.show();

    return QApplication::exec();
}
