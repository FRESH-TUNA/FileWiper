#include "deletefile.h"
#include "mainwindow.h"
#include "dropSiteWidgetForFastDelete.h"
#include "selectprocedurewindow.h"
#include "deletefile.h"

#include <QTableWidget>
#include <QPushButton>
#include <QHeaderView>
#include <QMimeData>
#include <QHBoxLayout>

mainWindow::mainWindow(QWidget *parent) :
    QDialog(parent)
{
    dWidget = new dropSiteWidgetForFastDelete;
    clearButton = new QPushButton(tr("Clear"));
    selectProcedureWindow = new SelectProcedureWindow;
    clearButton->setFixedSize(200, 200);

    layout = new QHBoxLayout(this);
    layout->addWidget(dWidget);
    layout->addWidget(clearButton);

    connect(clearButton, &QAbstractButton::clicked, selectProcedureWindow, &SelectProcedureWindow::show);
    setWindowTitle(tr("DeathSide"));
    setFixedSize(500, 500);
}

mainWindow::~mainWindow()
{
}

