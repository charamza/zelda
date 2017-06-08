#include "camera.h"
#include "game.h"
#include "tile.h"
#include "world.h"

Camera::Camera(Game *game)
{
    this->game = game;
    this->pos = QPointF(0, 0);
}

void Camera::update(Entity *entity){
    float x = entity->x - (game->WIDTH - entity->width) / 2;
    float y = entity->y - (game->HEIGHT - entity->height) / 2;
    setPosition(x, y);
    this->checkBorders();
}

QPointF Camera::getPosition()
{
    return this->pos;
}

void Camera::setPosition(float x, float y)
{
    this->pos = QPointF(x, y);
    this->checkBorders();
}

void Camera::setPosition(QPointF position)
{
    this->pos = position;
    this->checkBorders();
}

void Camera::move(float x, float y)
{
    this->pos += QPointF(x, y);
    this->checkBorders();
}

void Camera::move(QPointF move)
{
    this->pos += move;
    this->checkBorders();
}

void Camera::checkBorders()
{
    int left = this->game->world->WIDTH * Tile::SIZE - game->WIDTH;
    int top = this->game->world->HEIGHT * Tile::SIZE - game->HEIGHT;

    if(pos.rx() < 0) pos.setX(0);
    if(pos.ry() < 0) pos.setY(0);
    if(pos.rx() > left) pos.setX(left);
    if(pos.ry() > top) pos.setY(top);
}
