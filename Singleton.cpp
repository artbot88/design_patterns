#include <iostream>

using namespace std; 

// The class which needs to be a singleton
class Logger
{
public:
    // Static function to get instance of the logger. 
    // Note static functions can only return static member variables.
    static Logger* getInstance()
    {
        if(m_logger == NULL)
        {
            // Instantiate if it does not exist
            m_logger = new Logger();
        }

        return m_logger;
    }
    void Log(string input)
    {
        cout << " Message : "<< input << " [lines logged =  " << ++count << "]" << endl; 
    }
private:
    // Static pointer to itself
    static Logger* m_logger; 
    
    // Any other member functions
    int count;
    
    // Make the singleton non copyable
    Logger() : count(0) {}
    Logger(const Logger& in){}
    Logger& operator=(Logger const&);
    
};

// Initialize the static member variable to be null
Logger* Logger::m_logger = NULL;

void function1()
{
    Logger::getInstance()->Log("Func 1 Hello world");
    Logger::getInstance()->Log("Func 1 Hello world");
}

void function2()
{
    Logger::getInstance()->Log("Func 2 Hello world");
    Logger::getInstance()->Log("Func 2 Hello world");
}

int main() {
  function1();
  function2();
}
