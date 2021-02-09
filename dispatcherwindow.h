#ifndef DISPATCHERWINDOW_H
#define DISPATCHERWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DispatcherWindow; }
QT_END_NAMESPACE

class DispatcherWindow : public QMainWindow
{
    Q_OBJECT

public:
    DispatcherWindow(QWidget *parent = nullptr);
    ~DispatcherWindow();

signals:
    void openAuthorizationWindow();  // Сигнал для первого окна на открытие

private:
    Ui::DispatcherWindow *ui;
};
#endif // DISPATCHERWINDOW_H
