#include <iostream>

class FilterStrategy
{
public:
    virtual void runFilter() = 0;
   
};

class FIRFilter : public FilterStrategy
{
public:
    virtual void runFilter()
    {
        std::cout << "Running FIR Filter" << std::endl;
    }
};

class IIRFilter : public FilterStrategy
{
public:
    virtual void runFilter()
    {
        std::cout << "Running IIR Filter" << std::endl;
    }
};

class Filter
{
private:
    FilterStrategy* strategy; 

public:
    Filter() : strategy(NULL) {}
    
    void setStrategy(int type)
    {
        if(strategy != NULL)
            delete strategy; 
        
        switch(type)
        {
            case 1 : 
                strategy = new FIRFilter(); break;
            case 2 : 
                strategy = new IIRFilter(); break;
        }
    }
    
    void runFilter()
    {
        if(strategy != NULL)
            strategy->runFilter();
    }
    
};



int main() {
    Filter myFilter; 
    
    myFilter.setStrategy(1); 
    myFilter.runFilter(); 
    
    myFilter.setStrategy(2); 
    myFilter.runFilter(); 
    
    myFilter.setStrategy(1); 
    myFilter.runFilter(); 
    
    myFilter.setStrategy(2); 
    myFilter.runFilter(); 
    
}



