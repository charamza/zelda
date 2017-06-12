#ifndef BASICTILE_H
#define BASICTILE_H

#include "tile.h"

class Game;

class BasicTile : public Tile
{
public:
    BasicTile(Game *game, int x, int y, int id);
};

#endif // BASICTILE_H
