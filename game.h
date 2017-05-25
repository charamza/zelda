#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>

class View;

class Game
{
public:
    Game(View *view);
    void load();
    void update();

    int WIDTH;
    int HEIGHT;

private:
    QGraphicsScene *scene;
    View *view;
};

#endif // GAME_H
