#include "player.h"
#include "game.h"

Player::Player(Game *game, int x, int y) : Entity(game, x, y, 32, 48)
{
    speed = 2;
}

void Player::draw(QPainter *gl)
{

    QRect texture;
    if(dy == 1){
        texture = QRect(16*(game->STEPS/15%4), 6, 16, 24);
    }
    if(dy == -1){
        texture = QRect(16*(game->STEPS/15%4), 69, 16, 24);
    }
    if(dx == 1){
        texture = QRect(16*(game->STEPS/15%4), 38, 16, 22);
    }
    if(dx == -1){
        texture = QRect(16*(game->STEPS/15%4), 102, 16, 22);
    }
    if(dx == 0 && dy==0){
        texture = QRect(16*(game->STEPS/15%1), 6, 16, 24);
    }
    gl->drawImage(boundingRect(), game->resource->player, texture);
}

void Player::update()
{
    // Důležité pro pohyb (každý druh pohybu by měl mít vlastní funkci v entitě)
    updateMove();
}
