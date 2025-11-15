class Observer:#interface
    def update(self,new_state):
        NotImplementedError("sub-class must override update()")

class Subject:
    def registerObserver(self,obs):
        NotImplementedError

    def removeObserver(self,obs):
        raise NotImplementedError
    
    def notifyObservers(self):
        raise NotImplementedError
    
class SubjectImpl(Subject):
    def __init__(self):
        self.observers = []
        self.state = 0
    
    def registerObserver(self,obs):
        self.observers.append(obs)

    def notifyObservers(self):
        for obs in self.observers:
            obs.update(self.state)

    def setState(self,value):
        self.state = value
        self.notifyObservers()

    def getState(self):
        return self.state
    

class ObserverImpl(Observer):
    def __init__(self,subject,name):
        self.subject = subject
        self.name = name
        self.observerState = 0
        subject.registerObserver(self)
    

    def update(self, new_state):
        self.observerState = new_state
        print(f"{self.name} received new state = {self.observerState}")


subject = SubjectImpl()
o1 = ObserverImpl(subject,"first")
o2 = ObserverImpl(subject,"o2")

subject.setState(10)
subject.setState(100)
subject.setState("Wake up!")