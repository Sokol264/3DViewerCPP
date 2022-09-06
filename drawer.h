#ifndef DRAWER_H
#define DRAWER_H

#include <QOpenGLWidget>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>
#include <QMouseEvent>
#include <QWheelEvent>

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
    void wheelEvent(QWheelEvent *event);
    void setFigure(Figure figure);

protected:
    void initShaders();
    Figure figure;

private:
    QMatrix4x4 projectionMatrix;
    QOpenGLShaderProgram program;
    QVector2D mousePosition;
    QQuaternion rotation;
    double scale = 1;
};

#endif // DRAWER_H
