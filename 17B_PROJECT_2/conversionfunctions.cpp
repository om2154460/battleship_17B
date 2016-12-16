#include "conversionfunctions.h"

ConversionFunctions::ConversionFunctions()
{

}
//Convert an integer index to a corrosponding Coordiante EX: 1 -> A1
QString ConversionFunctions::convertIndex2Cell(int index){
    int row = index / 10;
    int col = index % 10;
    QString cell = "";

    switch(row){
        case 0:{
            cell += "A";
            break;
        }
        case 1:{
            cell += "B";
            break;
        }
        case 2:{
            cell += "C";
            break;
        }
        case 3:{
            cell += "D";
            break;
        }
        case 4:{
            cell += "E";
            break;
        }
        case 5:{
            cell += "F";
            break;
        }
        case 6:{
            cell += "G";
            break;
        }
        case 7:{
            cell += "H";
            break;
        }
        case 8:{
            cell += "I";
            break;
        }
        case 9:{
            cell += "J";
            break;
        }
    }

    switch(col){
        case 0:{
            cell += "1";
            break;
        }
        case 1:{
            cell += "2";
            break;
        }
        case 2:{
            cell += "3";
            break;
        }
        case 3:{
            cell += "4";
            break;
        }
        case 4:{
            cell += "5";
            break;
        }
        case 5:{
            cell += "6";
            break;
        }
        case 6:{
            cell += "7";
            break;
        }
        case 7:{
            cell += "8";
            break;
        }
        case 8:{
            cell += "9";
            break;
        }
        case 9:{
            cell += "10";
            break;
        }
    }

    return cell;

}

int ConversionFunctions::convertCellr2Index(QString coordinate){
    QString tempRow = coordinate.mid(0, 1);
    QChar row = tempRow[0];
    QString column = coordinate.mid(1, coordinate.size() - 1);

    int index = 0;

    switch(row.toLatin1()){
        case 'A':{
            index += 0;
            break;
        }
        case 'B':{
            index += 10;
            break;
        }
        case 'C':{
            index += 20;
            break;
        }
        case 'D':{
            index += 30;
            break;
        }
        case 'E':{
            index += 40;
            break;
        }
        case 'F':{
            index += 50;
            break;
        }
        case 'G':{
            index += 60;
            break;
        }
        case 'H':{
            index += 70;
            break;
        }
        case 'I':{
            index += 80;
            break;
        }
        case 'J':{
            index += 90;
            break;
        }
    }

    index += column.toInt() - 1;

    return index;
}
int ConversionFunctions::shipName2Index(QString name){
    if (name == "CARRIER")	//Size 5
        return 0;
    if (name == "BATTLESHIP")	//Size 4
        return 1;
    if (name == "CRUISER")	//Size 3
        return 2;
    if (name == "SUBMARINE")	//Size 3
        return 3;
    if (name == "DESTROYER")	//Size 2
        return 4;

    return 99;   //Only needed so compiler doesn't throw a fit...
}
//Convert a indexed number into a ship name
QString ConversionFunctions::index2ShipName(int index){
    switch (index){
    case 0:	return "CARRIER";
    case 1:	return "BATTLESHIP";
    case 2:	return "CRUISER";
    case 3:	return "SUBMARINE";
    case 4:	return "DESTROYER";
    }
    return "Wrong Index Given";   //Only needed so compiler doesn't throw a fit...
}
//Convert a ship name into a size
int ConversionFunctions::shipName2Size(QString name){
    if (name == "CARRIER")	//Size 5
        return 5;
    if (name == "BATTLESHIP")	//Size 4
        return 4;
    if (name == "CRUISER")	//Size 3
        return 3;
    if (name == "SUBMARINE")	//Size 3
        return 3;
    if (name == "DESTROYER")	//Size 2
        return 2;

    return 99;  //Only needed so compiler doesn't throw a fit...
}
//Convert an integer number to a QString letter (0-9 => A-J)
QString ConversionFunctions::num2StrLetter(int x){
    //0-9 == A-J
    switch (x){
    case 0: return "A";
    case 1: return "B";
    case 2: return "C";
    case 3: return "D";
    case 4: return "E";
    case 5: return "F";
    case 6: return "G";
    case 7: return "H";
    case 8: return "I";
    case 9: return "J";
    }

    return "Wrong index given"; //Only needed so compiler doesn't throw a fit...
}
//Convert a QString number to an integer number (0-10)
int ConversionFunctions::strNum2Num(QString num){
    QChar cNum;
    if (num == "10")
        return 10;
    else
        cNum = num.at(0);
    switch (cNum.toLatin1()){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    }

    return 99;  //Only needed so compiler doesn't throw a fit...
}
//Convert integer number to QString number (0-10)
QString ConversionFunctions::intNum2StrNum(int num){
    switch (num){
    case 0: return "0";
    case 1: return "1";
    case 2: return "2";
    case 3: return "3";
    case 4: return "4";
    case 5: return "5";
    case 6: return "6";
    case 7: return "7";
    case 8: return "8";
    case 9: return "9";
    case 10: return "10";
    }

    return "Wrong index given"; //Only needed so compiler doesn't throw a fit...
}
//Convert a QString letter to an integer number (A-J => 0-9)
int ConversionFunctions::strLetter2Num(QString letter){
    QChar cLetter = letter.at(0);
    switch (cLetter.toLatin1()){
        case 'A': return 0;
        case 'B': return 1;
        case 'C': return 2;
        case 'D': return 3;
        case 'E': return 4;
        case 'F': return 5;
        case 'G': return 6;
        case 'H': return 7;
        case 'I': return 8;
        case 'J': return 9;
    }

    return 99;  //Only needed so compiler doesn't throw a fit...
}
//Convert an intger index (0-9) to QString row (A-J)
QString ConversionFunctions::index2Row(int index){
    switch(index){
        case 0: return "A";
        case 1: return "B";
        case 2: return "C";
        case 3: return "D";
        case 4: return "E";
        case 5: return "F";
        case 6: return "G";
        case 7: return "H";
        case 8: return "I";
        case 9: return "J";
    }
    return "A";
}

