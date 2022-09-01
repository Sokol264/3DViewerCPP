#include "command.h"


void ReadObjectFileCommand::Execute() {
    controller->ReadObjectModelFromFile(filename);
}

void ReadTextureFileCommand::Execute()
{
    controller->ReadTextureFromFile(filename);
}
