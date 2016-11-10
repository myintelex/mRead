#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("#centralWidget{background-image: url(:/image/image/bg.png);background-repeat:repeat-xy;}");
    this->setWindowFlags(Qt::WindowSystemMenuHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName();
    ui->lineEdit->setText(filePath);
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    }
    QTextStream in(&file);
    QString line = in.readAll();
    ui->textBrowser->append(line);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    ui->textBrowser->setFixedSize(this->width(), this->height() - 20);
    ui->textBrowser->move(0, 30);
}
