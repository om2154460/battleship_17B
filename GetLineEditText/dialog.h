#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void handleSpinBox(int);
    void handleSpinBox_2(int);
    void handleSpinBox_3(int);
    void handleLineEdit(QString);


private:
    Ui::Dialog *ui;
    int hours=0, units=1, year;
    float GPA=0.00;
};

#endif // DIALOG_H
