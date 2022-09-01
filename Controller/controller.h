#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "facade.h"

class Controller
{
public:
    Controller(Facade *facade);
    void SetDrawer(Drawer *drawer);
    void ReadObjectModelFromFile(std::string filename);
    void ReadTextureFromFile(std::string filename);
private:
    Facade *facade;
};

#endif // CONTROLLER_H
