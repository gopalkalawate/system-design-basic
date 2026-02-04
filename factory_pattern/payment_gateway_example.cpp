#include<iostream>
#include <memory>
using namespace std;

class PaymentGateway{
public:
    virtual void pay() = 0;
    virtual ~PaymentGateway() = default;
};

class StripePaymentGateway : public PaymentGateway{
public:
    void pay() override {
        cout<<"Paying using stripe\n";
    }
};

class PhonePayPaymentGateway : public PaymentGateway{
public:
    void pay() override{
        cout<<"Paying using phonePe\n";
    }
};

class PaymentFactory{
public:
    static unique_ptr<PaymentGateway> create(string provider){
        if(provider=="stripe"){
            return make_unique<StripePaymentGateway>();
        }
        else{//phonePe
            return make_unique<PhonePayPaymentGateway>();
        }
    }
};

/*
Notes:
Factory = one place decides which implementation represents an abstraction
Ex:
    Here the payment factory method decieds which object should be used
    this gives us an abstraction and the factory class can be used anywhere
    instead of writing logic on every different places.

Factory chooses implementations, not behavior.
To Sum up :
1) Factory centralizes creation decisions
2) It isolates change-prone logic
3) It prevents business code from knowing concrete classes
4) It enables runtime configurability
*/

int main(){
    unique_ptr <PaymentGateway> paymentGateway = PaymentFactory::create("phonePe"); 
    // here we need not write the logic , the decision is outsourced to the factory
    paymentGateway->pay();
}