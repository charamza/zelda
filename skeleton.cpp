#include "skeleton.h"
#include "game.h"
#include <QDebug>

Skeleton::Skeleton(Game *game, int x, int y) : Entity(game,x,y,32,32)
{

}

void Skeleton::draw(QPainter *gl)
{
    /*QRect texture = QRect(64, 64, 32, 32);
    if(dx == -1) texture = QRect(0, 0, 32, 32);
    if(dx == 1) texture = QRect(32, 32, 32, 32);
    gl->drawImage(boundingRect(),game->resource->objects, texture);*/
    gl->drawRect(boundingRect());
}

void Skeleton::update()
{
    if(playerWithinRange(100)){
        chasePlayer(1);
    }
    else{
        setDY(0);
        int dx = (game->STEPS/40%4-1)%2;
        setDX(dx);
    }
    updateMove();
}
