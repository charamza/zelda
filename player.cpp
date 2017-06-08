#include "player.h"
#include "game.h"

Player::Player(Game *game, int x, int y) : Entity(game, x, y, 32, 48)
{
    speed = 2;
}

void Player::draw(QPainter *gl)
{
    gl->drawImage(boundingRect(), game->resource->player, QRect(16*(game->STEPS/15%4), 6, 16, 24));
}

void Player::update()
{
    // Důležité pro pohyb (každý druh pohybu by měl mít vlastní funkci v entitě)
    updateMove();
}
