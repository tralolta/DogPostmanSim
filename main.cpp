#include <QCoreApplication>
#include <QTextStream>

#include "simulationengine.h"
#include "dog.h"
#include "postman.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out(stdout);
    out << "===========================================" << endl;
    out << "Dog type 1, Postman type 1" << endl;
    SimulationEngine(new Dog(1), new Postman(1)).run();
    out << "===========================================" << endl;
    out << "Dog type 1, Postman type 2" << endl;
    SimulationEngine(new Dog(1), new Postman(2)).run();
    out << "===========================================" << endl;
    out << "Dog type 2, Postman type 1" << endl;
    SimulationEngine(new Dog(2), new Postman(1)).run();
    out << "===========================================" << endl;
    out << "Dog type 2, Postman type 2" << endl;
    SimulationEngine(new Dog(2), new Postman(2)).run();
    out << "===========================================" << endl;
    return a.exec();
}
