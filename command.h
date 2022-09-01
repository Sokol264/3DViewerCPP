#ifndef COMMAND_H
#define COMMAND_H

#include "Controller/controller.h"

class Command
{
public:
//    virtual ~Command();
    virtual void Execute() = 0;
protected:
    explicit Command(Controller *controller) : controller(controller) {}
    Controller *controller;
};

class ReadObjectFileCommand : public Command {
public:
    ReadObjectFileCommand(Controller *controller) : Command(controller) {}
    void Execute();
    void SetFilename(std::string filename) { this->filename = filename; }

private:
    std::string filename;
};


class ReadTextureFileCommand : public Command {
public:
    ReadTextureFileCommand(Controller *controller) : Command(controller) {}
    void Execute();
    void SetFilename(std::string filename) { this->filename = filename; }

private:
    std::string filename;
};



#endif // COMMAND_H
