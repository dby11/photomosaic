#ifndef PHOTOHANDLER_H
#define PHOTOHANDLER_H

#include <QImage>
#include <QString>

class PhotoHandler
{
public:
    PhotoHandler(QString i, QString d);
    QString search_database(std::vector<QColor> db_pixels, QColor colors);
    QImage construct_mosaic();
    std::vector<QColor> PhotoHandler::load_database();
private:
    QString database;
    QString imageName;
    QImage image;
    std::vector<QString> fileNames;
};

#endif // PHOTOHANDLER_H
