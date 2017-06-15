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

    void setDX(int dx);
    void setDY(int dy);
    void damaged(int damage);

    void updateMove();

    float x, y;
    int width, height;
    float speed;
    int health;
    int dx = 0, dy = 0; // DX -1 = Levo, DX 1 = Pravo, DY -1 = nahoru, DY 1 = dolu
    int adx = 0, ady = 0; // Určuje dx a dy i po tom, co už nejsou nastavené, aby entita doběhla po mřížce
    int atx = 0, aty = 0; // Určuje, kam má po mřížce doběhnout a tam se pak i zastaví
    int ldx = 0, ldy = 0; // Poslední dx, dy podle směru

protected:
	Game *game;
};

#endif // ENTITY_H
