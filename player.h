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
    void attack();
    void damaged(int damage);
    void pickup();
    int swing = 0;
    int health;
    int dmg;
    int direction = 0;
    int coins;


};

#endif // PLAYER_H
