#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <game.h>

#include <QMainWindow>
#include <QPushButton>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
friend class Game;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
int patrol[2],destroyer[3],submarine[3];
int battleship[4], aircraftCarrier[5];

public slots:
    void handleButton();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int numDrops;
    int firstCoordArr[5];
    //int coordTestArr[17];
    std::vector<int> coordTestVec;
    bool overlap;
    QPushButton *cells[100];
};

#endif // MAINWINDOW_H
