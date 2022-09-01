#include "controller.h"

Controller::Controller(Facade *facade) : facade(facade) {}

void Controller::SetDrawer(Drawer *drawer) {
    facade->SetDrawer(drawer);
}

void Controller::ReadObjectModelFromFile(std::string filename) {
    facade->ReadObjectModelFromFile(filename);
}

void Controller::ReadTextureFromFile(std::string filename)
{
    facade->ReadTextureFromFile(filename);
}

