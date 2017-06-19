#ifndef RESOURCE_H
#define RESOURCE_H

#include <QImage>

class Resource
{
public:
    Resource();

    void load();

    QImage spritesheet;

    QImage player;
    QImage objects;
    QImage font;

    QImage entityLog;
    QImage entityNPC;

    QImage skeleton;
};

#endif // RESOURCE_H
