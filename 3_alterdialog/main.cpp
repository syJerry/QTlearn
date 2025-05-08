#include "maindialog.h"
#include "mydialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainDialog w;
    MyDialog m;
    if(w.exec()== QDialog::Accepted)
    {
        m.show();
        return a.exec();
    }
    else
    {
        return 0;
    }


}
