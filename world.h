#ifndef WORLD_H
#define WORLD_H

#include <QPainter>
#include <QGraphicsItem>
#include "entity.h"
#include "tile.h"
#include "aabb.h"
#include "worldloader.h"

class Game;

class World : public QGraphicsItem
{
public:
    World(Game *game);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void update();
    AABB collision(QRectF rect);

    void addEntity(Entity *entity);

    int WIDTH, HEIGHT;
    int LAYERS;
    QImage spritesheet;
    Tile**** world;
    QList<Entity*> *entities;

    WorldLoader *loader;
    Game *game;
};

#endif // WORLD_H
