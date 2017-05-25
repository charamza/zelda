#include "game.h"
#include "view.h"
#include <QApplication>
#include <QDesktopWidget>

Game::Game(View *view)
{
    this->view = view;
    this->scene = view->scene();
    QRect resolution = QApplication::desktop()->screenGeometry();
    this->WIDTH = resolution.width();
    this->HEIGHT = resolution.height();
}

void Game::load(){

}

void Game::update(){

}
