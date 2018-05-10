#include <QTextStream>
#include <QThread>
#include <QtMultimedia/QSound>
#include <QtMath>
#include "simulationengine.h"

#include "dog.h"
#include "postman.h"

SimulationEngine::SimulationEngine(Dog* doge, Postman* postNam)
{
    this->dog = doge;
    this->postman = postNam;
}

void SimulationEngine::run()
{
    bool caught = false;
    QTextStream out(stdout);
    out << "Postman starting at [x:y] " << postman->get_x_position() << " : " << postman->get_y_position() << endl;
    out << "Dog starting at     [x:y] " << dog->get_x_position() << " : " << dog->get_y_position() << endl;
    qint32 ticks = 0;
    while(!caught)
    {
        postman->tick();
        out << "Postman moved to [x:y] "  << postman->get_x_position() << " : " << postman->get_y_position() << endl;
        if(!dog->slip())
        {
            dog->tick(postman->get_x_position(), postman->get_y_position());
            out << "Dog moved to     [x:y] " << dog->get_x_position() << " : " << dog->get_y_position() << endl;
        }
        else
        {
            out << "Dog slipped at   [x:y] " << dog->get_x_position() << " : " << dog->get_y_position() << endl;
        }
        out << "Distance: " << qSqrt(qPow(dog->get_x_position() - postman->get_x_position(), 2.0)
                                     + qPow(dog->get_y_position() - postman->get_y_position(), 2.0)) << endl;
        ticks++;
        if(dog->get_x_position() >= postman->get_x_position() && dog->get_y_position() <= postman->get_y_position())
        {
            caught = true;
        }
        QThread::msleep(1000);
    }
    out << "Dog caught the postman after " << ticks << " seconds!" << endl;
}
