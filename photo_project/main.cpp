#include "mainwindow.h"
#include <photohandler.h>
#include <QApplication>
#include <QFileDialog>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /*QString test_file("C:/Users/Derek Y/Desktop/for_coding_practice.png");
    QString test_directory = "C:/Users/Derek Y/Desktop/database/";
    */

    PhotoHandler test(,test_directory);
    QImage idea = test.construct_mosaic();
    QString testmosaic = "C:/testing_pictures/cats.png";
    idea.save(testmosaic);
    return a.exec();
}
