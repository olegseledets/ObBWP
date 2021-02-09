#ifndef AUTHORIZATIONWINDOW_H
#define AUTHORIZATIONWINDOW_H

#include <QDialog>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSql>
#include <QSqlDatabase>             // Подключение к БД
#include <QSqlError>                // Отслеживание ошибок поключения к БД
#include <QDebug>                   // Для вывода сообщения пользователю

#include "database.h"
#include "administrationwindow.h"
#include "dispatcherwindow.h"
#include "inventorywindow.h"

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

    void on_butt_eyes_pressed();

    void on_butt_eyes_released();

    void on_butt_exit_clicked();

private:
    void verifyUser();
    Ui::AuthorizationWindow *ui;

    DataBase             *db;
    AdministrationWindow *adminWindow;              // окно админа
    DispatcherWindow     *dispWindow;               // окно диспетчера
    InventoryWindow      *inventWindow;             // окно инвентаризации
};

#endif // AUTHORIZATIONWINDOW_H
