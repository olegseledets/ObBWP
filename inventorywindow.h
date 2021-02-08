#ifndef INVENTORYWINDOW_H
#define INVENTORYWINDOW_H

#include <QDialog>

namespace Ui {
class InventoryWindow;
}

class InventoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InventoryWindow(QWidget *parent = nullptr);
    ~InventoryWindow();

private:
    Ui::InventoryWindow *ui;
};

#endif // INVENTORYWINDOW_H
