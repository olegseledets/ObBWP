#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

/* Методы для подключения к базе данных
 * */
void DataBase::connectToDataBase()
{
    if(openDataBase()) {
    } else {
        QMessageBox::critical(NULL,QObject::tr("Ошибка"), db.lastError().text());
    }
}

/* Метод для открытия базы данных
 * */
bool DataBase::openDataBase()
{
    /* Создание подключения к базе данных
     * Возвращает статус подключения
     * */
    QSqlDatabase db = QSqlDatabase::addDatabase(DATABASE_DRIVER);
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);
    db.setPort(DATABASE_PORT.toInt());
    db.setUserName(DATABASE_USER);
    db.setPassword(DATABASE_PASS);
    return db.open();
    if(openDataBase()) {
        QMessageBox::information(NULL,QObject::tr("Успех"), "подключение успешно");
    } else {
        QMessageBox::critical(NULL,QObject::tr("Ошибка"), db.lastError().text());
    }
}

/* Методы закрытия базы данных
 * */
void DataBase::closeDataBase()
{
    db.close();
}
