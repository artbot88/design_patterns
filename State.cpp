#include <iostream>
using namespace std; 

// State pattern

// Note how declarations and definitions are decoupled

// Fwd declaration
class State; 


class Context
{
private:
    State* _state; 
public:
    Context();
    void setState(State* state);
    void Handle(); 
};


class State
{
protected:
    Context* _context; 
public:
    virtual void Handle() = 0;
    State(Context* context) : _context(context) {}
};

class StateA : public State
{
public:
    StateA(Context* context) : State(context) {}
    virtual void Handle();
};

class StateB : public State
{
public:
    StateB(Context* context) : State(context) {}
    virtual void Handle();
     
};

void StateA::Handle()
{
    cout << "Running in State A" << endl;
    _context->setState(new StateB(_context) ); 
}

void StateB::Handle()
{
    cout << "Running in State B" << endl;
    _context->setState(new StateA(_context) ); 
}
           
     

Context::Context()
{
    _state = new StateA(this);
}

void Context::setState(State* state)
{
    _state = state; 
}

void Context::Handle()
{
    _state->Handle();
}


int main() {
    Context ct; 
    
    for(int i = 0 ; i < 10 ; i++)
        ct.Handle();
}
