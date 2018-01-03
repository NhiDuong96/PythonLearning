#include <iostream>
using namespace std;

class State;

class Game{
protected:
    class State *current;
public:
    void setState(State *s){
        current = s;
    }
    void getState();
    void start();
    void resume();
    void pause();
    void stop();
    void restart();
    void destroy();

    virtual void onCreate()=0;
    virtual void onStart()=0;
    virtual void onResume()=0;
    virtual void onPause()=0;
    virtual void onStop()=0;
    virtual void onReStart()=0;
    virtual void onDestroy()=0;
};

class State{
    public:
        virtual void onStateCreate(Game *g){}
        virtual void onStateStart(Game *g){}
        virtual void onStateResume(Game *g){}
        virtual void onStatePause(Game *g){}
        virtual void onStateStop(Game *g){}
        virtual void onStateReStart(Game *g){}
        virtual void onStateDestroy(Game *g){}
        virtual void getState(){}
};

void Game::start(){
    current->onStateStart(this);
}
void Game::pause(){
    current->onStatePause(this);
}
void Game::resume(){
    current->onStateResume(this);
}

void Game::stop(){
    current->onStateStop(this);
}
void Game::restart(){
    current->onStateReStart(this);
    current->onStateStart(this);
}
void Game::destroy(){
    current->onStateDestroy(this);
}
void Game::getState(){
    current->getState();
}

//user implementation

class LAUNCH: public State{
public:
    LAUNCH(){
        cout << "Launch game!\n";
    }
    void getState(){
        cout << "LAUNCH\n";
    }
    void onStateCreate(Game *g);
};

class CREATED: public State{
public:
    CREATED(){
        cout << "Created game!\n";

    }
    void getState(){
        cout << "CREATED\n";
    }
    void onStateStart(Game *g);
    void onStateStop(Game *g){
        cout << "Game is not Started, so you can't stop it!\n";
    }
};

void LAUNCH::onStateCreate(Game *g){
        cout << "Parent on Create Game\n";
        g->onCreate();
        g->setState(new CREATED);
        delete this;
}

class STARTED: public State{
public:
    STARTED(){
        cout << "Started game!\n";
    }
    void getState(){
        cout << "STARTED\n";
    }
    void onStatePause(Game *g){
        cout << "Parent on Pause Game\n";
        //
        delete this;
    }
    void onStateStop(Game *g){
        cout << "Parent on Stop Game\n";
        //
        delete this;
    }
};

void CREATED::onStateStart(Game *g){
        cout << "Parent on Start Game\n";
        g->onStart();
        g->setState(new STARTED);
        delete this;
}


class SudoGame:public Game{
public:
    SudoGame(){
        current = new LAUNCH;
        current->onStateCreate(this);
    }
    void onCreate(){
        cout << "Sudo game on Create\n";
    }
    void onStart(){
        cout << "Sudo game on Start\n";
    }
    void onResume(){};
    void onPause(){};
    void onStop(){};
    void onReStart(){};
    void onDestroy(){};
};
int main(){
    SudoGame *game = new SudoGame;
    game->getState();
    game->start();
    game->getState();
    game->stop();
}
