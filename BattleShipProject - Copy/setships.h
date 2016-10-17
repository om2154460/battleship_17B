#ifndef SETSHIPS_H
#define SETSHIPS_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class SetShips;
}

class SetShips : public QDialog {
    Q_OBJECT

public:
    explicit SetShips(QWidget *parent = 0);
    ~SetShips();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SetShips *ui;
};

#endif // SETSHIPS_H
