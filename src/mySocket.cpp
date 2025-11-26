#include "../include/mySocket.hpp"

using namespace std;

string myTCPServer::myResponse(string input){
    // input = "2 4" [x y]
    
    int x,y;

    istringstream iss(input);
    iss >> x >> y;

    cout << "x: " << x << " y: " << y << endl;

    TASK3::ShootResult tmp = this->world.shoot(x, y);

    if(tmp == TASK3::WATER){
        return "WATER";
    } if(tmp == TASK3::SHIP_HIT){
        return "SHIP HIT";
    } if(tmp == TASK3::SHIP_DESTROYED){
        return "SHIP DESTROYED";
    } if(tmp == TASK3::ALL_SHIPS_DESTROYED){
        return "ALL SHIPS DESTROYED";
    } if(tmp == TASK3::GAME_OVER){
        return "GAME OVER";
    }

    return iss.str();
}

int myTCPServer::getGC(){
    return GC_;
}

void myTCPServer::setGC(int GC){
    GC_ = GC;
}

void myTCPServer::init(){
    this->world = TASK3::World();
}

void myTCPServer::init(int maxX, int maxY, int nmbFiver, int nmbFourer, int nmbThreer, int nmbTwoer){
    this->world = TASK3::World(maxX, maxY, nmbFiver, nmbFourer, nmbThreer, nmbTwoer);
}

// TCPClient methods
bool myTCPClient::sendData(string data){
    return 1;
}