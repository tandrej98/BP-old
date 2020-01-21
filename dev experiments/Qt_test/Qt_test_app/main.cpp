#include <QCoreApplication>
#include <iostream>
#include "C:\Users\Shadow\Git\Bakalarsky-projekt\dev experiments\Qt_test\Qt_test\qt_test.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Qt_test test;
	test.tf_test();
	//test.py_print("test");
    return a.exec();
}
