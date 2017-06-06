#ifndef ENTITY_H
#define ENTITY_H

#include <QPainter>
#include <QGraphicsItem>

class Game;

class Entity : public QGraphicsItem
{
public:
    Entity(Game *game, int x, int y, int width, int height);
    QRectF boundingRect() const;
    QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void update() const = 0;
    virtual void draw(QPainter *gl) const = 0;

    void updateMove();

    float x, y;
    int width, height;
    float speed;
    int dx = 0, dy = 0; // DX -1 = Levo, DX 1 = Pravo, DY -1 = nahoru, DY 1 = dolu
	
private:
	Game *game;
};

#endif // ENTITY_H
