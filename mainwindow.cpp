#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dialogterminal.h"

#include <QStringList>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnUpdateRepositories_clicked()
{
    myProcess->start("pkexec pacman -Syy");
    connectMyProcess();
}

void MainWindow::connectMyProcess() {
    myProcess->waitForStarted();
    connect( myProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(readyReadStandardOutput()) );
    connect( myProcess, SIGNAL(readyReadStandardError()), this, SLOT(readyReadStandardError()) );
}

void MainWindow::readyReadStandardOutput() {
    ui->lblStatus->setText(myProcess->readLine());
}

void MainWindow::readyReadStandardError(){
    qDebug() << myProcess->readAllStandardError();
}

void MainWindow::blockButtons() {
    ui->btnClearRepository->setDisabled(true);
    ui->btnFastestMirrors->setDisabled(true);
    ui->btnUpdateKeys->setDisabled(true);
    ui->btnUpdateRepositories->setDisabled(true);
}

void MainWindow::on_btnKill_clicked()
{
    myProcess->kill();
}

void MainWindow::on_btnFastestMirrors_clicked()
{
    myProcess->start("pkexec bash -c \" pacman-mirrors --fasttrack && pacman -Syyu \"");
    connectMyProcess();
}

void MainWindow::on_btnClearRepository_clicked()
{
    myProcess->start("pkexec bash -c \" pacman -Sc && pacman-optimize \"");
    connectMyProcess();
}
