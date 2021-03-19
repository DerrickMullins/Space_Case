#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList> // needed to detect item collision

// there is an external global object game
extern Game * game;

//Constructor
Bullet::Bullet(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    // draw graphics
    setPixmap(QPixmap(":/images/lazer.png"));

    //connect
    QTimer * timer = new QTimer();
    //connects timeout() function of timer which will go off periodically to the move slot of bullet
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //sets timers time to 50 milli secs
    timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            // increase score
            game->score->increase(); // access games score object and call increase member function

            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //delete them both
            delete colliding_items[i];
            delete this;
            return; //prevents memory error
        }
    }

    // move bullet up
    setPos(x(),y()-10);

    // if bullet goes off screen
    if (pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted";
    }
}

/*
  NOTE: If bullet collides with enemy, destroy both
  1) store list of colliding QGraphicsItem pointers (enemies) in colliding_items
  2) traverse said list
  3) if current pointer type id is = to enemy id remove/delete both
*/
