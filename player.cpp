#include "player.h"
#include "game.h"
#include "aabb.h"
#include <QDebug>
#include <QPainter>

Player::Player(Game *game, int x, int y) : Entity(game, x, y, 32, 48)
{
    speed = 2;
    health = 1;
    dmg = 20;
}

void Player::draw(QPainter *gl)
{
    if(health > 0){
        QRect texture;
        QRectF bounds = boundingRect();
        if(dx == 0 && dy==0){
            texture = QRect(16*(game->STEPS/15%1), 6, 16, 24);
        }
        if(dy == 1 || (dy == 0 && ldy == 1)){
            direction = 0;
            texture = QRect(16*(game->STEPS/15%(dy == 0 ? 1 : 4)), 6, 16, 24);
        }
        if(dy == -1 || (dy == 0 && ldy == -1)){
            direction = 2;
            texture = QRect(16*(game->STEPS/15%(dy == 0 ? 1 : 4)), 69, 16, 24);
        }
        if(dx == 1 || (dx == 0 && ldx == 1)){
            direction = 3;
            texture = QRect(16*(game->STEPS/15%(dx == 0 ? 1 : 4)), 38, 16, 24);
        }
        if(dx == -1|| (dx == 0 && ldx == -1)){
            direction = 1;
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
    QRect swingBox;

    if(direction == 0) swingBox = QRect((int)x, (int)(y+height/2), width, height);
    if(direction == 2) swingBox = QRect((int)x, (int)(y-height/2), width, height);
    if(direction == 3) swingBox = QRect((int)(x+width/2), (int)(y), width, height);
    if(direction == 1) swingBox = QRect((int)(x-width/2), (int)(y), width, height);

    for(int i = 0; i < game->world->entities->count(); i++){
        Entity *entity = game->world->entities->at(i);
        AABB collision(swingBox, entity->collisionRect());
        if(collision.collide){
            entity->damaged(dmg);
        }
    }
}

void Player::damaged(int damage)
{
    health-=damage;
}

void Player::died()
{

}
