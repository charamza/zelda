#ifndef SKELETON_H
#define SKELETON_H

#include "entity.h"

class Game;

class Skeleton : public Entity
{
public:
    Skeleton(Game *game, int x, int y);

    void draw(QPainter *gl);
    void update();

    int drawAttack = 0;
    int attackDelay = 0;
};

#endif // SKELETON_H
