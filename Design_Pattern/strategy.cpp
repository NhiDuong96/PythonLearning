class Strategy{
public:
    virtual int oper(int a, int b) = 0;
};

class Add: public Strategy{
public:
    int oper(int a, int b){
        return a+b;
    }
};
class Sub: public Strategy{
public:
    int oper(int a, int b){
        return a-b;
    }
};

class Context{
public:
    Context(Strategy *s):s(s){}
    int exec(int a, int b){
        return s->oper(a,b);
    }
private:
    Strategy *s;
};

#include <stdio.h>

int main(){
    Context con(new Sub);
    printf("%d\n",con.exec(5,6));
}
