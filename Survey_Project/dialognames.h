#ifndef DIALOGNAMES_H
#define DIALOGNAMES_H

#include <QDialog>

namespace Ui {
class DialogNames;
}

class DialogNames : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNames(QWidget *parent = 0);
    ~DialogNames();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogNames *ui;
};

#endif // DIALOGNAMES_H
