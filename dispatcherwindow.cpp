#include "dispatcherwindow.h"
#include "ui_dispatcherwindow.h"

DispatcherWindow::DispatcherWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DispatcherWindow)
{
    ui->setupUi(this);
}

DispatcherWindow::~DispatcherWindow()
{
    delete ui;
}

