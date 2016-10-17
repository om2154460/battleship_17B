#include "onenamedb.h"
#include "ui_onenamedb.h"
#include "setships.h"
#include <QString>

OneNameDB::OneNameDB(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OneNameDB)
{
    ui->setupUi(this);
}

OneNameDB::~OneNameDB()
{
    delete ui;
}

void OneNameDB::on_pushButton_clicked()
{
   SetShips ss;
    ss.setModal(true);
    ss.exec();
    this->close();
}

void OneNameDB::on_lineEdit_textEdited(const QString &arg1) {
   // QString QTextEdit::toPlainText();
   name = (QString)arg1;
}

QString OneNameDB::getName() {
    return name;
}
