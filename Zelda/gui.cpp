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
    for (int i = 0; i < 5; ++i) {
        painter->drawImage(QRect(i*30, 10, 32, 32), game->resource->objects, QRect(64, 2, 14, 13));
    }

}
