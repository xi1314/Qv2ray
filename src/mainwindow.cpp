#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    proc = new QProcess(this);
}

MainWindow::~MainWindow()
{
    proc->kill();
    delete proc;
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    proc->setProgram(this->ui->lineEdit->text());
    proc->setArguments( QStringList() << " -config " << this->ui->lineEdit_2->text());
    proc->start();
    QMessageBox::information(this, "Qv2ray", "v2ray has been started");
}

void MainWindow::on_pushButton_2_clicked()
{
    proc->kill();
    QMessageBox::information(this, "Qv2ray", "v2ray stopped");
}
