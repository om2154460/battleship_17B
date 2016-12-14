#ifndef LOGMENU_H
#define LOGMENU_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class logmenu;
}

class logmenu : public QDialog
{
    Q_OBJECT

public:
    explicit logmenu(QWidget *parent = 0);
    ~logmenu();

private slots:
    void on_pushButton_2_clicked();

    void on_quit_clicked();

    void on_enter_clicked();

private:
    Ui::logmenu *ui;
};

#endif // LOGMENU_H
