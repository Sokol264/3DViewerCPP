#ifndef VERTEX_H
#define VERTEX_H

#include <QVector3D>
#include <QVector2D>

struct VertexData {
    VertexData() {}
    VertexData(QVector3D p, QVector2D t, QVector3D n) :
        position(p), textCoord(t), normals(n) {}

    QVector3D position;
    QVector2D textCoord;
    QVector3D normals;
};

#endif // VERTEX_H
