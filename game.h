#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "world.h"
#include "camera.h"

class View;

class Game
{
public:
    Game(View *view);
    void load();
    void update();

    int WIDTH = 0;
    int HEIGHT = 0;
    int STEPS = 0;

    Camera *camera;
    World *world;

private:
    QGraphicsScene *scene;
    View *view;
};

#endif // GAME_H
