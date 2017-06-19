#include "skeleton.h"
#include "game.h"
#include <QDebug>

Skeleton::Skeleton(Game *game, int x, int y) : Entity(game,x,y,32,32)
{

}

void Skeleton::draw(QPainter *gl)
{
    QRect texture = QRect(0, 0, 16, 24);
    if(game->STEPS/15%2){
        texture = QRect(16, 0, 32, 24);
    }
    if(drawAttack > 0){
        texture = QRect(0, 24, 16, 48);
    }
    gl->drawImage(boundingRect(), game->resource->skeleton, texture);
}

void Skeleton::update()
{
    if(drawAttack > 0){
        --drawAttack;
    }
    if(attackDelay > 0){
        --attackDelay;
    }
    if(playerWithinRange(50) && attackDelay == 0){
        attackDelay = 100;
        drawAttack = 15;
        game->player->damaged(1);
        setDX(0);
        setDY(0);
    }
    else if(playerWithinRange(100)){
        chasePlayer(1);
    }
    else{
        setDY(0);
        int dx = (game->STEPS/40%4-1)%2;
        setDX(dx);
    }
    updateMove();
}
