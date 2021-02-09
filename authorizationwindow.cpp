#include "authorizationwindow.h"
#include "ui_authorizationwindow.h"


AuthorizationWindow::AuthorizationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthorizationWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);          //Отключает «умолчальные» хинты (заголовок, кнопки закрытия и т.п.)
    this->setWindowFlags(Qt::FramelessWindowHint);          //Убирает рамку окна
    this->setAttribute(Qt::WA_TranslucentBackground);       //Убирает фон окна

    adminWindow = new AdministrationWindow();
    connect(adminWindow, &AdministrationWindow::openAuthorizationWindow, this, &AuthorizationWindow::show);

    dispWindow = new DispatcherWindow();
    connect(dispWindow, &DispatcherWindow::openAuthorizationWindow, this, &AuthorizationWindow::show);

    inventWindow = new InventoryWindow();
    connect(inventWindow, &InventoryWindow::openAuthorizationWindow, this, &AuthorizationWindow::show);
}

AuthorizationWindow::~AuthorizationWindow()
{
    delete ui;
}

void helloMessage(QString login){
    QMessageBox msg;
    msg.setIconPixmap(QPixmap(":/i_Logo/icons8-грузовое-судно-50.png"));
    msg.setWindowTitle("Приветствие");
    msg.setText("Добро пожаловать: "+login+"!");
    msg.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    msg.exec();
}

void AuthorizationWindow::verifyUser()
{
    QSqlQuery query;                                                                    // Запрос
    QString login = ui->text_login->text();                                             // Логин
    QString password = ui->text_password->text();                                       // Введенный пароль

    query.exec("SELECT UserPassword FROM users WHERE UserLogin = '"+login+"'");         // Просим базу дать нам пароль под текущий логин
    query.first();
    QString verifyPass = query.value(0).toString();                                     // Получаем настоящий пароль от пользователя

    query.exec("SELECT UserDepartment FROM users WHERE UserLogin = '"+login+"'");          // Просим базу дать нам пароль под текущий логин
    query.first();
    QString userAccessLevel = query.value(0).toString();                                // Получаем настоящий пароль от пользователя

    if(verifyPass != password) {
        QMessageBox::critical(NULL,QObject::tr("Ошибка"),"Логин или пароль\nне верный!");            // Сообщение если логин не верен
    } else {
        QSettings *uSett = new QSettings(UserSett,QSettings::IniFormat);
        uSett->setValue("User_Settings/currentUser", login);
        uSett->sync();
        ui->text_password->setText("");
        if (userAccessLevel == "1") {
            adminWindow->show();                                                        // Показываем окно админа
            this->close();                                                              // Закрываем основное окно
            helloMessage(login);
        }
        else if (userAccessLevel == "2") {
            dispWindow->show();                                                         // Показываем окно диспетчера
            this->close();                                                              // Закрываем основное окно
            helloMessage(login);
        } else if (userAccessLevel == "3") {
            inventWindow->show();
            this->close();
            helloMessage(login);
        } else {
            QMessageBox::critical(NULL,QObject::tr("Ошибка"),"Программный модуль\nеще не разработан\nожидайте!");
        }
    }
}

void AuthorizationWindow::on_butt_enter_clicked()
{
    /* Первым делом необходимо создать объект, который будет использоваться для работы с данными нашей БД
     * и инициализировать подключение к базе данных
     */
    db = new DataBase();
    db->connectToDataBase();
    verifyUser();
}

void AuthorizationWindow::on_butt_eyes_pressed()
{
    ui->text_password->setEchoMode(QLineEdit::Normal);
}

void AuthorizationWindow::on_butt_eyes_released()
{
    ui->text_password->setEchoMode(QLineEdit::Password);
}

void AuthorizationWindow::on_butt_exit_clicked()
{
    this->close();          //Закрыть форму авторизации
}
