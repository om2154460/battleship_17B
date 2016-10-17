#ifndef ONEPLGAME_H
#define ONEPLGAME_H

#include <QDialog>

namespace Ui {
class OnePlGame;
}

class OnePlGame : public QDialog
{
    Q_OBJECT

public:
    explicit OnePlGame(QWidget *parent = 0);
    ~OnePlGame();

private:
    Ui::OnePlGame *ui;
};

#endif // ONEPLGAME_H
