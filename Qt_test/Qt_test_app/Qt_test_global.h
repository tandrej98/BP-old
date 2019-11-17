#ifndef QT_TEST_GLOBAL_H
#define QT_TEST_GLOBAL_H

#include <QtCore/qglobal.h>
#include <string>

#if defined(QT_TEST_LIBRARY)
#  define QT_TEST_EXPORT Q_DECL_EXPORT
#else
#  define QT_TEST_EXPORT Q_DECL_IMPORT
#endif

extern "C" QT_TEST_EXPORT void py_print(std::string input);

#endif // QT_TEST_GLOBAL_H
