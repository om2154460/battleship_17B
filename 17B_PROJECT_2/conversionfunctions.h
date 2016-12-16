#ifndef CONVERSIONFUNCTIONS_H
#define CONVERSIONFUNCTIONS_H

#include <QString>
class ConversionFunctions
{
public:
    ConversionFunctions();
    QString convertIndex2Cell(int index);
    int convertCellr2Index(QString coordinate);
    int shipName2Index(QString name);
    QString index2ShipName(int index);
    int shipName2Size(QString name);
    QString intNum2StrNum(int num);
    int strNum2Num(QString num);
    QString num2StrLetter(int x);
    int strLetter2Num(QString letter);
    QString index2Row(int index);
};

#endif // CONVERSIONFUNCTIONS_H
