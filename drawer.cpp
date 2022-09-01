#include "drawer.h"
#include "filemanager.h"
#include <iostream>
Drawer::Drawer(QWidget* parent) : QOpenGLWidget(parent) {}

void Drawer::initializeGL() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    initShaders();
}

void Drawer::resizeGL(int w, int h) {
    float aspect = w / (float)h;
    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(45, aspect, 0.1f, 10.0f);
}

void Drawer::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 viewMatrix;
    viewMatrix.setToIdentity();
    viewMatrix.translate(0.0, -1.0, -5.0);
    viewMatrix.rotate(rotation);
    viewMatrix.scale(2);

    auto texture = figure.getTexture();
    if (texture)
        texture->bind(0);

    program.bind();
    program.setUniformValue("u_projection_matrix", projectionMatrix);
    program.setUniformValue("u_view_matrix", viewMatrix);
    program.setUniformValue("u_model_matrix", figure.getModelMatrix());
    program.setUniformValue("u_texture", 0);
    program.setUniformValue("u_lightPosition", QVector4D(0.0, 0.0, 0.0, 1.0));
    program.setUniformValue("u_lightPower", 5.0f);

    int offset = 0;

    auto arrayBuffer = figure.getBuffer();
    arrayBuffer.bind();

    int vertexLocation = program.attributeLocation("a_position");
    program.enableAttributeArray(vertexLocation);
    program.setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    offset += sizeof(QVector3D);

    int textureLocation = program.attributeLocation("a_textcoord");
    program.enableAttributeArray(textureLocation);
    program.setAttributeBuffer(textureLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

    offset += sizeof(QVector2D);

    int normalLocation = program.attributeLocation("a_normal");
    program.enableAttributeArray(normalLocation);
    program.setAttributeBuffer(normalLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    glDrawArrays(GL_TRIANGLES, 0, figure.getVertices().size());
}

void Drawer::mousePressEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
        mousePosition = QVector2D(event->position());
    }
    event->accept();
}

void Drawer::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() != Qt::LeftButton) return;
    QVector2D diff = QVector2D(event->position()) - mousePosition;
    QVector3D axis = QVector3D(diff.y(), diff.x(), 0);

    float angle = diff.length() / 2.0;
    rotation = QQuaternion::fromAxisAndAngle(axis, angle) * rotation;

    mousePosition = QVector2D(event->position());
    update();
}

void Drawer::setFigure(Figure figure) {
    auto vert = figure.getVertices();
    figure.ConfigBuffer();
    this->figure = figure;
    update();
}

void Drawer::initShaders() {
    QOpenGLShader* vertex = new QOpenGLShader(QOpenGLShader::Vertex);
    vertex->compileSourceFile(":/vshader.vsh");
    QOpenGLShader* fragment = new QOpenGLShader(QOpenGLShader::Fragment);
    fragment->compileSourceFile(":/fshader.fsh");
    program.addShader(vertex);
    program.addShader(fragment);
    if (!program.link())
        close();
}
