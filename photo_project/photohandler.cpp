#include "photohandler.h"

PhotoHandler::PhotoHandler(QString i, QString d): database(d), imageName(i) {}

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

QString search_database(std::vector<QColor> db_pixels, QColor colors)
{

}

std::vector<QColor> PhotoHandler::load_database()
{

}

QImage construct_mosaic() {
    /*Basic algorithm outline
     *1. Get list of fileNames
     *2. Find average RGB values for fileNames in database
     *3. Read in image
     *
     *4. Get average RGB values for each subimage in the image
     *5. Find best match within the photo database for each image based on avg RGB
     *6. Assemble mosaic
    */
}
