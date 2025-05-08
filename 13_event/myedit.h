#ifndef MYEDIT_H
#define MYEDIT_H
#include <QLineEdit>

class MyEdit:public QLineEdit
{
    Q_OBJECT
public:
    MyEdit(QWidget* parent = 0);
protected:
    void keyPressEvent(QKeyEvent*);
    bool event(QEvent* pevent);
};

#endif // MYEDIT_H
