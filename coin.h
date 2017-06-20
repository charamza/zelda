#ifndef COIN_H
#define COIN_H

#include "entity.h"

class Game;

class Coin : public Entity
{
public:
    Coin(Game *game, int x, int y);
    void draw(QPainter *gl);
    void update();
};

#endif // COIN_H







