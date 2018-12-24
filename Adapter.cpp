#include <iostream>


class OldClass
{
public:
    void oldInterface()
    {
        std::cout << "Running the old interface" << std::endl;
    }
}; 

class NewClass
{
public:
    virtual void newInterface() = 0;
}; 

// Wraps the old class around the new class
class OldClassAdapter : public NewClass
{
public:
    void newInterface()
    {
        oc.oldInterface();
    }
private:
    OldClass oc; 
};

int main() {
    NewClass* nc = new OldClassAdapter(); 
    nc->newInterface();
}
