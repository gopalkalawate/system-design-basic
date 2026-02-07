#include<iostream>
#include<string>
using namespace std;

// Component interface
class Coffee{
public:
    virtual string getDescrition() = 0;
    virtual double getCost() = 0;
};


// Concrete Component : Implements the Component interface
class PlainCoffee : public Coffee{
public:
   
    string getDescrition() override {
        return "This is Plain Coffee";
    }
    double getCost() override {
        return 2.0;
    }
};

// Decorator interface
class CoffeeDecorator :public Coffee{
protected:
    Coffee * decoratedCoffee;
public:
    CoffeeDecorator(Coffee * coffee){
        decoratedCoffee = coffee;
    }
    virtual string getDescrition() override{
            return decoratedCoffee->getDescrition();
        }
        virtual double getCost() override{
            return decoratedCoffee->getCost();
        }
};

// decorator implementation
class SugarDecorator : public CoffeeDecorator{
public:
    SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {} // calling the super constructor

    string getDescrition() override {
        return CoffeeDecorator::getDescrition() + ", Milk";
    }
    double getCost() override {
        return CoffeeDecorator::getCost() + 0.5;
    }
};

class Whipped : public CoffeeDecorator{
    public:
    Whipped(Coffee * coffee) : CoffeeDecorator(coffee){}
    string getDescrition() override{
        return CoffeeDecorator::getDescrition() + ", Capachino";
    }
    double getCost() override{
        return CoffeeDecorator::getCost() + 1.0;
    }
};

int main(){
    // get whipped + sugar

    // 1. Start with base coffee
    Coffee *myCoffee = new PlainCoffee();
    // 2. Add Sugar
    myCoffee = new SugarDecorator(myCoffee);
    // 3. Add Capachino
    myCoffee = new Whipped(myCoffee);

    cout << "Order: " << myCoffee->getDescrition() << endl;
    cout << "Total Cost: $" << myCoffee->getCost() << endl;

    // Cleanup (In real HLD/LLD, use smart pointers like std::unique_ptr!)
    delete myCoffee; 
    return 0;
}