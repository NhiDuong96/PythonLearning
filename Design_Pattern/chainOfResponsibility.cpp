#include <iostream>

using namespace std;

class ATM{
    ATM *next;
    public:
        ATM(){
            next = NULL;
        }
        void nextHandle(ATM *n){
            next = n;
        }
        virtual void handle(int money){
            if(next != NULL)
                next->handle(money);
            else
                cout << "Giao dich that bai!" << endl;
        }
};

class MenhGia: public ATM{
    int menhgia;
    int amount;
    public:
    MenhGia(int menhgia){
        this->menhgia = menhgia;
        amount = 0;
    }
    void setAmount(int a){
        amount = a;
    }
    void handle(int money){
        int count = 0;
        while(money >= menhgia && amount > 0){
            money -= menhgia;
            count++;
            amount--;
        }
        cout << count << " to " << menhgia << endl;
        if(money > 0)
            ATM::handle(money);
        else
            cout << "Rut tien!" << endl; 
    }
};

int main(){
    MenhGia m500(500);m500.setAmount(2);
    MenhGia m200(200);m200.setAmount(5);
    MenhGia m100(100);m100.setAmount(10);
    MenhGia m50(50);  m50.setAmount(20);
    m500.nextHandle(&m200);
    m200.nextHandle(&m100);
    m100.nextHandle(&m50);
    m500.handle(3050);
}