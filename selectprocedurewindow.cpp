#include "dropsitewidget.h"
#include "deletefile.h"
#include "selectprocedurewindow.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QComboBox>
#include <QFileDialog>
#include <QMessageBox>

SelectProcedureWindow::SelectProcedureWindow(QWidget *parent) :
    QDialog(parent)
{
    setUI();
    dWidgetConnectFunc();
    buttonConnectFunc();

    msgBox = new QMessageBox;
    msgBox->setText("warning");
    msgBox->setInformativeText("Are you sure to delete file?");
    msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox->setDefaultButton(QMessageBox::Cancel);
}

void SelectProcedureWindow::dWidgetConnectFunc() {
    connect(dWidget, &dropSiteWidget::dropEventHappen, this, &SelectProcedureWindow::selectFileOnDrag);
}

void SelectProcedureWindow::buttonConnectFunc() {
    connect(pathButton, &QAbstractButton::clicked, this, &SelectProcedureWindow::selectFile);
    connect(deleteButton, &QAbstractButton::clicked, this, &SelectProcedureWindow::deleteFile);
    connect(cancelButton, &QAbstractButton::clicked, this, &SelectProcedureWindow::close);
}

void SelectProcedureWindow::selectFileOnDrag(const QString wantToDelete) {
    this->wantToDelete = wantToDelete;
}

void SelectProcedureWindow::selectFile() {
    wantToDelete = QFileDialog::getOpenFileName(this,
          tr("Select file"), "",
          tr(";;All Files (*)"));
    dWidget->setText(wantToDelete);
}

void SelectProcedureWindow::deleteFile() {
    int confirm;
    confirm = msgBox->exec();

    if(confirm == QMessageBox::Yes)
        DeleteFile::selectDeleteProcedure(wantToDelete, 0);
}

void SelectProcedureWindow::setUI() {
    setContentsMargins(30, 30, 30, 30);
    setButton();
    setDWidget();
    setLabels();
    setComboBox();
    pathFuncLayout();
    setLayouts();
    setWindowTitle(tr("select procedure"));
    setFixedSize(500, 400);
}

void SelectProcedureWindow::setButton() {
    buttons = new QDialogButtonBox;
    pathButton = new QPushButton((tr("Path")), this);
    cancelButton = new QPushButton((tr("Cancel")));
    deleteButton = new QPushButton((tr("Delete")));

    pathButton->setFixedSize(50, 50);
    buttons->addButton(deleteButton, QDialogButtonBox::ActionRole);
    buttons->addButton(cancelButton, QDialogButtonBox::RejectRole);
}

void SelectProcedureWindow::setDWidget() {
    dWidget = new dropSiteWidget;
    dWidget->setFixedSize(350, 50);
}

void SelectProcedureWindow::setLayouts() {
    totalLayout = new QVBoxLayout(this);
    totalLayout->addWidget(pathExplain);
    totalLayout->addLayout(pathLayout);
    totalLayout->addWidget(selectProcExplain);
    totalLayout->addWidget(selectProcBox);
    totalLayout->addWidget(buttons);
}

void SelectProcedureWindow::setComboBox() {
    selectProcBox = new QComboBox;
    selectProcBox->addItem("easy");
    selectProcBox->addItem("middle");
    selectProcBox->addItem("crazy");
    selectProcBox->setFixedSize(350, 30);
}

void SelectProcedureWindow::pathFuncLayout() {
    pathLayout = new QHBoxLayout;
    pathLayout->addWidget(dWidget);
    pathLayout->addWidget(pathButton);
}

void SelectProcedureWindow::setLabels() {
    pathExplain = new QLabel(tr("Select File"));
    pathExplain->setFixedSize(400, 20);
    selectProcExplain = new QLabel(tr("Select Procedure"));
    selectProcExplain->setFixedSize(400, 20);
}

