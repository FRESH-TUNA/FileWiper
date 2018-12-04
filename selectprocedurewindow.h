#ifndef SELECTPROCEDUREWINDOW_H
#define SELECTPROCEDUREWINDOW_H

#include <QDialog>

class QLabel;
class QHBoxLayout;
class QVBoxLayout;
class QPushButton;
class QDialogButtonBox;
class QComboBox;
class dropSiteWidget;
class QMessageBox;
class QMimeData;

class SelectProcedureWindow : public QDialog
{
    Q_OBJECT
public:
    explicit SelectProcedureWindow(QWidget *parent = nullptr);

public slots:
    void selectFileOnDrag(const QString wantToDelete);

private:
    void setUI();
    void setButton();
    void setLabels();
    void setDWidget();
    void setComboBox();
    void setLayouts();
    void pathFuncLayout();

    void buttonConnectFunc();
    void dWidgetConnectFunc();
    void selectFile();
    void deleteFile();

    QString wantToDelete;
    dropSiteWidget *dWidget;
    QHBoxLayout *pathLayout;
    QVBoxLayout *totalLayout;
    QComboBox *selectProcBox;
    QLabel *pathExplain;
    QLabel *selectProcExplain;
    QDialogButtonBox *buttons;
    QPushButton *pathButton;
    QPushButton *deleteButton;
    QPushButton *cancelButton;
    QMessageBox *msgBox;
};

#endif // SELECTPROCEDUREWINDOW_H
