#include "mainwindow.h"

#include <QApplication>
#include "orientationmap.h"
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDebug>
#include <QImage>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QFile csv("db.txt");
    csv.remove();
    csv.open((QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text));
    QTextStream stream(&csv);
    QDir base("Dataset/");
    QStringList directories = base.entryList();
    foreach(QString dirName, directories) {
        if(dirName=="."|| dirName==".."){
            continue;
        }
        QDir dir(base.dirName()+"/"+dirName);
        QStringList files = dir.entryList();
        foreach(QString fileName, files){
            if(fileName=="."|| fileName==".."){
                continue;
            }
            QString path(base.dirName()+"/"+dir.dirName()+"/"+fileName);
            OrientationMap orientationMap;
                orientationMap.setParams(path.toUtf8().constData());
                orientationMap.computeBasicMapGPU();
                QString outputString{af::toString("",af::flat(orientationMap.getOMapAF_basic()),6,false)};
                outputString.remove(0,outputString.indexOf(']')+2);
                outputString.replace(QRegExp("\\s+"),",");
                stream << dirName << outputString << "\n";



        }
    }
    csv.close();

    return a.exec();
}
