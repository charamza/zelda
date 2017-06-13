#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "world.h"
#include "camera.h"
#include "resource.h"
#include "player.h"
#include "gui.h"

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
    Player *player;
    Gui *gui;

    QGraphicsScene *scene;
    View *view;
};

#endif // GAME_H
