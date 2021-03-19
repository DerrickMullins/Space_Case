#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    // constructor
    Player(QGraphicsItem * parent=0);
    //responds to keyboard being pressed
    void keyPressEvent(QKeyEvent * event);

public slots:
    //connected to timer signal to spawn enemies
    void spawn();
};


#endif // PLAYER_H



