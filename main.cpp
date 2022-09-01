#include "mainwindow.h"
#include "Controller/controller.h"
#include "facade.h"
#include <QApplication>
#include "filemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Facade facade;
    Controller controller(&facade);
    MainWindow w(&controller);
    w.show();
    return a.exec();
}
