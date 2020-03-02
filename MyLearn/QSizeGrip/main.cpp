#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(400,300);
    SubWindow subwindow(&w);
    subwindow.move(200,180);
    w.show();

    return a.exec();
}
