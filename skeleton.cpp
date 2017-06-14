#include "skeleton.h"
#include "game.h"

Skeleton::Skeleton(Game *game, int x, int y) : Entity(game,x,y,32,32)
{

}

void Skeleton::draw(QPainter *gl)
{
    QRect texture = QRect(64, 64, 32, 32);
    if(dx == -1) texture = QRect(0, 0, 32, 32);
    if(dx == 1) texture = QRect(32, 32, 32, 32);
    gl->drawImage(boundingRect(),game->resource->objects, texture);
}

void Skeleton::update()
{
    updateMove();
}
