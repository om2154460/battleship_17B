#ifndef BATTLESHIPONEPLAYER_H
#define BATTLESHIPONEPLAYER_H

#include <QDialog>

namespace Ui {
class BattleShipOnePlayer;
}

class BattleShipOnePlayer : public QDialog
{
    Q_OBJECT

public:
    explicit BattleShipOnePlayer(QWidget *parent = 0);
    ~BattleShipOnePlayer();

private:
    Ui::BattleShipOnePlayer *ui;
};

#endif // BATTLESHIPONEPLAYER_H
