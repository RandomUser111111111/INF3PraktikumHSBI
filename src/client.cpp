/*
 * client.C
 *
 *  Created on: 11.09.2019
 *      Author: aml
 */

#include <string>
#include <iostream>
#include <unistd.h> //contains various constants

#include "../include/SIMPLESOCKET.hpp"

using namespace std;

int widthFirst(TCPclient* c);
int *getWorldSize(TCPclient* c);

int main() {
	srand(time(NULL));
	TCPclient c;
	string host = "localhost";
	string msg;

	c.conn("localhost" , 2022);

	int moves = widthFirst(&c);

	cout << "total moves: " << moves << endl;

	c.sendData("BYEBYE");

	return 0;
}

int *getWorldSize(TCPclient* c){
	string rcvData;
	int mX, mY; // map size x & y
	mX = mY = 0;

	int *tmp;

	c->sendData("SIZE");
	rcvData = c->receive(32);

	int endInt;
    int comma;

    comma = rcvData.find(','); 
    endInt = rcvData.length();

    string strMX = rcvData.substr(0, comma);
    string strMY = rcvData.substr(comma + 1, endInt - (comma + 1));

    mX = stoi(strMX);
    mY = stoi(strMY);

	cout << "x: " << mX << " y: " << mY << endl;

	tmp[0] = mX;
	tmp[1] = mY;

	return tmp;
}

int widthFirst(TCPclient *c){
	string rcvData;
	string sndData;

	int *worldSize = getWorldSize(c);

	int mX = worldSize[0];
	int mY = worldSize[1];

	int shootX, shootY;	// stores where the next shot is
	shootX = shootY = 1; // map starts at 1

	int moves = 0; // stores the amount of moves it takes to win the game

	while(rcvData != "GAME OVER"){ // send and receive data
		
		if(shootX == mX){
			shootX = 1;
			shootY++;
		} else{
			shootX++;
		}

		sndData = "COORD[" + to_string(shootX) + ", " + to_string(shootY) + "]";

		cout << "client sends:" << sndData << endl;
		c->sendData(sndData);

		moves++;

		rcvData = c->receive(32);
		cout << "got response:" << rcvData << endl;

		//sleep(1);

	}

	return moves;
}

