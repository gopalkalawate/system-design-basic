/*
Clients should not be forced to depend on interfaces they do not use.
                        OR
Many small, specific interfaces are better than one large, general-purpose interface.
*/
#include<iostream>
using namespace std;

class OrderService{
    public : 
    virtual void orderBurger(int quantity) = 0;
    virtual void orderFries(int quantity) = 0;
    virtual void orderCombo(int quantity,int fries) = 0;
};

class BurgerOrderService : OrderService{
    void orderBurger(int quantity) override {
        // we only need this 
        // but we still need to implement other two methods as we can't create object of abstract class
    }
    void orderFries(int quantity) override{

    }
    void orderCombo(int quantity,int fries) override{

    }
};

// a better method would be to create 

class Order{
    virtual void placeOrder(int quantity) = 0;
};
class Burger : Order{
    void placeOrder(int quantity) override {
        
    }
};

int main(){
    BurgerOrderService BurgerOrderService;
}