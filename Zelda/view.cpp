#include "view.h"
#include <QOpenGLWidget>
#include <QApplication>

View::View(QGraphicsScene *scene)
{
    setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setViewport(new QOpenGLWidget(this));
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
    game->camera->move(dx * 4, dy * 4);

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
    if(event->key() == Qt::Key_Escape) exit(0);
    if(event->key() == Qt::Key_Left) dx = -1;
    if(event->key() == Qt::Key_Right) dx = 1;
    if(event->key() == Qt::Key_Up) dy = -1;
    if(event->key() == Qt::Key_Down) dy = 1;
}

void View::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left && dx == -1) dx = 0;
    if(event->key() == Qt::Key_Right && dx == 1) dx = 0;
    if(event->key() == Qt::Key_Up && dy == -1) dy = 0;
    if(event->key() == Qt::Key_Down && dy == 1) dy = 0;
}
