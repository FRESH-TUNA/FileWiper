#include "deletefile.h"

void DeleteFile::selectDeleteProcedure(QString path, int procedure) {
        switch(procedure) {
          case 0: easyDelete(path);
          break;
          case 1: mediumDelete(path);
          break;
          case 2: hardDelete(path);
        }
}

void DeleteFile::easyDelete(QString path) {
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::WriteOnly))
         return;

     QByteArray buffer(file.size(), '\x00');
     file.write(buffer);
}

void DeleteFile::mediumDelete(QString path){
    qDebug() << path << " mediumDelete";
}

void DeleteFile::hardDelete(QString path){
    qDebug() << path << " hardDelete";
}
