#ifndef ONENAMEDB_H
#define ONENAMEDB_H

#include <QDialog>

namespace Ui {
class OneNameDB;
}

class OneNameDB : public QDialog
{
    Q_OBJECT

public:
    explicit OneNameDB(QWidget *parent = 0);
    ~OneNameDB();

private slots:
    void on_pushButton_clicked();

private:
    Ui::OneNameDB *ui;
};

#endif // ONENAMEDB_H
