#include "../include/mySocket.hpp"

using namespace std;

string myTCPServer::myResponse(string input){
    // input = "2 4" [x y]
    
    int x,y = 0;

    if(input.compare(0, 4, "INIT")== 0){
        initWorld();
        MOVES = 0;

        return "OK\n";
    }

    if(input.compare(0, 4, "SIZE") == 0){
        string tmp = "";

        tmp = to_string(lX) + ", " + to_string(lY);

        return tmp;
    }

    if(input.compare(0, 6, "COORD[") == 0){
        int endInt; // Laenge des Input
        int comma;  // Position des Kommas

        comma = input.find(','); 
        endInt = input.find(']');

        string strX = input.substr(6, comma - (6));
        string strY = input.substr(comma+1, endInt - (comma + 1));

        x = stoi(strX);
        y = stoi(strY);

        cout << "x: " << x << " y: " << y << endl;

        TASK3::ShootResult tmp = this->world.shoot(x, y);

        if(tmp == TASK3::WATER){
            MOVES++;
            return "WATER";
        } if(tmp == TASK3::SHIP_HIT){
            //POINTS++;
            MOVES++;
            return "SHIP HIT";
        } if(tmp == TASK3::SHIP_DESTROYED){
            //POINTS++;
            MOVES++;
            //test
            return "SHIP DESTROYED";
        } if(tmp == TASK3::ALL_SHIPS_DESTROYED){
            //POINTS++;
            MOVES++;
            return "ALL SHIPS DESTROYED";
        } if(tmp == TASK3::GAME_OVER){
            return "GAME OVER";
        }

        return "ERROR\n";
    }

    else {
        return "UNKNOWN COMMAND\n";
    }

    return "ERROR\n";
}

int myTCPServer::getPoints(){
    return POINTS;
}

void myTCPServer::setPoints(int points_){
    POINTS = points_;
}

void myTCPServer::initWorld(){
    this->world = TASK3::World();
    lX = lY = 10;
    printWorld();
}

void myTCPServer::initWorld(int maxX, int maxY, int nmbFiver, int nmbFourer, int nmbThreer, int nmbTwoer){
    this->world = TASK3::World(maxX, maxY, nmbFiver, nmbFourer, nmbThreer, nmbTwoer);
    lX = maxX;
    lY = maxY;
    printWorld();
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