#ifndef WORLDLOADER_H
#define WORLDLOADER_H

#include <QList>

class World;

struct EntitySpawn {
   int id;
   QString name;
};

class WorldLoader
{
public:
    WorldLoader(World *world);

    void loadTilesheet();
    void loadWorld();
    bool checkForSpawner(int id, int x, int y);

    QList<int> *solidTiles;
    QList<EntitySpawn> entitySpawns;

private:
    World *world;
};

#endif // WORLDLOADER_H
