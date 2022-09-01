#ifndef FIGURE_H
#define FIGURE_H

#include <QOpenGLTexture>
#include <QOpenGLBuffer>
#include <QVector>
#include <QMatrix4x4>
#include "vertex.h"

class Figure
{
public:
    Figure() : texture(nullptr) { modelMatrix.setToIdentity(); }
    Figure(QVector<VertexData> vertices) : texture(nullptr), vertices(vertices) {
      modelMatrix.setToIdentity();
    }
    void setVertices(QVector<VertexData> vertices);
    void setTexturePath(std::string filepath);
    void ConfigBuffer();
    void ConfigTexture();

    QVector<VertexData> getVertices();
    QOpenGLTexture *getTexture();
    QOpenGLBuffer getBuffer();
    QMatrix4x4 getModelMatrix();
private:
    QMatrix4x4 modelMatrix;

    std::string texturePath;
    QOpenGLTexture *texture;
    QOpenGLBuffer arrayBuffer;
    QVector<VertexData> vertices;
};

#endif // FIGURE_H
