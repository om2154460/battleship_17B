#ifndef DATABASE_H
#define DATABASE_H
//Author Brandon Robinson 2016
#include <QSql>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QString>

class Database
{
public:
    Database();
    ~Database();
    bool createConnection(QString hostName, QString databaseName, QString userName, QString password);
    bool checkConnection;
    void closeConnection();
    bool createSchema();
    void createTables();
    bool createGame(QString gameName, QString player1, QString player2);
    QSqlQuery getAllGames();
    bool createMessage(QString gameName, QString player, QString message);
    QSqlQuery getGameMessages(QString gameName);
    bool insertMove(QString move, QString userName, QString gameName);
    QSqlQuery getAllGameMoves(QString gameName);
    QSqlQuery getPlayerGameMoves(QString gameName, QString userName);
    bool insertPlayer(QString userName, QString Password);
    QSqlQuery getAllPlayers();
    QSqlQuery getAllPlayerShips(QString userName);
    QSqlQuery getPlayer(QString userName, QString password);
    bool insertShip(QString ship, QString gameName, QString userName, QVector<QString> coordinates, int shipSize);
    QSqlQuery getAllShips();
    QSqlQuery getShip(QString userName, QString gameName);


    //setters and getters
    bool getConnected(){return connected;}
    QSqlDatabase getDatabase(){return database;}
    QString getError(){return error;}


private:
    bool debugging;

    QString hostName;
    QString databaseName;
    QString userName;
    QString password;

    QSqlDatabase database;
    bool connected;
    QString error;

};

#endif // DATABASE_H
