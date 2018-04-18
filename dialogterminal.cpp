#include "dialogterminal.h"
#include "ui_dialogterminal.h"

DialogTerminal::DialogTerminal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTerminal)
{
    ui->setupUi(this);
}

DialogTerminal::~DialogTerminal()
{
    delete ui;
}
