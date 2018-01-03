#include <iostream>
#include <list>
using namespace std;

class Customer;
enum Meals
{
    SNACK, SOUP, NODLE
};

class Cooker{
public:
    Cooker(){}
    void cookSnack(){
        cout << "I will cook snack! \n";
    }
    void cookSoup(){
        cout << "I will cook soup! \n";
    }
};

class Order{
protected:
    Customer *cus;
public:
    Order(Customer *cus){this->cus = cus;}
    virtual void execute(Cooker *cooker);
};

class Snack: public Order{
public:
    Snack(Customer *cus):Order(cus){}
    void execute(Cooker *cooker){
        Order::execute(cooker);
        cout << "order snack: ";
        cooker->cookSnack();
    }
};
class Soup: public Order{
public:
    Soup(Customer *cus):Order(cus){}
    void execute(Cooker *cooker){
        Order::execute(cooker);
        cout << "order soup: ";
        cooker->cookSoup();
    }
};

class Customer{
private:
    char* name;
    int table;
public:
    Customer(char* name, int table):name(name),table(table){}
    Order* order(Meals meal){
        switch(meal){
            case SNACK:
                return new Snack(this);
            case SOUP:
                return new Soup(this);
            case NODLE:
            break;
            default:
            break;
        }
    }
    void getInfor(){
        cout << name << " " << table << " ";
    }
};

void Order::execute(Cooker *cooker){
    cus->getInfor();
}


class Waiter{
    private:
        list<Order*> orders;
    public:
        void takeOrder(Order *order){
            orders.push_back(order);
        }
        void placeOrders(Cooker *cooker){
            list<Order*>::iterator it = orders.begin();
            for(;it != orders.end(); it++){
                (*it)->execute(cooker);
            }
            orders.clear();
        }
};



int main(){
    Waiter waiter;
    Cooker cooker;
    Customer cus((char*)"nhi",10);

    waiter.takeOrder(cus.order(SNACK));
    waiter.takeOrder(cus.order(SOUP));
    waiter.placeOrders(&cooker);
    //waiter take orders from customer and then pass them to cooker who would cook them
}

