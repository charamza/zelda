#ifndef GUI_H
#define GUI_H
#include <QGraphicsItem>

class Game;

class Gui : public QGraphicsItem
{
public:
    Gui(Game *game);
     QRectF boundingRect() const;
     QPainterPath shape() const;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
     Game *game;
};

#endif // GUI_H
