#include "entity.h"
#include "game.h"

Entity::Entity(Game *game, int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->speed = 1;
}

void Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    this->draw(painter);
}

QRectF Entity::boundingRect() const
{
    return QRectF(0, 0, Tile::SIZE*WIDTH, Tile::SIZE*HEIGHT);
}

QPainterPath Entity::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Entity::updateMove()
{
    // TODO: Dodělat logiku základního pohybu
    this->x += dx*speed;
    this->y += dx*speed;
}

