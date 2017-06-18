#include "slime.h"
#include "game.h"

Slime::Slime(Game *game, int x, int y) : Entity(game, x, y, 32, 32)
{
    speed = 1;
}

void Slime::draw(QPainter *gl)
{
    gl->drawImage(boundingRect(), game->resource->objects, QRect(16*(game->STEPS/15%2), 0, 16, 16));
}

void Slime::update()
{
    // Ukázkovej pohyb
    if(game->STEPS/300%2==0) setDX(1); else setDX(-1);
    // Důležité pro pohyb (každý druh pohybu by měl mít vlastní funkci v entitě)
    updateMove();
}
