#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Controller *controller, QWidget *parent = nullptr);
    ~MainWindow();
    Controller *controller;

private slots:
    void on_openModelFile_clicked();
    void on_openTextureFile_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
