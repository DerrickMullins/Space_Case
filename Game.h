#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSimpleTextItem>
#include "Player.h"
#include "Score.h"
#include "Health.h"




class Game: public QGraphicsView
{
    // Macro needed for slot/signal
    Q_OBJECT
  public:
    // constructor
    Game(QWidget * parent = 0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

public slots:
    // end game slot is connected to health
    void end();


};

#endif // GAME_H
