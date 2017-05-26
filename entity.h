#ifndef ENTITY_H
#define ENTITY_H

#include <QPainter>

class Entity
{
public:
    Entity(int x, int y, int width, int height);

    virtual void update();
    virtual void draw();

    void updateMove();

    float x, y;
    int width, height;
    float speed;
    int dx = 0, dy = 0; // DX -1 = Levo, DX 1 = Pravo, DY -1 = nahoru, DY 1 = dolu
};

#endif // ENTITY_H
