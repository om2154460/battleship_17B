#ifndef DIALOG_2_H
#define DIALOG_2_H

#include <QDialog>

namespace Ui {
class Dialog_2;
}

class Dialog_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_2(QWidget *parent = 0);
    ~Dialog_2();

private slots:
    void on_pushButton_clicked();
    void handleSpinBox(int);
    void handleComboBox(int);
    void handleComboBox_1(int);

private:
    Ui::Dialog_2 *ui;
    QString ethnicity, religion;
    int nSiblings;
};

#endif // DIALOG_2_H
