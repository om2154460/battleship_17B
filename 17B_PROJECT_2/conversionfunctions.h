#ifndef CONVERSIONFUNCTIONS_H
#define CONVERSIONFUNCTIONS_H

#include <QString>
class ConversionFunctions
{
public:
    ConversionFunctions();
    QString convertIndex2Cell(int index);
    int convertCellr2Index(QString coordinate);
};

#endif // CONVERSIONFUNCTIONS_H
