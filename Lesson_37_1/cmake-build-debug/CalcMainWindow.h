//
// Created by freed on 11.02.2022.
//

#ifndef LESSON37_1_CALCMAINWINDOW_H
#define LESSON37_1_CALCMAINWINDOW_H

#include <iostream>
#include <string>
#include <QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>


enum types {
    INT = 0,
    DOUBLE = 1,
    ERROR = -1
};

class CalcMainWindow : public QMainWindow {
    Q_OBJECT

public:
    QLineEdit *lineEdit = nullptr;
    QLineEdit *lineEdit_2 = nullptr;
    QLabel* label_3 = nullptr;


    CalcMainWindow(QWidget* parent = nullptr): QMainWindow(parent) {}

public slots:
    void plus() {

        QString result = "";
        if (this->getTypes() == INT) {
            int valA = lineEdit->text().toInt();
            int valB = lineEdit_2->text().toInt();

            result = QString("%1").arg((valA + valB));
        } else if (this->getTypes() == DOUBLE) {
            double valA = lineEdit->text().toDouble();
            double valB = lineEdit_2->text().toDouble();

            result = QString("%1").arg((valA + valB), 0, 'E', 3);
        } else {
            result = "ERROR!!";
        }

        label_3->setText(result);
    };

    void minus() {

        QString result = "";
        if (this->getTypes() == INT) {
            int valA = lineEdit->text().toInt();
            int valB = lineEdit_2->text().toInt();

            result = QString("%1").arg((valA - valB));
        } else if (this->getTypes() == DOUBLE) {
            double valA = lineEdit->text().toDouble();
            double valB = lineEdit_2->text().toDouble();

            result = QString("%1").arg((valA - valB), 0, 'E', 3);
        } else {
            result = "ERROR!!";
        }

        label_3->setText(result);

    };

    void multipl() {
        QString result = "";
        if (this->getTypes() == INT) {
            int valA = lineEdit->text().toInt();
            int valB = lineEdit_2->text().toInt();

            result = QString("%1").arg((valA * valB));
        } else if (this->getTypes() == DOUBLE) {
            double valA = lineEdit->text().toDouble();
            double valB = lineEdit_2->text().toDouble();

            result = QString("%1").arg((valA * valB), 0, 'E', 3);
        } else {
            result = "ERROR!!";
        }

        label_3->setText(result);

    };

    void division() {
        QString result = "";
        if (this->getTypes() == INT) {
            int valA = lineEdit->text().toInt();
            int valB = lineEdit_2->text().toInt();

            if (valB != 0) {
                result = QString("%1").arg((valA / valB));
            } else {
                result = "ERROR!!";
            }
        } else if (this->getTypes() == DOUBLE) {
            double valA = lineEdit->text().toDouble();
            double valB = lineEdit_2->text().toDouble();

            if (valB != 0) {
                result = QString("%1").arg((valA / valB), 0, 'E', 3);
            } else {
                result = "ERROR!!";
            }
        } else {
            result = "ERROR!!";
        }

        label_3->setText(result);

    };

private:
    int getTypes() {
        bool errA = false;
        bool errB = false;

        if (lineEdit->text().contains(".") || lineEdit_2->text().contains(".")) {
            lineEdit->text().toDouble(&errA);
            lineEdit_2->text().toDouble(&errB);

            if (errA && errB) {
                return DOUBLE;
            } else {
                return ERROR;
            }
        } else {
            lineEdit->text().toInt(&errA);
            lineEdit_2->text().toInt(&errB);

            if (errA && errB) {
                return INT;
            } else {
                return ERROR;
            }
        }
    }

};



#endif //LESSON37_1_CALCMAINWINDOW_H
