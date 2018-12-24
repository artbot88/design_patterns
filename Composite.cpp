#include <iostream>
#include <vector>
// Composites - used to represent a hierarchical tree of objects
// Used for train - car - wheel type of representation
using namespace std; 

class Component
{
public:
    string id; 
    Component(string _id) : id(_id) {}; 
    
    vector<Component*> children; 
    
    void traverse()
    {
        cout << id << endl; 
        for(int i = 0 ; i < children.size() ; i++)
            children[i]->traverse();
    }
    
    void add(Component* c)
    {
        children.push_back(c);
    }
};


class Truck : public Component
{
public:
    Truck(string _id):Component(_id) {}
};

class Car : public Component
{
public:
    Car(string _id):Component(_id) {}
};

class Train : public Component
{
public:
    Train(string _id):Component(_id) {}
};


int main() {
    Component* train = new Train("Train1"); 
    
    Component* car1 = new Car("Car1");
    Component* car2 = new Car("Car2");
    
    Component* truck1 = new Truck("T1");
    Component* truck2 = new Truck("T2");
    Component* truck3 = new Truck("T3");
    Component* truck4 = new Truck("T4");
    
    car1->add(truck1);
    car1->add(truck2);
    
    car2->add(truck3);
    car2->add(truck4);
    
    train->add(car1); 
    train->add(car2);
    
    car2->traverse();
    //train->traverse();
    
    
}




