#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->phoneLineEdit, &QLineEdit::textEdited, [this](QString text) {
        QRegularExpression expr("^\\+7\\d{10}$");

        if (expr.match(text).hasMatch()) {
            setOk();
        } else {
            setFail();
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOk() {
    ui->phoneCorrectStatus->setText("Correct number");
    ui->phoneCorrectStatus->setStyleSheet("QLabel {color: green;}");


    palette->setColor(QPalette::Base,Qt::green);
    ui->phoneLineEdit->setPalette(*palette);

}

void MainWindow::setFail() {
    ui->phoneCorrectStatus->setText("Incorrect number");
    ui->phoneCorrectStatus->setStyleSheet("QLabel {color: red;}");

    palette->setColor(QPalette::Base,Qt::red);
    ui->phoneLineEdit->setPalette(*palette);
}

