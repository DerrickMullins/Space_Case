#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsSimpleTextItem>

class Score: public QGraphicsTextItem
{
public:
    // constructor
    Score(QGraphicsItem * parent = 0);
    void increase();
    int getScore();

private:
    int score;
};

#endif // SCORE_H
