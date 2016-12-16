#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "photohandler.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Currently only .png support
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image File"), "C://", "Image files (*.png)");
    ui->lineEdit->setText(filename);

}

void MainWindow::on_pushButton_2_clicked()
{
    //User must choose a directory
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->lineEdit_2->setText(dir);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString fileName = ui->lineEdit->text();
    QString directory = ui->lineEdit_2->text();
    PhotoHandler photo(fileName, directory);

    QImage mosaic = photo.construct_mosaic();

    //Personal directory - will update with a "save location" button
    mosaic.save("C:/testing_pictures/mosaic.png");


}
