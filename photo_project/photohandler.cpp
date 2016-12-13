#include "photohandler.h"

PhotoHandler::PhotoHandler(QString i, QString d): database(d), imageName(i) {}


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
