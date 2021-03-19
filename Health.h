#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsSimpleTextItem>
#include <QObject>

class Health: public QGraphicsTextItem
{
    // Macro needed for slot/signal
    Q_OBJECT

public:
    // constructor
    Health(QGraphicsItem * parent = 0);
    void decrease();
    int getHealth();

signals:
    void dead();

private:
    int health;

};

#endif // HEALTH_H
