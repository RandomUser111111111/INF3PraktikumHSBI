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
        MOVES++;
        return "WATER\n";
    } if(tmp == TASK3::SHIP_HIT){
        //POINTS++;
        MOVES++;
        return "SHIP HIT\n";
    } if(tmp == TASK3::SHIP_DESTROYED){
        //POINTS++;
        MOVES++;
        return "SHIP DESTROYED\n";
    } if(tmp == TASK3::ALL_SHIPS_DESTROYED){
        //POINTS++;
        MOVES++;
        return "ALL SHIPS DESTROYED\n";
    } if(tmp == TASK3::GAME_OVER){
        return "GAME OVER\n";
    }

    return iss.str();
}

int myTCPServer::getPoints(){
    return POINTS;
}

void myTCPServer::setPoints(int points_){
    POINTS = points_;
}

void myTCPServer::initWorld(){
    this->world = TASK3::World();
}

void myTCPServer::initWorld(int maxX, int maxY, int nmbFiver, int nmbFourer, int nmbThreer, int nmbTwoer){
    
    this->world = TASK3::World(maxX, maxY, nmbFiver, nmbFourer, nmbThreer, nmbTwoer);
}

int myTCPServer::getMoves(){
    return MOVES;
}

void myTCPServer::printWorld(){
    this->world.printBoard();
}



// TCPClient methods
bool myTCPClient::sendData(string data){
    return 1;
}