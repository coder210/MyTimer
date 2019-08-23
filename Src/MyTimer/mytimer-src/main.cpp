#include <QApplication>
#include "MyTimerWidget.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyTimerWidget w;
    w.show();

    return app.exec();
}



