#include "filemanager.h"

FileManager::FileManager() {}

void FileManager::ReadModel(std::string filename) {
    std::setlocale(LC_ALL, "en_US.UTF-8");
    std::ifstream input(filename);
    if (!input) {
        throw std::invalid_argument("There is no such file");
    }

    for (std::string line; std::getline(input, line);) {
        if (!line.empty()) {
            if (!line.compare(0, 2, "v ")) {
                ReadPoint3DFromString(position, line);
            } else if (!line.compare(0, 3, "vt ")) {
                ReadPoint2DFromString(textures, line);
            } else if (!line.compare(0, 3, "vn ")) {
                ReadPoint3DFromString(normals, line);
            } else if (!line.compare(0, 2, "f ")) {
                face = QVector<VertexData>();
                ReadFacesFromString(line);
                TurnPolygonsIntoTriangles(face);
            }
        }
    }
    position.clear();
    normals.clear();
    textures.clear();
}

void FileManager::ReadPoint3DFromString(QVector<QVector3D> &vector, std::string line) {
    size_t positionNextNumber = 2, count = 0;
    QVector3D point;
    point.setX(std::stof(line.substr(positionNextNumber), &count));
    positionNextNumber += count;
    point.setY(std::stof(line.substr(positionNextNumber), &count));
    positionNextNumber += count;
    point.setZ(std::stof(line.substr(positionNextNumber)));
    vector.push_back(point);
}

void FileManager::ReadPoint2DFromString(QVector<QVector2D> &vector, std::string line) {
    QVector2D point;
    size_t count = 0, positionNextNumber = 2;
    point.setX(std::stof(line.substr(positionNextNumber), &count));
    positionNextNumber += count;
    point.setY(std::stof(line.substr(positionNextNumber), &count));
    vector.push_back(point);
}

void FileManager::ReadFacesFromString(std::string line) {
    int queue = 1;
    QVector3D vert(0,0,0), norm(0,0,0);
    QVector2D text(0,0);

    for (size_t i = 2; i < line.size(); ++i) {
        if (line[i] == ' ') {
            if (queue > 1) face.push_back(VertexData(vert, text, norm));
            queue = 1;
        } else if (line[i] != '/') {
            if (std::isdigit(line[i]) && queue == 1) {
                ReadAndCopyPointByIndex(vert, position, line, i);
            } else if (std::isdigit(line[i]) && queue == 2) {
                ReadAndCopyPointByIndex(text, textures, line, i);
            } else if (std::isdigit(line[i]) && queue == 3) {
                ReadAndCopyPointByIndex(norm, normals, line, i);
            }
            queue += 1;
        }
    }
    face.push_back(VertexData(vert, text, norm));
}

template <typename T>
void FileManager::ReadAndCopyPointByIndex(T &point, QVector<T> vector, std::string line, size_t &iterator) {
    size_t count = 0;
    int index = std::stoi(line.substr(iterator), &count);
    point = vector[index - 1];
    iterator += count - 1;
}

void FileManager::TurnPolygonsIntoTriangles(QVector<VertexData> face) {
    for (int i = 0; i < face.size() - 2; ++i) {
        vertices.push_back(face[i]);
        vertices.push_back(face[i + 1]);
        vertices.push_back(face[face.size() - 1]);
    }
}

QVector<VertexData> FileManager::GetVertices() {
    return vertices;
}
