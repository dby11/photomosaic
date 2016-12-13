#ifndef PHOTOHANDLER_H
#define PHOTOHANDLER_H

#include <QImage>
#include <QString>

class PhotoHandler
{
public:
    PhotoHandler(QString i, QString d);
    QImage construct_mosaic();

private:
    QString database;
    QString imageName;
    QImage image;
    std::vector<QString> fileNames;
};

#endif // PHOTOHANDLER_H
