#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "photohandler.h"
#include <QDebug>
#include <QFileDialog>
#include <QImage>

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

//Image is for choosing the original image
void MainWindow::on_pushButton_clicked()
{
    //Currently only .png support
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image File"), "C://", "Image files (*.png)");
    ui->lineEdit->setText(filename);

}

//Database is for choosing a photo database
void MainWindow::on_pushButton_2_clicked()
{
    //User must choose a directory
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "C://", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->lineEdit_2->setText(dir);
}

//OK button initiates photomosaic
void MainWindow::on_pushButton_3_clicked()
{
    QString fileName = ui->lineEdit->text();
    QString directory = ui->lineEdit_2->text();
    PhotoHandler photo(fileName, directory);

    QImage mosaic = photo.construct_mosaic();

    QString saveas = ui->lineEdit_3->text() + "/" + ui->lineEdit_4->text();
    qDebug() << saveas;
    mosaic.save(saveas);


}

void MainWindow::on_pushButton_4_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "C://", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->lineEdit_3->setText(dir);
}
