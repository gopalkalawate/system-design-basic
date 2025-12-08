/*
Def : Class should be open for extension but closed for modification
*/
#include<iostream>
using namespace std;

// example 
class Calculator{
    public:
    int calculate(int a,int b,int operation){
        if(operation==0){
            return a + b;
        }
        else if(operation==1){
            return a-b;
        }
        else if(operation==2){
            return a*b;
        }
        return 0;
    }
};/*
in this class if we want to add other function , we will have to create elseif condition for this 
this makes code less readable and we will have to change the class so we will need to test it again
*/ 

// better way
class IOperation{
    protected:
    int a,b;
    public :
    virtual int performOperation() = 0;
};

class Addition : IOperation{
public:
int performOperation() override{
    return a + b;
}
};

class Substraction : IOperation{
public:
int performOperation() override{
    return a - b;
}
};

class Multiplication : IOperation{
public:
int performOperation() override{
    return a*b;
}
};

class Divide : IOperation{
public:
int performOperation() override{
    return a/b;
}
};

class NewCalculator{
    public :
    int calculate(IOperation * operation){// always create pointer of abstract class , we can create instance of abstract class (defination)
        return operation->performOperation();
    }
};

/*
This way our class is open for extension but closed for modification
*/

