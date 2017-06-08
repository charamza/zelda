#ifndef SLIME_H
#define SLIME_H

#include "entity.h"
#include "game.h"

class Game;

class Slime : public Entity
{
public:
    Slime(Game *game, int x, int y);

    void draw(QPainter *gl);
    void update();

};

#endif // SLIME_H
