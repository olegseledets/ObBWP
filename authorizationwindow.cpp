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
}

AuthorizationWindow::~AuthorizationWindow()
{
    delete ui;
}

void AuthorizationWindow::verifyUser()
{
    QSqlQuery query;                                                                    // Запрос
    QString login = ui->text_login->text();                                             // Логин
    QString password = ui->text_password->text();                                       // Введенный пароль

    query.exec("SELECT UserPassword FROM users WHERE UserLogin = '"+login+"'");         // Просим базу дать нам пароль под текущий логин
    query.first();
    QString verifyPass = query.value(0).toString();                                     // Получаем настоящий пароль от пользователя

    query.exec("SELECT AccessLevel FROM users WHERE UserLogin = '"+login+"'");          // Просим базу дать нам пароль под текущий логин
    query.first();
    QString userAccessLevel = query.value(0).toString();                                // Получаем настоящий пароль от пользователя

    if(verifyPass != password) {
        QMessageBox::critical(NULL,QObject::tr("Ошибка"),"Пароль не верен");            // Сообщение если логин не верен
    } else {
        QSettings *uSett = new QSettings(UserSett,QSettings::IniFormat);
        uSett->setValue("User_Settings/currentUser", login);
        uSett->sync();
        ui->text_password->setText("");
        if (userAccessLevel == "1")
        {
            adminWindow->show();                                                        // Показываем окно админа
            this->close();                                                              // Закрываем основное окно
        }
        else if (userAccessLevel == "2")
        {
            dispWindow->show();                                                         // Показываем окно диспетчера
            this->close();                                                              // Закрываем основное окно

            QMessageBox msg;
            msg.setIconPixmap(QPixmap(":/i_Logo/icons8-грузовое-судно-50.png"));
            msg.setWindowTitle("Приветствие");
            msg.setText("Добро пожаловать: "+login+"!");
            msg.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
            msg.exec();
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
}

void AuthorizationWindow::on_pushButton_clicked()
{
    this->close();          //Закрыть форму авторизации
}
