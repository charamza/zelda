#include "world.h"
#include "game.h"
#include "tile.h"
#include "watertile.h"
#include <QFile>
#include <QDebug>

World::World(Game *game)
{
    this->game = game;
    spritesheet.load("../Zelda/Overworld.png");
}

void World::load()
{
    QFile file("../Zelda/mapa.tmx");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString list = file.readAll();
    LAYERS = list.count("<layer");

    world = new Tile***[LAYERS];
    file.seek(0);
    qDebug() << "Nacetli se" << LAYERS << "vrstvy.";

    int layer = -1;
    int layerStart = -1;
    for(int i = 0; !file.atEnd(); i++){
        QString line = file.readLine();
        if(line.contains("<layer")){
            WIDTH = line.split("width=\"")[1].split("\"")[0].toInt();
            HEIGHT = line.split("height=\"")[1].split("\"")[0].toInt();

            world[++layer] = new Tile**[WIDTH];
            for (int i = 0; i < WIDTH; ++i) {
                world[layer][i] = new Tile*[HEIGHT];
            }

            for(int x = 0; x < WIDTH; x++){
                for(int y = 0; y < HEIGHT; y++){
                    world[layer][x][y] = NULL;
                }
            }
        }
        if(line.contains("<data")) {layerStart = i; continue;}
        if(line.contains("</data>")) {layerStart = -1; continue;}
        if(layerStart != -1){
            int y = i - layerStart - 1;
            QStringList row = line.split(",");
            for(int x = 0; x < WIDTH; x++)
                world[layer][x][y] = new Tile(game, x, y, row[x].toInt() - 1);
        }
    }
}

void World::update()
{

}

void World::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int bx = game->camera->getPosition().rx()/Tile::SIZE;
    int by = game->camera->getPosition().ry()/Tile::SIZE;
    if(bx < 0) bx = 0;
    if(by < 0) by = 0;
    int fx = bx+game->WIDTH/Tile::SIZE+2;
    int fy = by+game->HEIGHT/Tile::SIZE+2;
    if(fx>WIDTH) fx = WIDTH;
    if(fy>HEIGHT) fy = HEIGHT;

    for(int w = 0; w < LAYERS; w++)
        for(int x = bx; x < fx; x++){
            for(int y = by; y < fy; y++){
                Tile *tile = world[w][x][y];
                if(tile != NULL){
                    tile->update();
                    painter->drawImage(tile->getBounds(), spritesheet, tile->getTexCoords());
                }
            }
        }
}

QRectF World::boundingRect() const
{
    return QRectF(0, 0, Tile::SIZE*WIDTH, Tile::SIZE*HEIGHT);
}

QPainterPath World::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}
