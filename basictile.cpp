#include "basictile.h"

BasicTile::BasicTile(Game *game, int x, int y, int id) : Tile(game, x, y, id)
{
    this->game = game;
    this->x = x;
    this->y = y;
    this->id = id;
}
