#include "game.h"
#include "view.h"
#include <QApplication>
#include <QDesktopWidget>
#include "slime.h"
#include "player.h"

Game::Game(View *view)
{
    this->view = view;
    this->scene = view->scene();
    QRect resolution = QApplication::desktop()->screenGeometry();
    this->WIDTH = resolution.width();
    this->HEIGHT = resolution.height();
}

void Game::load(){
    resource = new Resource();
    resource->load();

    camera = new Camera(this);

    world = new World(this);
    world->load();
    scene->addItem(world);

    player = new Player(this, 100, 100);
    scene->addItem(player);

    loadEntities();
}

void Game::loadEntities(){
    world->addEntity(new Slime(this, 30, 30));
}

void Game::update(){
    STEPS++;
    player->update();
    world->update();
}
