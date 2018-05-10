#include "dog.h"
#include <QtMath>
#include <QDateTime>

Dog::Dog(qint8 type = 1)
{
    this->current_speed = 0;
    this->x_position = 0.0;
    this->y_position = 20.0;
    this->ticks = 0;
    this->slip_chance = 0.0;
    this->random_generator = new QRandomGenerator(QDateTime::currentMSecsSinceEpoch());
    switch(type)
    {
    case 1:
        this->acceleration = 2;
        this->acceleration_time_end = 5;
        this->max_speed = 10;
        this->base_slip_chance = 0.0;
        break;
    case 2:
        this->acceleration = 3;
        this->acceleration_time_end = 4;
        this->max_speed = 12;
        this->base_slip_chance = 0.1;
        break;
    }
}

Dog::~Dog()
{
    delete random_generator;
}

void Dog::tick(qreal x_position_postman, qreal y_position_postman)
{
    qreal delta_x = qFabs(x_position_postman - this->x_position);
    qreal delta_y = qFabs(this->y_position - y_position_postman);
    qreal theta = qAtan(delta_x / delta_y);
    this->x_position += (qreal)this->current_speed * qSin(theta);
    this->y_position -= (qreal)this->current_speed * qCos(theta);
    this->x_position = (this->x_position < x_position_postman)?this->x_position:x_position_postman;
    this->y_position = (this->y_position > y_position_postman)?this->y_position:y_position_postman;
    if(this->ticks < this->acceleration_time_end)
    {
        this->current_speed += this->acceleration;
    }
    this->slip_chance += this->base_slip_chance / qPow(2.0, this->ticks);
    if(this->current_speed > this->max_speed)
    {
        this->current_speed = this->max_speed;
    }
    this->ticks++;
}

bool Dog::slip()
{
    if(qFuzzyIsNull(this->base_slip_chance))
    {
        return false;
    }
    qreal slip_generated = random_generator->bounded(1.0);
    if(slip_generated < this->slip_chance)
    {
        this->current_speed = 0.0;
        this->ticks = 0;
        this->slip_chance = 0.0;
        return true;
    }
    else
    {
        return false;
    }
}

qreal Dog::get_x_position()
{
    return this->x_position;
}

qreal Dog::get_y_position()
{
    return this->y_position;
}
