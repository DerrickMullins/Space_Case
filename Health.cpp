#include "Health.h"
#include <QFont>

//Constructor
Health::Health(QGraphicsItem * parent) : QGraphicsTextItem(parent) // call base class construct passing in parent
{
    // initialize health to 3
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // convert number to string
    // make text red
    setDefaultTextColor(Qt::red);
    // change font
    setFont(QFont("times",16));
}

// decrease health
void Health::decrease()
{
    // decrement health
    health--;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health));

    if (health == 0)
    {
        emit dead();
    }
}

// get score
int Health::getHealth()
{
    return health;
}
