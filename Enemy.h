#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject> // needed for signals and slots

class Enemy: public QObject, public QGraphicsPixmapItem
{   // Macro needed for slot/signal
    Q_OBJECT

public:
    // constructor
    Enemy(QGraphicsItem * parent=0);

public slots:
    //connected to timer signal to move enemy
    void move();
};

/*
 Signals and slots are used for communication between objects
*/

#endif // ENEMY_H


/*
  Note: When using slots and signals, three things are needed.
  1) Include <QObject> library
  2) Class must inherit from QObject
  3) Q_OBJECT macro is needed
*/
