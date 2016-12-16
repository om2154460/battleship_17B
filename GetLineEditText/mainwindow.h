#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString getName() {return name;}
    QString getDate(){return dob;}
    ~MainWindow();

private slots:
    void handleLineEdit(QString);
    void handleLineEdit_1(QString);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString name, dob;
};

#endif // MAINWINDOW_H
