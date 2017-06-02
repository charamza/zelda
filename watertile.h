#ifndef WATERTILE_H
#define WATERTILE_H

#include "tile.h"

class Game;

class WaterTile : public Tile
{
public:
    WaterTile(Game *game, int x, int y, int type);

    int getID();

private:
    int texPos;
    QPoint texRange;
};

#endif // WATERTILE_H
