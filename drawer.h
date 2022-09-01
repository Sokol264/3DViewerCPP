#ifndef DRAWER_H
#define DRAWER_H

#include <QOpenGLWidget>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>
#include <QMouseEvent>

#include "vertex.h"
#include "figure.h"

class Drawer : public QOpenGLWidget
{
public:
    Drawer() {}
    Drawer(QWidget* parent);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void setFigure(Figure figure);

protected:
    void initShaders();
    Figure figure;

private:
    QMatrix4x4 projectionMatrix;
    QOpenGLShaderProgram program;
    QVector2D mousePosition;
    QQuaternion rotation;
};

#endif // DRAWER_H
