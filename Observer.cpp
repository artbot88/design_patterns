#include <iostream>
#include <vector> 

using namespace std;

// Observer 
class Observer
{
public:
    virtual void update(int price) = 0;
};

// There is a common "topic" or "subject" that observers observe
// If there is something new happening on that topic, it sends out a notification
// to all observers
// Lets say the subject wants to notify all the observers about its new price
class StockPrice
{
private: 
    vector<Observer*> observers; 
public:
    void addObserver(Observer* o)
    {
        observers.push_back(o);
    }
    
    void notify(int price)
    {
        for(int i = 0 ; i < observers.size() ; i++)
            observers[i]->update(price);
    }
};

// Few observers to watch the subject
class AlgorithmicTrader : public Observer 
{
public:
    virtual void update(int price)
    {
        cout << "Algorithmic Trader saw the price at " << price << endl;
    }
};

// Few observers to watch the subject
class PriceLogger : public Observer 
{
public:
    virtual void update(int price)
    {
        cout << "Price logger saw the price at " << price << endl;
    }
};




int main() {
    StockPrice stockPrice; 
    
    // Our observers
    AlgorithmicTrader* at = new AlgorithmicTrader(); 
    PriceLogger * pl = new PriceLogger();
    
    // Add them to our notification list
    stockPrice.addObserver(dynamic_cast<Observer*>(at));
    stockPrice.addObserver(dynamic_cast<Observer*>(pl));
    
    
    // stock price changes to 42, notify our observers
    stockPrice.notify(42); 
    
    // stock price changes to 54, notify our observers
    stockPrice.notify(54); 
    
    stockPrice.notify(21); 
    
    
}




