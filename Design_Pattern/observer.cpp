#include <iostream>
#include <list>
#include <stdio.h>
using namespace std;

class Observer;

class Subject{
public:
    void setState(int state){
        this->state = state;
        notifyAll();
    }
    int getState(){
        return state;
    }
    void attach(Observer* observer){
        observers.push_back(observer);
    }
    void notifyAll();

private:
    list<Observer*> observers;
    int state;
};


class Observer{
    public:
        Observer(Subject *subject, int state){
            this->subject = subject;
            this->state = state;
            subject->attach(this);
        }
        virtual void update(){}
        void getState(){
            printf("%d\n",state);
        }
    protected:
        Subject *subject;
        int state;
};

void Subject::notifyAll(){
        list<Observer*>::iterator it = observers.begin();
        for(;it!=observers.end();it++){
            (*it)->update();
        }
}

class Div: public Observer{
public:
    Div(Subject *subject, int state):Observer(subject,state){}
    void update(){
        state = subject->getState()/state;

    }
};

class Mul: public Observer{
public:
    Mul(Subject *subject, int state):Observer(subject,state){}
    void update(){
        state = subject->getState()*state;
    }
};


int main(){
    Subject subject;
    Div div(&subject,3);
    Mul mul(&subject,2);
    subject.setState(12); //change state Target
    div.getState(); //automatically change
    mul.getState();
}
