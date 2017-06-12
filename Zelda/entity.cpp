#include "entity.h"
#include "game.h"

Entity::Entity(Game *game, int x, int y, int width, int height)
{
    this->game = game;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->speed = 1;
}

void Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->translate(QPointF(x - game->camera->pos.rx(), y - game->camera->pos.ry()));
    this->draw(painter);
    painter->restore();
}

QRectF Entity::boundingRect() const
{
    return QRectF(0, 0, width, height);
}

QRectF Entity::collisionRect() const
{
    return QRectF(x, y, width, height);
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
    this->y += dy*speed;
}

