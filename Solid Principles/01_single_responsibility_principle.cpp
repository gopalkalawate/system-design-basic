/*
Def : A class shoule have only single reason to change
*/
#include<iostream>
using namespace std;

class CabFareCalculation{
public:
    int distance;
    int paymentReq;

    float calulateFarePrice(){

    }

    float registerPaymentDiscount(int discount,int paymentMode){

    }

    void generateInvoiceAndSaveToDatabase(){

    }
    // if anything changes the class will have to changed 
};