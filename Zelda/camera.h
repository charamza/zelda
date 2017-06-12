#ifndef CAMERA_H
#define CAMERA_H

#include <QPointF>
#include "entity.h"

class Game;

class Camera
{
public:
    Camera(Game *game);

    Game *game;
    QPointF pos;
    QPointF mouse;
    bool clickLeft = false, clickRight = false, pointingOnEntity = false;
    int mouseTileX = 0, mouseTileY = 0;

    void update(Entity *entity);
    QPointF getPosition();
    void setPosition(float x, float y);
    void setPosition(QPointF position);
    void move(float x, float y);
    void move(QPointF move);
    void checkBorders();
};

#endif // CAMERA_H
