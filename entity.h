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
    QRectF collisionRect() const;
    QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    virtual void update() { return; };
    virtual void draw(QPainter *gl) { return; };

    void updateMove();

    float x, y;
    int width, height;
    float speed;
    int dx = 0, dy = 0; // DX -1 = Levo, DX 1 = Pravo, DY -1 = nahoru, DY 1 = dolu
	
protected:
	Game *game;
};

#endif // ENTITY_H
