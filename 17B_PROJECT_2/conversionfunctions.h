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
};

#endif // CONVERSIONFUNCTIONS_H
