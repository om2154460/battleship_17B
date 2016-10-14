#ifndef TWONAMESDB_H
#define TWONAMESDB_H

#include <QDialog>

namespace Ui {
class TwoNamesDB;
}

class TwoNamesDB : public QDialog
{
    Q_OBJECT

public:
    explicit TwoNamesDB(QWidget *parent = 0);
    ~TwoNamesDB();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TwoNamesDB *ui;
};

#endif // TWONAMESDB_H
