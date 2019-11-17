#include <QCoreApplication>
#include <iostream>
#include "../../Qt_test/Qt_test/qt_test.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Qt_test test;
    test.py_print();
    return a.exec();
}
