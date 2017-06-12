#ifndef TILE_H
#define TILE_H

#include <QRect>

class Game;

class Tile
{
public:
    Tile(Game *game, int x, int y, int id);

    virtual void update() { return; };
    QRect getTexCoords();
    QRect getBounds();
    int getRX();
    int getRY();
    virtual int getID() { return id; };

    Game *game;
    int id;
    int x, y;
    const static int SIZE = 32;
};

#endif // TILE_H
