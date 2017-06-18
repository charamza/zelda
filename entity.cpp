#include "entity.h"
#include "game.h"
#include "tile.h"
#include <QDebug>
#include <math.h>

Entity::Entity(Game *game, int x, int y, int width, int height)
{
    this->game = game;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->speed = 1;
    this->health = 20;
}

void Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->translate(QPointF(-game->camera->pos.rx(), -game->camera->pos.ry()));
    painter->translate(QPointF(x, y));
    this->draw(painter);
    painter->translate(QPointF(-x, -y));
    if(game->DEBUG) painter->drawRect(collisionRect());
    painter->restore();
}

void Entity::setDX(int dx)
{
    this->dx = dx;
    if(dx != 0) this->adx = dx;
    if(dx != 0){this->ldx = dx; this->ldy = 0;}
}

void Entity::setDY(int dy)
{
    this->dy = dy;
    if(dy != 0) this->ady = dy;
    if(dy != 0){this->ldy = dy; this->ldx = 0;}
}

void Entity::damaged(int damage)
{
    health-=damage;
    if(health <=0){
        for(int i = 0; i < game->world->entities->count(); i++){
            Entity *entity = game->world->entities->at(i);
            if(entity == this){
                game->world->entities->removeAt(i);
                game->world->scene()->removeItem(entity);
            }
        }
    }
}

QRectF Entity::boundingRect() const
{
    return QRectF(0, 0, width, height);
}

QRectF Entity::collisionRect()
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
    int rdx = dx;
    int rdy = dy;

    if(adx == 0) adx = dx;
    if(ady == 0) ady = dy;

    int GRIDSIZE = Tile::SIZE / 2;

    if(dx != 0 && adx != 0){
        QRectF xBoxX;
        if(dx == -1){
            xBoxX = QRectF(collisionRect().x() - 2, collisionRect().y(), 2, collisionRect().height());
        }else if(dx == 1){
            xBoxX = QRectF(collisionRect().x() + collisionRect().width(), collisionRect().y(), 2, collisionRect().height());
        }
        AABB aabb = game->world->collision(xBoxX);
        if(!aabb.collide) atx = x / GRIDSIZE + (adx == 1 ? 1 : 0);
        else adx = 0;
    }
    if(dy != 0 && ady != 0){
        QRectF xXxBoxXxX;
        if(dy == -1){
            xXxBoxXxX = QRectF(collisionRect().x(), collisionRect().y() - 2, collisionRect().width(), 2);
        }else if(dy == 1){
            xXxBoxXxX = QRectF(collisionRect().x(), collisionRect().y() + collisionRect().height(), collisionRect().width(), 2);
        }
        AABB aabb = game->world->collision(xXxBoxXxX);
        if(!aabb.collide) aty = y / GRIDSIZE + (ady == 1 ? 1 : 0);
        else ady = 0;
    }

    if(adx != 0){
        if(atx > x / GRIDSIZE && adx == -1) adx = 0;
        if(atx < x / GRIDSIZE && adx == 1) adx = 0;
        if(adx == 0) x = atx * GRIDSIZE;
        else rdx = adx;
    }
    if(dy == 0 && ady != 0){
        if(aty > y / GRIDSIZE && ady == -1) ady = 0;
        if(aty < y / GRIDSIZE && ady == 1) ady = 0;
        if(ady == 0) y = aty * GRIDSIZE;
        else rdy = ady;
    }

    float moveX = adx * speed;
    float moveY = ady * speed;

    x += moveX;
    y += moveY;
}

bool Entity::playerWithinRange(float range)
{
    return (hypotf(abs(game->player->x - this->x),abs(game->player->y - this->y)) <= range);
}

void Entity::chasePlayer(float distance)
{
    if(!this->playerWithinRange(distance)){
        setDX((game->player->x - this->x)/abs(game->player->x - this->x));
        setDY((game->player->y - this->y)/abs(game->player->y - this->y));
    }
}
