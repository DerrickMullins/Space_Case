#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>


Player::Player(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    // set graphic
    setPixmap(QPixmap(":images/player.png").scaled(100,100));
}

// the key that is pressed is stored in event
void Player::keyPressEvent(QKeyEvent * event)
{   // left key
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 0)  // prevents player from moving off left side of screen
        setPos(x()-10,y()); // change x postion and keep y position
    }
    // right key
    else if (event->key() == Qt::Key_Right) //
    {
        if(pos().x() + 100 < 800)
        setPos(x()+10,y()); // change x position and keep y position
    }
    // space key
    else if (event->key() == Qt::Key_Space)
    {
        Bullet * bullet = new Bullet(); // create bullet
        bullet->setPos(x(),y()); // create at x and y position
        scene()->addItem(bullet); // bullet isnt visible until its added to the scene
    }
}

// spawn enemy
void Player::spawn()
{
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
/*
    Note: Every QGraphicsItem has a member function scene() which returns a pointer
    to the scene that its in.
*/
