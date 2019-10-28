#ifndef CPROGRESSDIALOG_H
#define CPROGRESSDIALOG_H

#include <DDialog>
#include <DWidget>
#include <DProgressBar>

#include <QWidget>

DWIDGET_USE_NAMESPACE

class CProgressDialog : public DDialog
{
    Q_OBJECT

public:
    enum EProgressDialogType {
        SaveDDF,
        LoadDDF
    };

public:
    explicit CProgressDialog(DWidget *parent = nullptr);
    void showProgressDialog(EProgressDialogType type);

signals:

public slots:
    void slotupDateProcessBar(int);

private:
    DProgressBar *m_progressBar;
    DLabel *m_label;


private:
    void initUI();


};

#endif // CPROGRESSDIALOG_H