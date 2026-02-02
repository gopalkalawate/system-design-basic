/*
High-level modules should not depend on low-level modules. Both should depend on abstractions.

Abstractions should not depend on details. Details should depend on abstractions.

Simply : Code to interfaces, not implementations.
*/
#include<iostream>
using namespace std;

class Manager{
public:
    void addDeveloper(Developer developer){

    }
    void addTester(){
        // ...
    }
};

class Developer{

};
// in the above code we need to keep on adding function in manager class a better thinng would be
// make an interface employee inherit employee to Developer and Tester and 
// have a function addEmployee(Employee emplouyee){} that adds employee