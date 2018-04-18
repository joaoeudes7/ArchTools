#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QProcess>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    const QString sudo = "pkexec";
    QProcess* myProcess = new QProcess(this);

private slots:
    void on_btnUpdateRepositories_clicked();
    void on_btnKill_clicked();
    void on_btnFastestMirrors_clicked();

    void readyReadStandardOutput();
    void readyReadStandardError();
    void connectMyProcess();

    void blockButtons();

    void on_btnClearRepository_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
