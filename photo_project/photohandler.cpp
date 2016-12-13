#include "photohandler.h"
#include <QDirIterator>
#include <QColor>
#include <QPainter>
#include <QDir>
#include <algorithm>
#include <functional>
#include <QDebug>
#include <QFileDialog>
#include <QCoreApplication>

double norm(QColor a, QColor b) {
    int red = a.red() - b.red();
    int blue = a.blue() - b.blue();
    int green = a.green() - b.green();
    return sqrt(red*red + blue*blue + green*green);
}

QColor avgpixel(QImage& img, int wstart, int wend, int hstart, int hend)
{
    int total_red = 0;
    int total_green = 0;
    int total_blue = 0;
    int wid = wend - wstart;
    int ht = hend - hstart;
    for (int row = hstart; row < hend; ++row)
    {
        for(int col = wstart; col <wend; ++col)
        {
            QColor pixels = img.pixel(col,row);
            total_red += pixels.red();
            total_green += pixels.green();
            total_blue += pixels.blue();
        }
    }
    int avg_red = total_red/(wid*ht);
    int avg_blue = total_blue/(wid*ht);
    int avg_green = total_green/(wid*ht);

    QColor avg_rgb(avg_red, avg_blue, avg_green);
    return avg_rgb;
}

PhotoHandler::PhotoHandler(QString i, QString d): database(d), imageName(i) {}

QString PhotoHandler::search_database(std::vector<QColor> db_pixels, QColor colors)
{
    auto closest = std::min_element(db_pixels.begin(), db_pixels.end(),
        [=](QColor colors1, QColor colors2){return norm(colors1, colors) < norm(colors2, colors);});
    return fileNames[std::distance(db_pixels.begin(), closest)];
}

std::vector<QColor> PhotoHandler::load_database()
{
    std::vector<QColor> v;
    QDir dir(database);
    QDirIterator it(dir);
    it.next();
    it.next();

    while(it.hasNext()){
        it.next();
        qDebug() << it.filePath();
        QImage tmp(it.filePath());
        tmp = tmp.scaled(40,30);
        QColor tmp_pix = avgpixel(tmp, 1, tmp.width(),1, tmp.height());
        v.push_back(tmp_pix);
        qDebug() << tmp_pix.blue();

        fileNames.push_back(it.filePath());
    }

    return v;
}

QImage PhotoHandler::construct_mosaic() {
    /*Basic algorithm outline
     *1. Get list of fileNames
     *2. Find average RGB values for fileNames in database
     *3. Read in image
     *
     *4. Get average RGB values for each subimage in the image
     *5. Find best match within the photo database for each image based on avg RGB
     *6. Assemble mosaic
    */
    int scaled_width = 40;
    int scaled_height = 30;

    std::vector<int> wcount;
    for( int i = 0; i < scaled_width; i++ )
        wcount.push_back( i*10 );
    wcount.push_back(scaled_width*10 - 1);
    std::vector<int> hcount;
    for( int i = 0; i < scaled_height; i++ )
        hcount.push_back( i*10);
    hcount.push_back(scaled_height*10 - 1);
    qDebug() << hcount[0];

    QSize size(1600,900);
    image.load(imageName);
    image = image.scaled(scaled_width*10, scaled_height*10);

    if (image.isNull())
    {
        QString a = "cries";
        qDebug() << a;
    }

    qDebug() << "width: "<<image.width();
    qDebug() << "height: " << image.height();

    std::vector<QColor> db_pixels = this->load_database();
    qDebug() << "random red to show that this works:"<<db_pixels[13].red();

    QImage mosaic(size,QImage::Format_RGB32);
    mosaic.fill(0);
    QPainter painter;
    painter.begin(&mosaic);
    for (int w = 1; w<wcount.size(); ++w)
    {
        for(int h = 1; h<hcount.size(); ++h)
        {
            qDebug() << "enter for";
            QColor image_colors = avgpixel(this->image, wcount[w-1], wcount[w], hcount[h-1], hcount[h]); //you're using height and width rather than points

            QString file = this->search_database(db_pixels, image_colors);
            QImage piece(file);
            piece = piece.scaled(40,30);
            painter.drawImage(QRect((w-1)*40,h*30,40,30),piece);
        }
    }
    return mosaic;
}
