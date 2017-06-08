#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Game;

class Player : public Entity
{
public:
    Player(Game *game, int x, int y);
    void draw(QPainter *gl);
    void update();
};

#endif // PLAYER_H
