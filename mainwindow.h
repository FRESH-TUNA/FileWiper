#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>

class QHBoxLayout;
class QMimeData;
class QPushButton;
class QTableWidget;
class dropSiteWidgetForFastDelete;
class SelectProcedureWindow;
class DeleteFile;

namespace Ui {
class mainWindow;
}

class mainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private:
    dropSiteWidgetForFastDelete *dWidget;
    SelectProcedureWindow *selectProcedureWindow;
    QPushButton *clearButton;
    QHBoxLayout *layout;
};

#endif // MAINWINDOW_H
