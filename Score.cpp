#include "Score.h"
#include <QFont>

//Constructor
Score::Score(QGraphicsItem * parent) : QGraphicsTextItem(parent) // call base class construct passing in parent
{
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // convert number to string
    // make text red
    setDefaultTextColor(Qt::yellow);
    // change font
    setFont(QFont("times",16));
}

// increase score
void Score::increase()
{
    score++;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score));
}

// get score
int Score::getScore()
{
    return score;
}
