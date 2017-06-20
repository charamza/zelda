#include "coin.h"
#include "game.h"
#include <QDebug>

Coin::Coin(Game *game, int x, int y) : Entity(game,x,y,32,32)
{

}


void Coin::draw(QPainter *gl)
{

    QRect texture;
    QRectF bounds = boundingRect();
    //painter->drawImage(QRect(15, 1030, 32, 32), game->resource->objects, QRect((game->STEPS/16%4)*15, 64, 15, 15));
    texture = QRect((game->STEPS/16%4)*15, 64, 15, 15);


    gl->drawImage(bounds, game->resource->objects, texture);
}

void Coin::update()
{
    setDX(dx);
    updateMove();
}
