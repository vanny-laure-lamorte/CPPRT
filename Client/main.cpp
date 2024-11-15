#include "header/ClientUi.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    clientUi w;
    w.show();
    return a.exec();
}
