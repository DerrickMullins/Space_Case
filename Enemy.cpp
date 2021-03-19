#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <Game.h>


extern Game * game;

// enemy constructor
Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem()
{
    // set random postion
    int random_number = rand() % 700; // 700 is 10 less than screen (prevents enemy from spawning off screen)
    setPos(random_number,0); //(x pos(), y pos())

   // make enemy same size as player
   setPixmap(QPixmap(":/images/enemy.png").scaled(75,75)); // .scaled sets size of enemy

    //connect
    QTimer * timer = new QTimer();

    //connects timeout() function of timer which will go off periodically to the move slot of enemy
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //sets timers time to 50 milli secs
    timer->start(50);
}


// move enemy
void Enemy::move()
{
    // move enemy down
    setPos(x(),y() + 5);

    // if enemy collides with player
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            // increase score
            game->health->decrease(); // access games score object and call increase member function

            // remove enemy
            scene()->removeItem(this);

            //delete enemy
            delete this;
            return; //prevents memory error
        }
     }

    // if enemy goes off screen
    if (pos().y() > 600 )
    {
        // decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;

    }
}
