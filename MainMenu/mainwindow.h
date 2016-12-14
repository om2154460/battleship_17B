#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include "instructions.h"

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
    void on_actionInstructions_triggered();

private:
    instructions *i;
    Ui::MainWindow *ui;
    QMediaObject * cannonfire;
};

#endif // MAINWINDOW_H
