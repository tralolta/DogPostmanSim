#include "postman.h"

#include <QDateTime>

Postman::Postman(qint8 type = 1)
{
    this->random_generator = new QRandomGenerator(QDateTime::currentMSecsSinceEpoch());
    this->speed = 0;
    this->y_position = 0;
    this->x_position = random_generator->bounded(100.0);
    switch (type) {
    case 1:
        this->speed = 5.0;
        this->time_to_wait = 3;
        break;
    case 2:
        this->speed = 2.5;
        this->time_to_wait = 0;
        break;
    }
}

Postman::~Postman()
{
    delete this->random_generator;
}

void Postman::tick()
{
    if(time_to_wait > 0)
    {
        time_to_wait--;
        return;
    }
    this->x_position += this->speed;
}

qreal Postman::get_x_position()
{
    return x_position;
}

qreal Postman::get_y_position()
{
    return y_position;
}
