#ifndef CELL_H
#define CELL_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class Cell;
}

class Cell : public QDialog
{
    Q_OBJECT

public:
    explicit Cell(QWidget *parent = 0);
    void handleButton(int);
    ~Cell();

private:
    Ui::Cell *ui;
     // QPushButton *cells[100];

};





class Square: public QPushButton {
    Q_OBJECT
private:
   // QPushButton button;

public:
    Square() {}
 QPushButton *button;
    ~Square(){}







};













#endif // CELL_H
