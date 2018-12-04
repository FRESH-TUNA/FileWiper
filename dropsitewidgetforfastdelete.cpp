#include "dropsitewidgetforfastdelete.h"
#include "deletefile.h"
#include <QDropEvent>
#include <QMessageBox>

dropSiteWidgetForFastDelete::dropSiteWidgetForFastDelete(QWidget *parent)
    : dropSiteWidget(parent)
{
    msgBox = new QMessageBox;
    msgBox->setText("warning");
    msgBox->setInformativeText("Are you sure to delete file?");
    msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox->setDefaultButton(QMessageBox::Cancel);
}


void dropSiteWidgetForFastDelete::dropEvent(QDropEvent *event)
{
    QString wantToDelete = event->mimeData()->text();
    int confirm;

    wantToDelete.remove(0, 8);
    setBackgroundRole(QPalette::Dark);
    event->acceptProposedAction();

    confirm = msgBox->exec();

    if(confirm == QMessageBox::Yes)
        DeleteFile::selectDeleteProcedure(wantToDelete, 0);
}
