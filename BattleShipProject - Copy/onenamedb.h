#ifndef ONENAMEDB_H
#define ONENAMEDB_H

#include <QDialog>
#include <QString>

namespace Ui {
class OneNameDB;
}

class OneNameDB : public QDialog
{
    Q_OBJECT

public:
    explicit OneNameDB(QWidget *parent = 0);
    ~OneNameDB();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textEdited(const QString &arg1);
    QString getName();
private:
    Ui::OneNameDB *ui;
    QString name;
};

#endif // ONENAMEDB_H
