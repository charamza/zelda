#include "watertile.h"
#include "game.h"
#include <QDebug>

WaterTile::WaterTile(Game *game, int x, int y, int type) : Tile(game, x, y, 1) {
    this->game = game;
    this->x = x;
    this->y = y;

    switch(type){
        case 1:
            texPos = 40;
            texRange = QPoint(4, 2);
            break;
        case 2:
            texPos = 123;
            texRange = QPoint(3, 2);
            break;
        default:
            texPos = 40;
            texRange = QPoint(4, 2);
            break;
    }
}

int WaterTile::getID()
{
    int index = (game->STEPS+x)/20%(texRange.rx()*texRange.ry());
    int id = index%texRange.rx()+index/texRange.rx()*40+texPos;
    return id;
}

