#include "game.h"
#include "view.h"
#include <QApplication>
#include <QDesktopWidget>
#include "slime.h"
#include "player.h"
#include "skeleton.h"

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
    world->loadTilesheet();
    world->loadWorld();
    scene->addItem(world);

    player = new Player(this, 100, 100);
    scene->addItem(player);

    loadEntities();

    gui = new Gui(this);
    scene->addItem(gui);
}

void Game::loadEntities(){
    world->addEntity(new Slime(this, 300, 300));
    world->addEntity(new Skeleton(this, 200, 200));
}

void Game::update(){
    STEPS++;
    player->update();
    world->update();
}
