#ifndef CHILDWINDOW_H
#define CHILDWINDOW_H

#include <QDialog>
// #include "mainwindow.h"

namespace Ui {
class ChildDialog;
}

class ChildDialog : public QDialog
{
    Q_OBJECT

signals:
    void showMainSig();

public:
    explicit ChildDialog(QWidget *parent = nullptr);
    ~ChildDialog();

private:
    Ui::ChildDialog *ui;

private:
    QWidget *parent;

public slots:
    void showMianDialog();
};

#endif // CHILDWINDOW_H
