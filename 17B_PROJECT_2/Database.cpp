//Author Brandon Robinson 2016
#include "Database.h"
#include <QDebug>   //qDebug() stream (comparable to cout and cin)
#include <QTime>
#include <QDateTime>
#include <QDate>
#include <QSqlRecord>   //Needed for record.count()  for column number.
#include <QSqlError>

//Constructor
Database::Database()
{
    debugging = true;
}
//Destructor
Database::~Database(){
    database.close();
}
//Create a connection to a specifcied Database, return true or false
bool Database::createConnection(QString hostName, QString databaseName, QString userName, QString password){
    //For debugging
    if(debugging){
        hostName = "127.0.0.1";
        databaseName = "test";
        userName = "root";
        password = "";
    }

    //Set Class Database connections
    this->hostName = hostName;
    this->databaseName = databaseName;
    this->userName = userName;
    this->password = password;

    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName(hostName);
    database.setDatabaseName(databaseName);
    database.setUserName(userName);
    database.setPassword(password);

    if (!database.open()) {
        qDebug() << "Database error occurred...";
        connected = false;
        return connected;
    }
    else{
        connected = true;
    }
    return connected;
}
//Close Database Connection
void Database::closeConnection(){
    database.close();
}
//Create Database BattleShip Schema
bool Database::createSchema(){
    QSqlQuery query;
    //Prepare SQL Script for Schema creating
    query.prepare("CREATE SCHEMA `battleship`");
    //Send the SQL command, returning whether it was successful or not.
    if(query.exec()){
        qDebug() << "BattleShip Schema created.";
        return true;
    } else{
        error = query.lastError().text();
        qDebug() << error;
        return false;
    }
}
//Create Database Tables
void Database::createTables(){
    QSqlQuery query;
    //Prepare SQL Script for games table creating
    query.prepare("CREATE TABLE `battleship`.`games` ("
                  "`ColumnID` INT NOT NULL AUTO_INCREMENT, "
                  "`GameName` VARCHAR(45) NOT NULL, "
                  "`DateCreated` DATE NOT NULL, "
                  "`Player1` VARCHAR(45) NOT NULL, "
                  "`Player2` VARCHAR(45) NOT NULL, "
                  "PRIMARY KEY (`ColumnID`, `GameName`))");
    //Send the SQL command, returning whether it was successful or not.
    if(!query.exec()){
        error = query.lastError().text();
        qDebug() << error;
    }
    //Prepare SQL Script for players table creating
    query.prepare("CREATE TABLE `battleship`.`players` ("
                  "`PlayerID` INT NOT NULL AUTO_INCREMENT, "
                  "`UserName` VARCHAR(45) NOT NULL, "
                  "`Password` VARCHAR(45) NOT NULL, "
                  "PRIMARY KEY (`PlayerID`, `UserName`))");
    //Send the SQL command, returning whether it was successful or not.
    if(!query.exec()){
        error = query.lastError().text();
        qDebug() << error;
    }
    //Prepare SQL Script for messages table creating
    query.prepare("CREATE TABLE `battleship`.`messages` ("
                  "`MessageID` INT NOT NULL AUTO_INCREMENT, "
                  "`Message` VARCHAR(45) NULL, "
                  "`UserName` VARCHAR(45) NOT NULL, "
                  "`DateTime` DATETIME NOT NULL, "
                  "`Game` VARCHAR(45) NOT NULL, "
                  "PRIMARY KEY (`MessageID`))");
    //Send the SQL command, returning whether it was successful or not.
    if(!query.exec()){
        error = query.lastError().text();
        qDebug() << error;
    }
    //Prepare SQL Script for moves table creating
    query.prepare("CREATE TABLE `battleship`.`moves` ("
                  "`MoveID` INT NOT NULL AUTO_INCREMENT, "
                  "`Move` VARCHAR(5) NOT NULL, "
                  "`UserName` VARCHAR(45) NOT NULL, "
                  "`GameName` VARCHAR(45) NOT NULL, "
                  "`TimeDate` DATETIME NOT NULL, "
                  "PRIMARY KEY (`MoveID`))");
    //Send the SQL command, returning whether it was successful or not.
    if(!query.exec()){
        error = query.lastError().text();
        qDebug() << error;
    }
    //Prepare SQL Script for ships table creating
    query.prepare("CREATE TABLE `battleship`.`ships` ( "
                  "`id` INT NOT NULL AUTO_INCREMENT, "
                  "`userName` VARCHAR(45) NOT NULL, "
                  "`shipName` VARCHAR(45) NOT NULL, "
                  "`shipSize` INT NOT NULL, "
                  "`gameName` VARCHAR(45) NOT NULL, "
                  "`coordinates` VARCHAR(45) NOT NULL, "
                  "PRIMARY KEY (`id`))";
    //Send the SQL command, returning whether it was successful or not.
    if(!query.exec()){
        error = query.lastError().text();
        qDebug() << error;
    }
}
//Add a game entry into the Game table of the database
bool Database::createGame(QString gameName, QString player1, QString player2){
    QSqlQuery query;

    //Get the current date
    QString dateCreated = QDate::currentDate().toString("yyyy-dd-MM");
    //Prepare SQL Script with place holders for the fields to be inserted
    query.prepare("INSERT INTO `battleship`.`games` (`GameName`, `DateCreated`, `Player1`, `Player2`) "
                  "VALUES (:gameName, :dateCreated, :player1, :player2)");
    //Replace the place holders with the actual values to be instered into the database
    query.bindValue(":gameName", gameName);
    query.bindValue(":dateCreated", dateCreated);
    query.bindValue(":player1", player1);
    query.bindValue(":player2", player2);
    //Send the SQL command, returning whether it was successful or not.
    if(query.exec())
        return true;
    else{
        error = query.lastError().text();
        qDebug() << error;
        return false;
    }
}
//Retrieve all game entries in the game table. Returns QSqlQuery
QSqlQuery Database::getAllGames(){
    QSqlQuery query;
    //query.prepare("SELECT * FROM 'battleship'.'games' LIMIT 0, 1000");
    query.prepare("SELECT * FROM battleship.games LIMIT 0, 1000");

    if(query.exec()){
        if(debugging){  //Print the returned table
            int columns = query.record().count();
            int rows = query.size();
            QString temp = "";
            for(int r = 0; r < rows; r++){
                if (query.next()){
                    for(int c = 0; c < columns; c++){
                        temp += query.value(c).toString() + ", ";
                    }
                }
                qDebug() << temp;   //Output the row
                temp = "";  //Clear the temporary QString holder
            }
        }
        return query;   //Return the table
    }
    else{
        error = query.lastError().text();
        qDebug() << error;
        return query;
    }
}
//Insert a message into the Message table of the database
bool Database::createMessage(QString gameName, QString userName, QString message){
    QDate date;
    QSqlQuery query;
    QDateTime dt;

    //Get the current date
    //QString dateCreated = date.currentDate().toString("yyyy-dd-MM");
    QString dateTime = dt.currentDateTime().toString("yyyy-dd-MM HH:mm:ss");
    //Prepare SQL Script with place holders for the fields to be inserted
    query.prepare("INSERT INTO `battleship`.`messages` (`Message`, `UserName`, `DateTime`, `Game`) "
                  "VALUES (:Message, :UserName, :DateTime, :GameName)");
    //Replace the place holders with the actual values to be instered into the database
    query.bindValue(":Message", message);
    query.bindValue(":UserName", userName);
    query.bindValue(":DateTime", dateTime);
    query.bindValue(":GameName", gameName);
    //Send the SQL command, returning whether it was successful or not.
    if(query.exec())
        return true;
    else{
        error = query.lastError().text();
        qDebug() << error;
        return false;
    }
}
//Retrieve all messages for a specified game
QSqlQuery Database::getGameMessages(QString gameName){
    QSqlQuery query;
    //Prepare the SQL Script
    query.prepare("SELECT * FROM battleship.messages WHERE Game = :Game");
    //Replace the placehold
    query.bindValue(":Game", gameName);
    //Execute the SQL Script
    if(query.exec()){
        if(debugging){  //Print the returned table
            int columns = query.record().count();
            int rows = query.size();
            QString temp = "";
            for(int r = 0; r < rows; r++){
                if (query.next()){
                    for(int c = 0; c < columns; c++){
                        temp += query.value(c).toString() + ", ";
                    }
                }
                qDebug() << temp;   //Output the row
                temp = "";  //Clear the temporary QString holder
            }
        }
        return query;   //Return the table
    }
    else{
        error = query.lastError().text();
        qDebug() << error;
        return query;
    }
}
//Insert a move into the database
bool Database::insertMove(QString move, QString userName, QString gameName){
    QSqlQuery query;
    QDateTime dt;

    //Get the current date and time
    QString dateTime = QDateTime::currentDateTime().toString("yyyy-dd-MM HH:mm:ss");
    //Prepare SQL Script with place holders for the fields to be inserted
    query.prepare("INSERT INTO `battleship`.`moves` (`Move`, `UserName`, `GameName`, `TimeDate`) "
                  "VALUES (:move, :userName, :game, :dateTime)");
    //Replace the place holders with the actual values to be instered into the database
    query.bindValue(":move", move);
    query.bindValue(":userName", userName);
    query.bindValue(":game", gameName);
    query.bindValue(":dateTime", dateTime);
    //Send the SQL command, returning whether it was successful or not.
    if(query.exec())
        return true;
    else{
        error = query.lastError().text();
        qDebug() << error;
        return false;
    }
}
//Retrieve all moves for a specified game
QSqlQuery Database::getAllGameMoves(QString gameName){
    QSqlQuery query;
    //Prepare the SQL Script
    query.prepare("SELECT * FROM battleship.moves WHERE GameName = :Game");
    //Replace the placehold
    query.bindValue(":Game", gameName);
    //Execute the SQL Script
    if(query.exec()){
        if(debugging){  //Print the returned table
            int columns = query.record().count();
            int rows = query.size();
            QString temp = "";
            for(int r = 0; r < rows; r++){
                if (query.next()){
                    for(int c = 0; c < columns; c++){
                        temp += query.value(c).toString() + ", ";
                    }
                }
                qDebug() << temp;   //Output the row
                temp = "";  //Clear the temporary QString holder
            }
        }
        return query;   //Return the table
    }
    else{
        error = query.lastError().text();
        qDebug() << error;
        return query;
    }
}
//Retrieve all Player moves for a specified game
QSqlQuery Database::getPlayerGameMoves(QString gameName, QString userName){
    QSqlQuery query;
    //Prepare the SQL Script
    query.prepare("SELECT * FROM battleship.moves WHERE GameName = :Game AND UserName = :userName");
    //Replace the placehold
    query.bindValue(":Game", gameName);
    query.bindValue(":userName", userName);
    //Execute the SQL Script
    if(query.exec()){
        if(debugging){  //Print the returned table
            int columns = query.record().count();
            int rows = query.size();
            QString temp = "";
            for(int r = 0; r < rows; r++){
                if (query.next()){
                    for(int c = 0; c < columns; c++){
                        temp += query.value(c).toString() + ", ";
                    }
                }
                qDebug() << temp;   //Output the row
                temp = "";  //Clear the temporary QString holder
            }
        }
        return query;   //Return the table
    }
    else{
        error = query.lastError().text();
        qDebug() << error;
        return query;
    }
}
//Insert a Player into the database
bool Database::insertPlayer(QString userName, QString password){
    QSqlQuery query;
    //Prepare SQL Script with place holders for the fields to be inserted
    query.prepare("INSERT INTO `battleship`.`players` (`UserName`, `Password`) "
                  "VALUES (:userName, :password)");
    //Replace the place holders with the actual values to be instered into the database
    query.bindValue(":userName", userName);
    query.bindValue(":password", password);
    //Send the SQL command, returning whether it was successful or not.
    if(query.exec())
        return true;
    else{
        error = query.lastError().text();
        qDebug() << error;
        return false;
    }
}
//Retrieve all Players from the Database
QSqlQuery Database::getAllPlayers(){
    QSqlQuery query;
    //Prepare the SQL Script
    query.prepare("SELECT * FROM battleship.players");
    //Execute the SQL Script
    if(query.exec()){
        if(debugging){  //Print the returned table
            int columns = query.record().count();
            int rows = query.size();
            QString temp = "";
            for(int r = 0; r < rows; r++){
                if (query.next()){
                    for(int c = 0; c < columns; c++){
                        temp += query.value(c).toString() + ", ";
                    }
                }
                qDebug() << temp;   //Output the row
                temp = "";  //Clear the temporary QString holder
            }
        }
        return query;   //Return the table
    }
    else{
        error = query.lastError().text();
        qDebug() << error;
        return query;
    }
}
//Retrieve a specified player with matching password
QSqlQuery Database::getPlayer(QString userName, QString password){
    QSqlQuery query;
    //Prepare the SQL Script
    query.prepare("SELECT * FROM battleship.players WHERE UserName = :userName AND Password = :password");
    //Replace the placehold
    query.bindValue(":userName", userName);
    query.bindValue(":password", password);
    //Execute the SQL Script
    if(query.exec()){
        if(debugging){  //Print the returned table
            int columns = query.record().count();
            int rows = query.size();
            QString temp = "";
            for(int r = 0; r < rows; r++){
                if (query.next()){
                    for(int c = 0; c < columns; c++){
                        temp += query.value(c).toString() + ", ";
                    }
                }
                qDebug() << temp;   //Output the row
                temp = "";  //Clear the temporary QString holder
            }
        }
        return query;   //Return the table
    }
    else{
        error = query.lastError().text();
        qDebug() << error;
        return query;
    }
}
//Insert a Ship for a game into the database
bool Database::insertShip(QString ship, QString gameName, QString userName, QVector<QString> coordinates, int shipSize){
    QString coords;
    for(int i = 0; i < shipSize; i++){
        coords += coordinates[i] + ",";
    }

    QSqlQuery query;
    //Prepare SQL Script with place holders for the fields to be inserted
    query.prepare("INSERT INTO `battleship`.`ships` (`userName`, `shipName`, `shipSize`, `gameName`, `coordinates`) "
                  "VALUES (':userName', ':shipName', ':shipSize', ':gameName', ':coordinates');");
    //Replace the place holders with the actual values to be instered into the database
    query.bindValue(":userName", userName);
    query.bindValue(":shipName", ship);
    query.bindValue(":shipSize", QString::number((shipSize));
    query.bindValue(":gameName", gameName);
    query.bindValue(":coordinates", coords);
    //Send the SQL command, returning whether it was successful or not.
    if(query.exec())
        return true;
    else{
        error = query.lastError().text();
        qDebug() << error;
        return false;
    }
}
//Retrieve all Ships for a game from the Database
QSqlQuery Database::getAllPlayerShips(QString userName){
    QSqlQuery query;
    //Prepare the SQL Script
    query.prepare("SELECT * FROM battleship.ships WHERE userName = :UserName");
    //Replace the placehold
    query.bindValue(":UserName", userName);
    //Execute the SQL Script
    if(query.exec()){
        if(debugging){  //Print the returned table
            int columns = query.record().count();
            int rows = query.size();
            QString temp = "";
            for(int r = 0; r < rows; r++){
                if (query.next()){
                    for(int c = 0; c < columns; c++){
                        temp += query.value(c).toString() + ", ";
                    }
                }
                qDebug() << temp;   //Output the row
                temp = "";  //Clear the temporary QString holder
            }
        }
        return query;   //Return the table
    }
    else{
        error = query.lastError().text();
        qDebug() << error;
        return query;
    }
}

