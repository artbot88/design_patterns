#include <iostream>

// abstraction ------ implementation
// (refined abs.)       (concrete implementation)
// Bridge between abstraction and implementation
// Think vehicle (abstraction) - workshop (implementation)
// Vehicle could be car, bike etc. 
// Workshop can be of type bodyshop, oilshop etc. 

class Abstraction; 

class Implementation
{
public:
    virtual void doSomething(std::string object) = 0; 
};

class ConcreteImplementation1 : public Implementation
{
public:
    virtual void doSomething(std::string object)
    {
        std::cout << "Running implementation 1 on " << object << std::endl;
    }
};

// There could be other implementations.... 

class Abstraction
{
protected:
    Implementation* impl; 

    
public:
    
    void setImplmentation(Implementation * _impl)
    {
        impl = _impl;
    }
    
    virtual void performOperation() = 0;
   
};

class RefinedAbstraction1 : public Abstraction
{
public:
    virtual void performOperation()
    {
        impl->doSomething("Refined Abstraction 1");
    }
};

int main() {
    Abstraction* ra = new RefinedAbstraction1(); 
    Implementation* ca = new ConcreteImplementation1(); 
    
    ra->setImplmentation(ca); 
    
    ra->performOperation();
    
}






