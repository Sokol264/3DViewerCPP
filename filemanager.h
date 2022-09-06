#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "vertex.h"
#include <QVector>
#include <fstream>
#include <clocale>

class FileManager
{
public:
    FileManager();
    void ReadModel(std::string filename);
    QVector<VertexData> GetVertices();
private:
    void ReadPoint3DFromString(QVector<QVector3D> &vector, std::string &line);
    void ReadPoint2DFromString(QVector<QVector2D> &vector, std::string &line);

    template <typename T>
    void ReadAndCopyPointByIndex(T &point, QVector<T> &vector, std::string &line, size_t &iterator);
    void TurnPolygonsIntoTriangles(QVector<VertexData> &face);
    void ReadFacesFromString(std::string &line);
    void ClearTempVertexData();
    void ReadFacesFromString(std::string &line, int queue, size_t index);

    QVector<VertexData> vertices;

    QVector<QVector3D> position;
    QVector<QVector2D> textures;
    QVector<QVector3D> normals;

    QVector<VertexData> face;
};

#endif // FILEMANAGER_H
