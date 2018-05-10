#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

class Dog;
class Postman;

class SimulationEngine
{
private:
    Dog* dog;
    Postman* postman;
public:
    SimulationEngine(Dog*, Postman*);
    void run();
};

#endif // SIMULATIONENGINE_H
