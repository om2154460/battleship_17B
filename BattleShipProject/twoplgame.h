#ifndef TWOPLGAME_H
#define TWOPLGAME_H

#include <QDialog>

namespace Ui {
class TwoPlGame;
}

class TwoPlGame : public QDialog
{
    Q_OBJECT

public:
    explicit TwoPlGame(QWidget *parent = 0);
    ~TwoPlGame();

private:
    Ui::TwoPlGame *ui;
};

#endif // TWOPLGAME_H
