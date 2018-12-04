#include "dropsitewidget.h"
#include "deletefile.h"
#include <QDragEnterEvent>
#include <QMimeData>

dropSiteWidget::dropSiteWidget(QWidget *parent)
    : QLabel(parent)
{
    setFixedSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAlignment(Qt::AlignCenter);
    setAcceptDrops(true);
    setAutoFillBackground(true);
    setText(tr("Drag file or folder"));
}

void dropSiteWidget::dragEnterEvent(QDragEnterEvent *event)
{
    setBackgroundRole(QPalette::Dark);
    event->acceptProposedAction();
}

void dropSiteWidget::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}

void dropSiteWidget::dropEvent(QDropEvent *event)
{
    QString wantToDelete = event->mimeData()->text();
    wantToDelete.remove(0, 8);
    setBackgroundRole(QPalette::Dark);
    event->acceptProposedAction();
    setText(wantToDelete);
    emit dropEventHappen(wantToDelete);
}

void dropSiteWidget::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}
