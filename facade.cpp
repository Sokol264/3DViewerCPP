#include "facade.h"

Facade::Facade() : drawer(nullptr) {}

void Facade::SetDrawer(Drawer *drawer) {
    this->drawer = drawer;
}

void Facade::ReadObjectModelFromFile(std::string filename) {
    fileManager.ReadModel(filename);
    auto vertices = fileManager.GetVertices();
    figure.setVertices(vertices);
    drawer->setFigure(figure);
}

void Facade::ReadTextureFromFile(std::string filename) {
    figure.setTexturePath(filename);
    figure.ConfigTexture();
    drawer->setFigure(figure);
}
