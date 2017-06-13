#include "player.h"
#include "game.h"

Player::Player(Game *game, int x, int y) : Entity(game, x, y, 32, 48)
{
    speed = 2;
}

void Player::draw(QPainter *gl)
{

    QRect texture;
    QRectF bounds = boundingRect();
    if(dx == 0 && dy==0){
        texture = QRect(16*(game->STEPS/15%1), 6, 16, 24);
    }
    if(dy == 1 || (dy == 0 && ldy == 1)){
        texture = QRect(16*(game->STEPS/15%(dy == 0 ? 1 : 4)), 6, 16, 24);
    }
    if(dy == -1 || (dy == 0 && ldy == -1)){
        texture = QRect(16*(game->STEPS/15%(dy == 0 ? 1 : 4)), 69, 16, 24);
    }
    if(dx == 1 || (dx == 0 && ldx == 1)){
        texture = QRect(16*(game->STEPS/15%(dx == 0 ? 1 : 4)), 38, 16, 24);
    }
    if(dx == -1|| (dx == 0 && ldx == -1)){
        texture = QRect(16*(game->STEPS/15%(dx == 0 ? 1 : 4)), 102, 16, 24);
    }
    if((swing > 0 && dy == 0 && dx == 0 && ldx == 0 && ldy == 0) || (swing > 0 && (dy == 1 || ldy == 1))){
        bounds=QRectF(-16,-2, 64,52);
        texture = QRect(31*(3 - (swing/8%4)), 134, 32, 26);
    }
    if(swing > 0 && (dy == -1 || ldy == -1)){
        bounds=QRectF(-16,-2, 64,52);
        texture = QRect(31*(3 - (swing/8%4)), 166, 32, 26);
    }
    if(swing > 0 && (dx == 1 || ldx == 1)){
        bounds=QRectF(-16,-2, 64,52);
        texture = QRect(31*(3 - (swing/8%4)), 199, 32, 26);
    }
    if(swing > 0 && (dx == -1 || ldx == -1)){
        bounds=QRectF(-16,-2, 64,52);
        texture = QRect(31*(3 - (swing/8%4)), 230, 32, 26);
    }
    gl->drawImage(bounds, game->resource->player, texture);
}

void Player::update()
{
    if(swing > 0)
        swing--;
    // Důležité pro pohyb (každý druh pohybu by měl mít vlastní funkci v entitě)
    updateMove();
}

void Player::attack()
{
    swing = 32;
}
