#ifndef DELETEFILE_H
#define DELETEFILE_H
#include <QtCore>

class DeleteFile {
public:
    static void selectDeleteProcedure(QString path, int procedure);

private:
    static void easyDelete(QString path);

    static void mediumDelete(QString path);

    static void hardDelete(QString path);
};

#endif // DELETEFILE_H
