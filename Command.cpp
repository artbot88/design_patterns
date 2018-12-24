#include <iostream>
#include <vector> 

// The command pattern lets us build up a sequence of "commands"
// which the scheduler/executor can execute. 
// In our example main itself is the executor

using namespace std; 

// Consider a couple of appliances with different commands
// For a light, you have to set the state
class Light
{
public:
    void setLightState(int status)
    {
        if(status == 0)
            cout << "Turning light OFF" << endl;
        if(status == 1)
            cout << "Turning light ON" << endl;
    }

};
// For a heater, you have to turn the knob left/right
class Heater
{
public:
    void turnKnobRight()
    {
        cout << "Turning heater ON" << endl;
    }
    
    void turnKnobLeft()
    {
        cout << "Turning heater OFF" << endl;
    }

};

// Lets wrap these commands in a command interface
class Command
{
public:
    virtual void execute() = 0; 
};

class HeaterOnCommand : public Command
{
private:
    Heater *h;
public:
    HeaterOnCommand(Heater* _h) : h(_h) {}
    virtual void execute()
    {
        // The client doesnt need to know how to interact with the heater
        h->turnKnobRight(); 
    }
}; 

class LightOnCommand : public Command
{
private:
    Light *l;
public:
    LightOnCommand(Light * _l) : l(_l) {}
    virtual void execute()
    {
        // The client doesnt need to know how to interact with the light
        l->setLightState(1); 
    }
}; 





int main() {
    // Have some appliances
    Light* myLight = new Light();
    Heater* myHeater = new Heater();  
    
    // I want to execute a sequence of commands
    vector<Command*> commands; 
    commands.push_back(new LightOnCommand(myLight));
    commands.push_back(new HeaterOnCommand(myHeater));
    
    // execute them in a batch
    for(int i = 0 ; i < commands.size() ; i++)
        commands[i]->execute();
    
}



