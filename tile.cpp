#include "tile.h"
#include "game.h"

Tile::Tile(Game *game, int x, int y, int id)
{
    this->game = game;
    this->x = x;
    this->y = y;
    this->id = id;
    this->solid = game->world->solidTiles->contains(id);
}

QRect Tile::getTexCoords()
{
    int SWIDTH = 40; // Počet řádků na spritesheetu
    int TEXTURE_SIZE = 16; // Velikost textury
    int x1 = (getID()%SWIDTH)*TEXTURE_SIZE;
    int y1 = (int)(getID()/SWIDTH)*TEXTURE_SIZE;
    int x2 = TEXTURE_SIZE;
    int y2 = TEXTURE_SIZE;

    return QRect(x1, y1, x2, y2);
}

QRect Tile::drawingRect()
{
    return QRect(getRX(), getRY(), SIZE, SIZE);
}

QRect Tile::boundingRect()
{
    return QRect(x * SIZE, y * SIZE, SIZE, SIZE);
}

int Tile::getRX()
{
    return x * SIZE - game->camera->pos.rx();
}

int Tile::getRY()
{
    return y * SIZE - game->camera->pos.ry();
}
