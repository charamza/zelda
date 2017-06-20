#include "worldloader.h"
#include "world.h"
#include <QFile>
#include <QDebug>
#include "tile.h"
#include "game.h"
#include "player.h"
#include "skeleton.h"

WorldLoader::WorldLoader(World *world)
{
    this->world = world;
}

void WorldLoader::loadTilesheet(){
    solidTiles = new QList<int>();

    QStringList files;
    files << "../Zelda/world/tilesheet.tsx" << "../Zelda/world/mappoints.tsx";

    int idOffset = 0;
    int aoffset = 0;
    for(int f = 0; f < files.length(); f++){
        QFile file(files.at(f));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        idOffset = aoffset;

        int tileId = -1;
        int tileStart = -1;
        for(int i = 0; !file.atEnd(); i++){
            QString line = file.readLine();
            if(line.contains("<tile ")) {
                tileStart = i;
                tileId = line.split("id=\"")[1].split("\"")[0].toInt();
                continue;
            }
            if(line.contains("</tile>")) {
                tileStart = -1;
                continue;
            }
            if(line.contains("<tileset ")) {
                aoffset = line.split("tilecount=\"")[1].split("\"")[0].toInt();
                continue;
            }
            if(tileStart != -1){
                int depth = i - tileStart - 1;
                if(depth == 0) continue;
                if(line.contains("<property")) {
                    QString property = line.split("name=\"")[1].split("\"")[0];
                    QString value = line.split("value=\"")[1].split("\"")[0];
                    if(property == "solid" && value == "true") {
                        solidTiles->append(tileId);
                        qDebug() << "Tile" << tileId << "je solidni";
                    }
                    if(property == "spawn"){
                        EntitySpawn spawn;
                        spawn.id = tileId + idOffset;
                        spawn.name = value;
                        entitySpawns.append(spawn);
                        qDebug() << spawn.id << spawn.name;
                    }
                }
            }
        }
    }
}

void WorldLoader::loadWorld()
{
    QFile file("../Zelda/world/level1.tmx");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString list = file.readAll();
    world->LAYERS = list.count("<layer");

    world->world = new Tile***[world->LAYERS];
    file.seek(0);
    qDebug() << "Nacetli se" << world->LAYERS << "vrstvy.";

    int layer = -1;
    int layerStart = -1;
    for(int i = 0; !file.atEnd(); i++){
        QString line = file.readLine();
        if(line.contains("<layer")){
            world->WIDTH = line.split("width=\"")[1].split("\"")[0].toInt();
            world->HEIGHT = line.split("height=\"")[1].split("\"")[0].toInt();

            world->world[++layer] = new Tile**[world->WIDTH];
            for (int i = 0; i < world->WIDTH; ++i) {
                world->world[layer][i] = new Tile*[world->HEIGHT];
            }

            for(int x = 0; x < world->WIDTH; x++){
                for(int y = 0; y < world->HEIGHT; y++){
                    world->world[layer][x][y] = NULL;
                }
            }
        }
        if(line.contains("<data")) {layerStart = i; continue;}
        if(line.contains("</data>")) {layerStart = -1; continue;}
        if(layerStart != -1){
            int y = i - layerStart - 1;
            QStringList row = line.split(",");
            for(int x = 0; x < world->WIDTH; x++){
                int id = row[x].toInt() - 1;
                if(checkForSpawner(id, x, y)) continue;
                world->world[layer][x][y] = new Tile(world->game, x, y, id);
            }
        }
    }
}

bool WorldLoader::checkForSpawner(int id, int x, int y)
{
    int rx = x * Tile::SIZE;
    int ry = y * Tile::SIZE;

    for(int i = 0; i < entitySpawns.length(); i++){
        EntitySpawn spawn = entitySpawns.at(i);
        if(spawn.id == id){
            if(spawn.name == "Player"){
                Player *player = new Player(world->game, rx, ry);
                world->game->player = player;
                world->game->scene->addItem(player);
                player->setZValue(5);
                return true;
            }
            if(spawn.name == "Skeleton"){
                world->addEntity(new Skeleton(world->game, rx, ry));
                return true;
            }
        }
    }
    return false;
}
