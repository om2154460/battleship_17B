#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QObject>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_close_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
