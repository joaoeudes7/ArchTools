#ifndef DIALOGTERMINAL_H
#define DIALOGTERMINAL_H

#include <QDialog>

namespace Ui {
class DialogTerminal;
}

class DialogTerminal : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTerminal(QWidget *parent = 0);
    ~DialogTerminal();

private:
    Ui::DialogTerminal *ui;
};

#endif // DIALOGTERMINAL_H
