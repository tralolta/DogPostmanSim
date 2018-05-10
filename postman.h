#ifndef POSTMAN_H
#define POSTMAN_H

#include <QRandomGenerator>

class Postman
{
private:
    qreal speed;
    qreal x_position;
    qreal y_position;
    qint8 time_to_wait;
    QRandomGenerator* random_generator;
public:
    Postman(qint8);
    ~Postman();
    void tick();
    qreal get_x_position();
    qreal get_y_position();
};

#endif // POSTMAN_H
