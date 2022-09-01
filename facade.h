#ifndef FACADE_H
#define FACADE_H

#include "filemanager.h"
#include "drawer.h"

class Facade
{
public:
    Facade();
    void SetDrawer(Drawer *drawer);
    void ReadObjectModelFromFile(std::string filename);
    void ReadTextureFromFile(std::string filename);
private:
    FileManager fileManager;
    Drawer *drawer;
    Figure figure;
};

#endif // FACADE_H
