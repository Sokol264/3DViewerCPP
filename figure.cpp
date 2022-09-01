#include "figure.h"

void Figure::setVertices(QVector<VertexData> vertices) {
    this->vertices = vertices;
    modelMatrix.setToIdentity();
}

void Figure::setTexturePath(std::string filepath) {
    texturePath = filepath;
}

void Figure::ConfigTexture() {
    texture = new QOpenGLTexture(QImage(texturePath.c_str()).mirrored());
    texture->setMagnificationFilter(QOpenGLTexture::Nearest);
    texture->setMagnificationFilter(QOpenGLTexture::Linear);
    texture->setWrapMode(QOpenGLTexture::Repeat);
}

QVector<VertexData> Figure::getVertices() {
    return vertices;
}

QOpenGLTexture *Figure::getTexture() {
    return texture;
}

QOpenGLBuffer Figure::getBuffer() {
    return arrayBuffer;
}

QMatrix4x4 Figure::getModelMatrix() {
    return modelMatrix;
}

void Figure::ConfigBuffer() {
    arrayBuffer.create();
    arrayBuffer.bind();
    arrayBuffer.allocate(this->vertices.constData(), this->vertices.size() * sizeof(VertexData));
    arrayBuffer.release();
}


