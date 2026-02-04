#include<iostream>
using namespace std;
// implementing factory pattern
// abstract product
class Vehical{
public:
    virtual void printVehical() = 0;
};

// implementation of product classes
class TwoWheeler : public Vehical{
public:
    void printVehical() override{
        cout<<"Its two Wheeler\n";
    }
};

class FourWheeler : public Vehical{
public:
    void printVehical() override{
        cout<<"Its four Wheeler\n";
    }
};

// now we create factory classes , factory have the responsibility of creating products

// abstract factory
class VehicalFactory{
public:
    virtual Vehical * createVehical() = 0;
};

// implementation of Factory for various products 
class TwoWheelerFactory : public VehicalFactory{
public:
    Vehical *createVehical() override {
        return new TwoWheeler();
    }
};

class FourWheelerFactory : public VehicalFactory{
public:
    Vehical *createVehical() override{
        return new FourWheeler();
    }
};

class Client{
// client class 
private:
    Vehical * vehical;
public:
    Client(VehicalFactory *factory){
        vehical = factory->createVehical();
    }
    Vehical *getVehical(){
        return vehical;
    }
};

int main(){
    VehicalFactory *vehicalFactory = new TwoWheelerFactory();
    Client twoWheelerClient(vehicalFactory);
    Vehical *twoWheeler = twoWheelerClient.getVehical();
    twoWheeler->printVehical();
    
    delete vehicalFactory;
    vehicalFactory = new FourWheelerFactory();
    Client fourWheelerClient(vehicalFactory);
    Vehical *fourWheeler = fourWheelerClient.getVehical();
    fourWheeler->printVehical();
}