#include "view.h"
#include <QOpenGLWidget>
#include <QApplication>

View::View(QGraphicsScene *scene)
{
    setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //this->setViewport(new QOpenGLWidget(this));
    setMouseTracking(true);

    game = new Game(this);
    game->load();

    timerUpdate = new QTimer(this);
    connect(timerUpdate, SIGNAL(timeout()), this, SLOT(update()));
    timerUpdate->start(16);
}

void View::update()
{
    game->update();

    this->scene()->update(QRectF(0, 0, game->WIDTH, game->HEIGHT));
}

void View::mousePressEvent(QMouseEvent *event)
{

}

void View::mouseReleaseEvent(QMouseEvent *event)
{

}

void View::mouseMoveEvent(QMouseEvent *event){

}

void View::keyPressEvent(QKeyEvent *event)
{

}

void View::keyReleaseEvent(QKeyEvent *event)
{

}
