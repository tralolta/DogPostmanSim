#ifndef DOG_H
#define DOG_H

#include <QRandomGenerator>

class Dog
{
private:
    qint32 current_speed;
    qint32 acceleration;
    qint32 acceleration_time_end;
    qint32 ticks;
    qint32 max_speed;
    qreal base_slip_chance;
    qreal slip_chance;
    qreal x_position;
    qreal y_position;
    QRandomGenerator* random_generator;
public:
    Dog(qint8);
    ~Dog();
    void tick(qreal, qreal);
    bool slip();
    qreal get_x_position();
    qreal get_y_position();
};

#endif // DOG_H
