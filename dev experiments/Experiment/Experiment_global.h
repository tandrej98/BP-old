#ifndef EXPERIMENT_GLOBAL_H
#define EXPERIMENT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(EXPERIMENT_LIBRARY)
#  define EXPERIMENT_EXPORT Q_DECL_EXPORT
#else
#  define EXPERIMENT_EXPORT Q_DECL_IMPORT
#endif

#endif // EXPERIMENT_GLOBAL_H
