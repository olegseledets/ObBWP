#ifndef AUTHORIZATIONWINDOW_H
#define AUTHORIZATIONWINDOW_H

#include <QDialog>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSql>
#include <QSqlDatabase>             // Подключение к БД
#include <QSqlError>                // Отслеживание ошибок поключения к БД
#include <QDebug>                   // Для вывода сообщения пользователю

/* Подключаем заголовочный файл для работы с информацией, которая помещена в базу данных */
#include "database.h"

namespace Ui {
class AuthorizationWindow;
}

class AuthorizationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AuthorizationWindow(QWidget *parent = nullptr);
    ~AuthorizationWindow();

private slots:
    void on_butt_enter_clicked();

    void on_pushButton_clicked();

private:
    void verifyUser();
    Ui::AuthorizationWindow *ui;
    /* В проекте используются объекты для взаимодействия с информацией в базе данных
     * */
    DataBase        *db;
};

#endif // AUTHORIZATIONWINDOW_H
