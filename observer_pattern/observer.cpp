#include<iostream>
#include<vector>
using namespace std;
class Observer{
    public:
    virtual void update(int newState) = 0;// pure virtual function
    virtual ~Observer() = default;
};

class Subject{
    public :
    virtual void registerObserver(Observer *obs) = 0;
    virtual void removeObserver(Observer *obs) = 0;
    virtual void notifyUsers() = 0;

    virtual ~Subject() = default;
};

class ImplementationSubject : public Subject{
private :
    vector<Observer*> observers;
    int state = 0;
public :

    void registerObserver(Observer *obs) override {
        observers.push_back(obs);
    }

    void removeObserver(Observer *obs) override{
            observers.erase(
            remove(observers.begin(), observers.end(), obs),
            observers.end()
        );        
    }

    void notifyUsers() override {
        for(Observer *obs : observers){
            obs->update(state);
        }
    }

    void setState(int newState){
        state = newState;
        notifyUsers();
    }

    int getState(){
        return state;
    }
};

class ImplementationObserver : public Observer{
    public:
    int observerState = 0;
    string name;
    Subject *subject;

    ImplementationObserver(Subject *s,string name){
        this->subject = s;
        this->name = name;
        s->registerObserver(this);
    }

    void update(int newState) override {
        observerState = newState;
        cout<<this->name<<" recieved new State "<<observerState<<endl;
    }
};

int main(){
    ImplementationSubject subject;
    ImplementationObserver o1(&subject,"gk");
    ImplementationObserver o2(&subject,"mb");
    ImplementationObserver o3(&subject,"Obs3");
    subject.setState(10);
    subject.setState(20);
}