#include "entity.h"

Entity::Entity(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->speed = 1;
}

void Entity::updateMove()
{
    // TODO: Dodělat logiku základního pohybu
}
