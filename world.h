#ifndef WORLD_H
#define WORLD_H

#include <QPainter>
#include <QGraphicsItem>
#include "entity.h"
#include "tile.h"

class Game;

class World : public QGraphicsItem
{
public:
    World(Game *game);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void load();
    void update();

    int WIDTH, HEIGHT;
    int LAYERS;
    QImage spritesheet;
    Tile**** world;
    QList<Entity*> *entities;
    Game *game;
};

#endif // WORLD_H
