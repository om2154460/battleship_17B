#ifndef DIALOG_3_H
#define DIALOG_3_H

#include <QDialog>

namespace Ui {
class Dialog_3;
}

class Dialog_3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_3(QWidget *parent = 0);
    ~Dialog_3();

private slots:
    void on_pushButton_clicked();
    void handleCB1(bool);
    void handleCB2(bool);
    void handleCB3(bool);
    void handleCB4(bool);
    void handleSpinBox(int);
    void handleSpinBox_2(int);

private:
    Ui::Dialog_3 *ui;
    bool marijuana = false, pets = false, liveAtHome= false, music = false;
    int nUses, hrsSleep;
};

#endif // DIALOG_3_H
