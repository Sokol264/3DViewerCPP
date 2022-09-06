#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

#include "command.h"

MainWindow::MainWindow(Controller *controller, QWidget *parent)
    : QMainWindow(parent)
    , controller(controller)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    controller->SetDrawer(ui->openGLWidget);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_openModelFile_clicked() {
    auto filename = QFileDialog::getOpenFileName(this, tr("Open Object file"),
                                               "/", tr("OBJ (*.obj)"));
    if (!filename.isEmpty()) {
        ReadObjectFileCommand command(controller);
        command.SetFilename(filename.toStdString());
        command.Execute();
    }
}


void MainWindow::on_openTextureFile_clicked()
{
    auto filename = QFileDialog::getOpenFileName(this, tr("Open Texture file"),
                                               "/", tr("Image (*.png *.jpeg *.jpg *.bmp)"));
    if (!filename.isEmpty()) {
        ReadTextureFileCommand command(controller);
        command.SetFilename(filename.toStdString());
        command.Execute();
    }
}

