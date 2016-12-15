#ifndef LOGMENU_H
#define LOGMENU_H

#include <QDialog>
#include <QtDebug>
#include <QFileInfo>
#include <QString>

namespace Ui {
class logmenu;
}

class logmenu : public QDialog
{
    Q_OBJECT

public:
    explicit logmenu(QWidget *parent = 0);
    ~logmenu();

    QString getUser(){return userName;}
    QString getPass(){return password;}
    void setUser(QString user);
    void setPass(QString pass);

    QString userName;
    QString password;

private slots:

    void on_quit_clicked();

    void on_enter_clicked();

private:
    Ui::logmenu *ui;

};

#endif // LOGMENU_H

