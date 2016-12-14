#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <QFrame>

namespace Ui {
class instructions;
}

class instructions : public QFrame
{
    Q_OBJECT

public:
    explicit instructions(QWidget *parent = 0);
    ~instructions();

private slots:
    void on_toolButton_clicked();

private:
    Ui::instructions *ui;
};

#endif // INSTRUCTIONS_H
