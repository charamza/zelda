#include "gui.h"
#include "game.h"

#include <QPainter>
#include <QPainterPath>

class Game;

Gui::Gui(Game *game)
{
    this->game = game;
}

QRectF Gui::boundingRect() const
{
    return QRectF(0, 0, 10, 10);
}

QPainterPath Gui::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Gui::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(game->player->health > 0){
        for (int i = 0; i < game->player->health; ++i) {
            painter->drawImage(QRect(20+i*40, 30, 32, 32), game->resource->objects, QRect(64, 2, 14, 13));
        }
    }

    painter->drawImage(QRect(15, 1030, 32, 32), game->resource->objects, QRect((game->STEPS/16%4)*15, 64, 15, 15));
}
