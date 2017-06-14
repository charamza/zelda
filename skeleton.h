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

};

#endif // SKELETON_H
