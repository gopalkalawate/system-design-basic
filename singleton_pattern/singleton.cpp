#include<iostream>
using namespace std;
/*
The Singleton Design Pattern ensures that a class has 
only one instance and provides a global access point 
to it
*/

class Singleton{
private:
    Singleton() = default;

public:

    static Singleton& getInstance(){
        // since both copy constructor and assignment operator are deleted
        // we are haveing Singleton& over here.
        static Singleton instance;
        return instance;
    }

    Singleton(const Singleton&) = delete;// object must never be copied
    Singleton operator = (const Singleton&) = delete; // object must never be assigned

};

int main(){

}