#include <iostream>

// Facade makes a complex set of sequences wrapped under a simpler interface
// eg running series of subsystems in a particular order
// eg pipeline of image processing operations

class SubsystemA
{
public:
    void doSomething()
    {
        std::cout << "Subsystem A is doing something" << std::endl;
    }
};

class SubsystemB
{
public:
    void doSomething()
    {
        std::cout << "Subsystem B is doing something" << std::endl;
    }
};

class SubsystemC
{
public:
    void doSomething()
    {
        std::cout << "Subsystem C is doing something" << std::endl;
    }
};

class Facade
{
private:
    SubsystemA a; 
    SubsystemB b;
    SubsystemC c;

public:
    void achieveObjective1()
    {
        a.doSomething();
        c.doSomething();
    }
    
    void achieveObjective2()
    {
        b.doSomething();
        a.doSomething();
    }
    
};


int main() 
{
    Facade f; 
    f.achieveObjective1();
    f.achieveObjective2();
}



