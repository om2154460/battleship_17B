#include "AI_Ship_Placer.h"
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <iostream>
#include <time.h>
#include <algorithm>    // std::random_shuffle
#include <Windows.h>

using namespace std;

//Constructor
AI_Ship_Placer::AI_Ship_Placer()
{
    debugging = false;
}
//Destructor
AI_Ship_Placer::~AI_Ship_Placer()
{
}
//Set Ships, returning a vector of Ship instances
vector<Ship> AI_Ship_Placer::setShips(){
    vector<Ship> ships;
    vector<string> coordinates;
    vector<char> directions;
    vector<string> tempCoordinates;
    vector<string> allCoordiantes;
    string temp;
    bool ok = false;
    std::vector<string>::iterator it;

    //Create 5 instances in the ships vector
    ships.resize(5);
    //Loop until all ships are placed on valid coordinates and not on top of each other.
    while (!ok){
        //Randomly choose 5 coordinates
        coordinates = getRandomCoordinates();
        //Randomly choose 5 directions (DOWN or RIGHT), one for each coordinate
        directions = getRandomDirections();
        //Place the ships given the provided starting coordinates and directions
        ships = placeAllShips(coordinates, directions);
        //Check if ship placements we okay.
        for (int i = 0; i < 5; i++){
            if (ships[i].getBadPlacement()){
                ok = false;
                break;
            }
            else
                ok = true;	//Ships are on valid coordinates and not on top of each other. Break out of this while loop. Lets do this!
        }
    }

    //Return the finished ships
    return ships;
}
//Set Ships (one by one), returning a vector of Ship instances
vector<Ship> AI_Ship_Placer::setShips2(){
    string coordinate;
    char direction;
    vector<string> coordinates;
    vector<Ship> ships;
    Ship tempShip;

    ships.resize(5);


        int i = 0;
        while (i != 5){
            //Randomly choose a coordinate
            coordinate = getRandomCoordinate();
            //Randomly choose a direction
            direction = getRandomDirection();


            //Fill a temporay ship instance
            tempShip = fillShip(index2ShipName(i), coordinate, direction);
            //Check that the ship was placed okay
            if (tempShip.getBadPlacement()){
                cout << "Placement of the " << index2ShipName(i) << " was off the grid. Try again!" << endl;
                continue;	//Ship placement was bad, go back to the asking the player for new coordinates.
            }
            //Get the coordinates of the temporary ship to be checked for collision with other ships that have been placed.
            vector<string> tempCoordinates = tempShip.getCoordinates();
            //Varibales to be used for the comparison code. May be put into a function.
            bool rePlaceShip = false;
            std::vector<string>::iterator it;
            //Check the ship to be placed will be on top of another other.
            if (coordinates.size() > 0){
                for (int w = 0; w < signed(tempCoordinates.size()); w++){
                    it = find(coordinates.begin() + w, coordinates.end(), tempCoordinates.at(w));
                    if (it != coordinates.end()){	//A coordinate of the temporary Ship has matched a coordinate from another ship.
                        rePlaceShip = true;	//Set Re-Place flag to true
                        break;
                    }
                }
                if (rePlaceShip){
                    cout << "Placement of the " << index2ShipName(i) << " was on top of another ship. Try again!" << endl;
                    continue;	//The temporary ship was placed on top of another ship, go back to the asking the player for new coordinates.
                }
            }

            //Add coordinates of the temporary ship the the coordinate vector for comparing.
            for (int j = 0; j < signed(tempCoordinates.size()); j++){
                coordinates.push_back(tempCoordinates[j]);
            }
            //Fill the player's ship with the temporary ship cooprdinates.
            ships[i].createShip(tempCoordinates);
            //Display where the Ship was placed
            cout << index2ShipName(i) << " placed on coordinates: ";
            for (int f = 0; f < signed(tempCoordinates.size()); f++){
                cout << tempCoordinates[f] << " ";
            }
            cout << endl;

            //Increase the iterator to go to next ship placement.
            i++;
        }

        return ships;
}
//Set Ships, creates a list of possible coordinates and pops off from those, returning a vector of Ship instances
vector<Ship> AI_Ship_Placer::setShips3(){
    string coordinate;
    char direction;
    vector<char> directions;
    vector<string> coordinates;
    vector<Ship> ships;
    Ship tempShip;

    ships.resize(5);

    //Randomly choose 5 directions (DOWN or RIGHT), one for each coordinate
    directions = getRandomDirections();
    vector<string> possCoordinates = randomCoordinates();
    int i = 0;
    while (i != 5){
        //Randomly choose a coordinate
        coordinate = possCoordinates.at(possCoordinates.size() - 1);;
        possCoordinates.pop_back();
        //Randomly choose a direction
        direction = directions[i];


        //Fill a temporay ship instance
        tempShip = fillShip(index2ShipName(i), coordinate, direction);
        //Check that the ship was placed okay
        if (tempShip.getBadPlacement()){
            cout << "Placement of the " << index2ShipName(i) << " was off the grid. Try again!" << endl;
            continue;	//Ship placement was bad, go back to the asking the player for new coordinates.
        }
        //Get the coordinates of the temporary ship to be checked for collision with other ships that have been placed.
        vector<string> tempCoordinates = tempShip.getCoordinates();
        //Varibales to be used for the comparison code. May be put into a function.
        bool rePlaceShip = false;
        std::vector<string>::iterator it;
        //Check the ship to be placed will be on top of another other.
        if (coordinates.size() > 0){
            for (int w = 0; w < signed(tempCoordinates.size()); w++){
                it = find(coordinates.begin() + w, coordinates.end(), tempCoordinates.at(w));
                if (it != coordinates.end()){	//A coordinate of the temporary Ship has matched a coordinate from another ship.
                    rePlaceShip = true;	//Set Re-Place flag to true
                    break;
                }
            }
            if (rePlaceShip){
                cout << "Placement of the " << index2ShipName(i) << " was on top of another ship. Try again!" << endl;
                continue;	//The temporary ship was placed on top of another ship, go back to the asking the player for new coordinates.
            }
        }

        //Add coordinates of the temporary ship the the coordinate vector for comparing.
        for (int j = 0; j < signed(tempCoordinates.size()); j++){
            coordinates.push_back(tempCoordinates[j]);
        }
        //Fill the player's ship with the temporary ship cooprdinates.
        ships[i].createShip(tempCoordinates);

        if (debugging){
            //Display where the Ship was placed
            cout << index2ShipName(i) << " placed on coordinates: ";
            for (int f = 0; f < signed(tempCoordinates.size()); f++){
                cout << tempCoordinates[f] << " ";
            }
            cout << endl;
        }


        //Increase the iterator to go to next ship placement.
        i++;
    }

    return ships;
}
//Randomly choose 5 coordinates A1 - J10. J10 not included because nothing can go to the Right or Down from there.
vector<string> AI_Ship_Placer::getRandomCoordinates(){
    vector<string> coordinates;
    string position;
    for (int i = 0; i < 5; i++){
        //Initialize the random seed
        std::srand(unsigned(std::time(NULL)));
        //Generate a random number between 1 and 100
        int randomNum = rand() % 100 + 1;
        //Convert random Number into a coordinate
        position = num2Coordinate(randomNum);
        //Add new coordinate to coordinate vector
        coordinates.push_back(position);
    }
    return coordinates;
}
//Randomly choose a coordinate A1 - J10.
string AI_Ship_Placer::getRandomCoordinate(){
    string coordinate;
    //Initialize the random seed
    std::srand(unsigned(std::time(NULL)));
    //Generate a random number between 1 and 100
    int randomNum = rand() % 100 + 1;
    //Convert random Number into a coordinate
    coordinate = num2Coordinate(randomNum);

        return coordinate;
}
//Convert a number 1 - 100 into a coordinate A1 - J10
string AI_Ship_Placer::num2Coordinate(int number){
    //Get Letter of coordinate
    int temp = number / 10;
    string letter;
    switch (temp){	//Every 10 is one more letter
        case 0:{
            letter = "A";
            break;
        }
        case 1:{
            letter = "B";
            break;
        }
        case 2:{
            letter = "C";
            break;
        }
        case 3:{
            letter = "D";
            break;
        }
        case 4:{
            letter = "E";
            break;
        }
        case 5:{
            letter = "F";
            break;
        }
        case 6:{
            letter = "G";
            break;
        }
        case 7:{
            letter = "H";
            break;
        }
        case 8:{
            letter = "I";
            break;
        }
        case 9:{
            letter = "J";
            break;
        }
    }

    //Get number of coordinate
    int temp2 = number % 10;	//Get remainder
    string num;
    switch (temp2){
        case 0:{
            num = "10";
            break;
        }
        case 1:{
            num = "1";
            break;
        }
        case 2:{
            num = "2";
            break;
        }
        case 3:{
            num = "3";
            break;
        }
        case 4:{
            num = "4";
            break;
        }
        case 5:{
            num = "5";
            break;
        }
        case 6:{
            num = "6";
            break;
        }
        case 7:{
            num = "7";
            break;
        }
        case 8:{
            num = "8";
            break;
        }
        case 9:{
            num = "9";
            break;
        }
    }

    //Combine Letter and Number into a usable Coordinate
    return (letter + num);

}
//Randomly choose 5 directions (DOWN or RIGHT), one for each coordinate
vector<char> AI_Ship_Placer::getRandomDirections(){
    vector<char> directions;

    SYSTEMTIME st;
    GetSystemTime(&st);
    std::srand(unsigned(st.wMilliseconds));
    // then convert st to your precision needs
    for (int i = 0; i < 5; i++){
        //Initialize the random seed
        //std::srand(unsigned(std::time(NULL)));
        //Generate a random number between 0 and 1
        int randomNum = rand() % 100 + 1;
        int remainder = randomNum % 2;
        //Convert random Number into a direction
        if (remainder == 0){
            directions.push_back('R');
        }
        else{
            directions.push_back('D');
        }
    }
    return directions;
}
//Randomly choose 5 directions (DOWN or RIGHT), one for each coordinate
char AI_Ship_Placer::getRandomDirection(){
    char direction;
    //Initialize the random seed
    std::srand(unsigned(std::time(NULL)));
    //Generate a random number between 100 and 1
    int randomNum = rand() % 100 + 1;
    int remainder = randomNum % 2;
    //Convert random Number into a direction
    if (remainder == 0){
        direction = 'D';
    }
    else{
        direction = 'R';
    }
    return direction;
}
//Returns the next coordinate based on a given coordinate and a direction.
string AI_Ship_Placer::nextPosition(char direction, string lastHit){
    string nextPos;
    int temp = 0;   //Only needed for debugging. After code works can combine two lines into one in the switch statement.
    //Break last hit apart into a row and column strings
    string row = lastHit.substr(0, 1); //Letter
    string column = lastHit.substr(1, lastHit.size());  //Number

    switch (direction){
    case 'U':{
        //Move up one, manipulating the letter... Ex: C5 => B5
        if (strLetter2Num(row) == 0) //Row A (Top of grid))
            return "Out";
        else{
            temp = strLetter2Num(row) - 1;
            row = num2StrLetter(temp);
        }
        break;
    }
    case 'D':{
        //Move down one, manipulating the letter... Ex: C5 => D5
        if (strLetter2Num(row) == 9) //Row J (Bottom of grid))
            return "Out";
        else{
            temp = strLetter2Num(row) + 1;
            row = num2StrLetter(temp);
        }
        break;
    }
    case 'L':{
        //Move left one, manipulating the number... Ex: C5 => C4
        if (strNum2Num(column) == 1) //Column 1 (Left of grid)
            return "Out";
        else{
            temp = strNum2Num(column) - 1;
            column = intNum2StrNum(temp);
        }
        break;
    }
    case 'R':{
        //Move right one, manipulating the number... Ex: C5 => C6
        if (strNum2Num(column) == 10) //Column 10 (Right of grid)
            return "Out";
        else{
            temp = strNum2Num(column) + 1;
            column = intNum2StrNum(temp);
        }
        break;
    }
    }

    //nextPos = row + column;   //Does not work. Adds the decimal Unicode instead of the combining the characters
    nextPos += row;
    nextPos += column;

    return nextPos;
}
//Convert a string letter to an integer number (A-J => 0-9)
int AI_Ship_Placer::strLetter2Num(string letter){
    char cLetter = letter[0];
    switch (cLetter){
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

    return 99;  //Needed so the compiler doesn't throw a fit...
}
//Convert an integer number to a string letter (0-9 => A-J)
string AI_Ship_Placer::num2StrLetter(int x){
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

    return "Wrong index passed";    //Needed so the compiler doesn't throw a fit...
}
//Convert a string number to an integer number (0-10)
int AI_Ship_Placer::strNum2Num(string num){
    char cNum;
    if (num == "10")
        return 10;
    else
        cNum = num[0];
    switch (cNum){
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

    return 99;  //Needed so the compiler doesn't throw a fit...
}
//Convert integer number to string number (0-10)
string AI_Ship_Placer::intNum2StrNum(int num){
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

    return "Wrong index passed!";   //Needed so the compiler doesn't throw a fit...
}
//Fill Ship based on name, starting coordiante, and direction. Return a filled ship
Ship AI_Ship_Placer::fillShip(string shipName, string coordinate, char direction){
    Ship ship;
    vector<string> tempCoordinates;
    string temp;
    int shipSize = shipName2Size(shipName) - 1;

    //Based on the name of the ship, deduce the size of the ship and the index of the ship
    tempCoordinates.push_back(coordinate);
    for (int i = 0; i < shipSize; i++){
        temp = nextPosition(direction, tempCoordinates.at(tempCoordinates.size() - 1));
        if (temp == "Out"){
            ship.setBadPlacement(true);	//Next coordinate was off the grid.
            return ship;	//Return a ship with badPlacement boolean set to true.
        }
        else{
            tempCoordinates.push_back(temp);
        }
    }
    //Assign coordinates to the ship
    ship.createShip(shipSize, tempCoordinates);

    return ship;
}
//Convert a ship name into a indexed number
int AI_Ship_Placer::shipName2Index(string name){
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

    return 99;  //Needed so the compiler doesn't throw a fit...
}
//Convert a indexed number into a ship name
string AI_Ship_Placer::index2ShipName(int index){
    switch(index){
        case 0:	return "CARRIER";
        case 1:	return "BATTLESHIP";
        case 2:	return "CRUISER";
        case 3:	return "SUBMARINE";
        case 4:	return "DESTROYER";
    }

    return "Wrong index passed!";   //Needed so the compiler doesn't throw a fit...
}
//Convert a ship name into a size
int AI_Ship_Placer::shipName2Size(string name){
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

    return 99;  //Needed so the compiler doesn't throw a fit...
}
//Place the ships given the provided starting coordinates and directions
vector<Ship> AI_Ship_Placer::placeShips2(vector<string> coordinates, vector<char> directions){
    vector<Ship> ships;
    vector<string> allCoordiantes;
    vector<string> tempCoordinates;
    bool startOver = false;
    bool ok = false;
    std::vector<string>::iterator it;

    //Loop until all ships are placed on valid coordinates and not on top of each other.
    while (!ok){
        //Fill ships with their coordinates
        for (int i = 0; i < 5; i++){
            ships[i] = fillShip(index2ShipName(i), coordinates[i], directions[i]);
            if (ships[i].getBadPlacement()){
                startOver = true;
                break;	//Break out of the for loop
            }
            //Add the ship coordinates to the all coordinate vector
            tempCoordinates = ships[i].getCoordinates();
            for (int x = 0; x < ships[i].getSize(); x++){
                allCoordiantes.push_back(tempCoordinates[x]);
            }
        }
        //If coordinates go off the map loop back and start over
        if (startOver){
            //Clear allCoordinates vector
            allCoordiantes.erase(allCoordiantes.begin(), allCoordiantes.end());
            startOver = false;
            continue;	//Go back to the beginnning of the while loop
        }
        //Check if ships are on top of each other
        for (int i = 0; i < signed(allCoordiantes.size()); i++){
            it = find(allCoordiantes.begin() + i + 1, allCoordiantes.end(), allCoordiantes.at(i));
            if (it != allCoordiantes.end()){
                startOver = true;
                break;	//Break out of the for loop
            }
        }
        //If one or more coordiantes match each other, start loop over
        if (startOver){
            //Clear allCoordinates vector
            allCoordiantes.erase(allCoordiantes.begin(), allCoordiantes.end());
            startOver = false;
            continue;	//Go back to the beginnning of the while loop
        }

        //Ships are on valid coordinates and not on top of each other. Break out of this while loop. Lets do this!
        ok = true;
    }

    return ships;
}
//Place the ships given the provided starting coordinates and directions
vector<Ship> AI_Ship_Placer::placeAllShips(vector<string> coordinates, vector<char> directions){
    vector<Ship> ships;
    vector<string> allCoordiantes;
    vector<string> tempCoordinates;
    std::vector<string>::iterator it;

    //Fill ships with their coordinates
    for (int i = 0; i < 5; i++){
        ships[i] = fillShip(index2ShipName(i), coordinates[i], directions[i]);
        if (ships[i].getBadPlacement()){	//If coordinates go off
            return ships;
        }
        //Add the ship coordinates to the all coordinate vector
        tempCoordinates = ships[i].getCoordinates();
        for (int x = 0; x < ships[i].getSize(); x++){
            allCoordiantes.push_back(tempCoordinates[x]);
        }
    }
    //Check if ships are on top of each other
    for (int i = 0; i < signed(allCoordiantes.size()); i++){
        it = find(allCoordiantes.begin() + i + 1, allCoordiantes.end(), allCoordiantes.at(i));
        if (it != allCoordiantes.end()){	//If one or more coordiantes match each other
            ships[i].setBadPlacement(true);	//Only need to set one ship placement as bad since entire loop will start again.
            return ships;
        }
    }

    return ships;
}

vector<string> AI_Ship_Placer::randomCoordinates(){
    //Create a move list, not randomized yet.
    vector<string> coordinates;
    coordinates.resize(100);
    for (int i = 0; i < 10; i++){
        for (int x = 0; x < 10; x++){
            //Add move to vector (Row letter + Column number)
            coordinates[(i * 10) + x] = num2Letter(i) + intNum2StrNum(x + 1);    //Must convert integer to a string
        }
    }

    //Create temporary move vector and copy vectors
    vector<string> tempCoordinates(coordinates);
    //Array of numbers the size of the total deck to be randomized.
    int randArray[100];	//Visual Studio does not like [possMoves.size()]
    //int randArray[possMoves.size()];
    //Fill randArray from 0 to totalPossiblemoves - 1
    for (int i = 0; i < signed(coordinates.size()); i++){
        randArray[i] = i;
    }
    //Randomize the randArray
    SYSTEMTIME st;
    GetSystemTime(&st);
    std::srand(unsigned(st.wMilliseconds));
    //std::srand(unsigned(std::time(NULL)));   //So that cards are actually random for every game.
    std::random_shuffle(&randArray[0], &randArray[coordinates.size() - 1]);
    //Randomize Possible Moves Vector using the randomized array
    for (int i = 0; i < signed(coordinates.size()); i++){
        coordinates[i] = tempCoordinates[randArray[i]];
    }

    //Switch last coordinate in Possible Move List with another coordinate based on randomNum that was generated.
    //This is needed because the random_shuffle function does not change the last instance of array
    //Initialize the random seed
    //std::srand(unsigned(std::time(NULL)));
    //Generate a random number between 0 and 99
    int randomNum = rand() % 99 + 0;
    //Do the swap!
    string temp = coordinates[coordinates.size() - 1];
    coordinates.at(coordinates.size() - 1) = coordinates.at(randomNum);
    coordinates.at(randomNum) = temp;

    return coordinates;
}
//Convert integer number to char letter (0-9 => A-J)
char AI_Ship_Placer::num2Letter(int x){
    //0-9 == A-J
    switch (x){
    case 0: return 'A';
    case 1: return 'B';
    case 2: return 'C';
    case 3: return 'D';
    case 4: return 'E';
    case 5: return 'F';
    case 6: return 'G';
    case 7: return 'H';
    case 8: return 'I';
    case 9: return 'J';
    }

    return 'W'; //Needed so the compiler doesn't throw a fit...b
}



