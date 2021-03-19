#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject> // needed for signals and slots

class Bullet: public QObject, public QGraphicsPixmapItem
{   // macro needed for signals and slots
    Q_OBJECT
public:
    // constructor
    Bullet(QGraphicsItem * parent=0);
public slots:
    //connected to timer signal to move bullet
    void move();
};

#endif // BULLET_H

/*
 Signals and slots are used for communication between objects
*/
