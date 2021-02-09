#ifndef ADMINISTRATIONWINDOW_H
#define ADMINISTRATIONWINDOW_H

#include <QDialog>

namespace Ui {
class AdministrationWindow;
}

class AdministrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdministrationWindow(QWidget *parent = nullptr);
    ~AdministrationWindow();

signals:
    void openAuthorizationWindow();  // Сигнал для первого окна на открытие

private:
    Ui::AdministrationWindow *ui;
};

#endif // ADMINISTRATIONWINDOW_H
