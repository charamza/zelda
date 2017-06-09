#include "entity.h"
#include "game.h"
#include "tile.h"

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

void Entity::setDX(int dx)
{
    this->dx = dx;
    if(dx != 0) this->adx = dx;
}

void Entity::setDY(int dy)
{
    this->dy = dy;
    if(dy != 0) this->ady = dy;
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

    int GRIDSIZE = Tile::SIZE / 2;
    if(dx != 0 && adx != 0){
        atx = x / GRIDSIZE + (dx == 1 ? 1 : 0);
    }
    if(dy != 0 && ady != 0){
        aty = y / GRIDSIZE + (dy == 1 ? 1 : 0);
    }
    if(dx == 0 && adx != 0){
        if(atx >= x / GRIDSIZE && adx == -1) adx = 0;
        if(atx <= x / GRIDSIZE && adx == 1) adx = 0;
        if(adx == 0) x = atx * GRIDSIZE;
        else x += adx * speed;

    }
    if(dy == 0 && ady != 0){
        if(aty >= y / GRIDSIZE && ady == -1) ady = 0;
        if(aty <= y / GRIDSIZE && ady == 1) ady = 0;
        if(ady == 0) y = aty * GRIDSIZE;
        else y += ady * speed;
    }
}

