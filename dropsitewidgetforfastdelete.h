#ifndef DROPSITEWIDGETFORFASTDELETE_H
#define DROPSITEWIDGETFORFASTDELETE_H

class QMessageBox;
#include "dropsitewidget.h"

class dropSiteWidgetForFastDelete : public dropSiteWidget
{
    Q_OBJECT
public:
    explicit dropSiteWidgetForFastDelete(QWidget *parent = nullptr);

protected:
     void dropEvent(QDropEvent *event) override;

private:
     QMessageBox *msgBox;
};

#endif // DROPSITEWIDGETFORFASTDELETE_H
