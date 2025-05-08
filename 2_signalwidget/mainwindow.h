#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class ChildDialog;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    ChildDialog* child_window;

public slots:
    void showChidDialog();
    void showMainDialog();
};
#endif // MAINWINDOW_H
