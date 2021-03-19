#include "Game.h"
#include "GameOver.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Score.h"
#include <QBrush>
#include <QImage>
#include <QApplication>



Game::Game(QWidget * parent)
{
    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make scene 800x600 instead of 0x0 (W x H)
    // set image as background
    setBackgroundBrush(QBrush(QImage(":/images/space.jpg")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView widget
    // it can be used to visualize scenes)
    setScene(scene);

    // disable horizontal and vertical scroll bars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600); // W x H

    // create an item to put into the scene
    player = new Player();
    // set players position to center of screen
    player->setPos(400,500);
    // make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable); // set flag to true
    player->setFocus();
    // add player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25); // reposition health so it doesnt overlap score
    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    // create enemy every 2000 mili secs
    timer->start(2000);

    // end game when out of lives
    connect(health, SIGNAL(dead()), this, SLOT(end()));


}

void Game::end()
{
    if (health->getHealth() == 0)
    {

        scene->addText("Game Over");

        QApplication::quit();
    }
}


/*
  1) First we need to create a scene
  2) Next we need to create an item to put in the scene
  3) Then we need to add the item to the scene
  4) After we add the item to the scene we need to make it focusable so it can move and shoot
  5) Next we need to add a view to make the scene visible
  6) Next we disabled the scroll bars
  7) Lastly we have to show the view
  Note: Only one qgraphics item can respond to keyboard events at a time and can only be the focus item
  (Scene > View > Item)
*/
