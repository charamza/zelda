#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "world.h"
#include "camera.h"
#include "resource.h"

class View;

class Game
{
public:
    Game(View *view);
    void load();
    void update();

    void loadEntities();

    int WIDTH = 0;
    int HEIGHT = 0;
    int STEPS = 0;

    Resource *resource;
    Camera *camera;
    World *world;

    QGraphicsScene *scene;
    View *view;
};

#endif // GAME_H
