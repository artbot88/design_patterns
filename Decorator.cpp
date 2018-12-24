#include <iostream>

// Consider a shape class, with a drawShape feature.. 
// Derived classes implement the drawing feature
class Shape
{
public:
    virtual void drawShape() = 0; 
};

class Rectangle : public Shape
{
public:
    virtual void drawShape()
    {
        std::cout << "Drawing a rectangle" << std::endl;
    }
};

class Circle : public Shape
{
public:
    virtual void drawShape()
    {
        std::cout << "Drawing a circle" << std::endl;
    }
};

// Lets say we want to add decorations to the shape eg. border
class Decorator : public Shape
{
private:
    Shape* s; 

public:
    Decorator(Shape* _s) : s(_s) {}
    
    virtual void drawShape()
    {
        s->drawShape();
    }
   
};

class BorderDecorator : public Decorator
{
public:
    BorderDecorator(Shape* _s) : Decorator(_s) {}
    
    virtual void drawShape()
    {
        Decorator::drawShape(); 
        // Add the decoration
        std::cout << " with a pretty border" << std::endl;
    }
};





int main() {
    Shape* s = new Rectangle(); 
    s->drawShape();
    
    Shape* sd = new BorderDecorator(s); 
    sd->drawShape();
    
}





