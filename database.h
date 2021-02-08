#ifndef DATABASE_H
#define DATABASE_H

#include "datafromfile.h"

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QMessageBox>

/* Директивы имен таблицы, полей таблицы и базы данных */
#define DATABASE_DRIVER         driver_f
#define DATABASE_HOSTNAME       ip_f
#define DATABASE_PORT           port_f
#define DATABASE_NAME           dbName_f
#define DATABASE_USER           userName_f
#define DATABASE_PASS           userPass_f

#define TABLE_CARGO             nameTable_c_f
#define TABLE_PASSENGER         nameTable_p_f


class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();
    /* Методы для непосредственной работы с классом
     * Подключение к базе данных и вставка записей в таблицу
     * */
    void connectToDataBase();
    /* Внутренние методы для работы с базой данных
     * */
private:
    bool openDataBase();
    void closeDataBase();
private:
    // Сам объект базы данных, с которым будет производиться работа
    QSqlDatabase    db;
};

#endif // DATABASE_H
