#ifndef DROPSITEWIDGET_H
#define DROPSITEWIDGET_H

#include <QLabel>
class QMimeData;

class dropSiteWidget : public QLabel
{
     Q_OBJECT
public:
    explicit dropSiteWidget(QWidget *parent = nullptr);

signals:
    void dropEventHappen(const QString wantToDelete = nullptr);


protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
};

#endif // DROPSITEWIDGET_H
