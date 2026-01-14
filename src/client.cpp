/*
 * client.C
 *
 *  Created on: 11.09.2019
 *      Author: aml
 */

#include <string>
#include <iostream>
#include <unistd.h> //contains various constants
#include <vector>
#include <fstream>

#include "../include/SIMPLESOCKET.hpp"

using namespace std;

int widthFirst(TCPclient *c);
int heightFirst(TCPclient *c);
int *getWorldSize(TCPclient *c);
int random(TCPclient *c);

struct Run{
	int m;
	string type;
};

int main(int argc, char **argv) {
	string strat = "";
	int n = 0;
	// Check cmd line parameters and set port accordingly
	if(argc > 2){
		strat = argv[1];
		n = atoi(argv[2]);
	} else{
		cerr << "Usage \n./client <strategy> <n>\n<strategy> height, width, rnd, all\n";
		exit(0);
	}

	srand(time(NULL));
	TCPclient c;
	string host = "localhost";
	
	vector <Run>runs;


	srand(time(NULL));

	c.conn("localhost" , 2022);
	
	
	if(strat == "width" || strat == "all"){
		for(int i = 0; i < n; i++){
		c.sendData("INIT");
		c.receive(32);

		Run tmp = { widthFirst(&c), "WIDTH" };

		runs.emplace_back(tmp);
		}
	}
	
	if(strat == "height" || strat == "all"){
		for(int i = 0; i < n; i++){
		c.sendData("INIT");
		c.receive(32);

		Run tmp = { heightFirst(&c), "HEIGHT" };

		runs.emplace_back(tmp);
		}
	}


	
	if(strat == "rnd" || strat == "all"){
		for(int i = 0; i < n; i++){
		c.sendData("INIT");
		c.receive(32);

		Run tmp = { random(&c), "RND" };

		runs.emplace_back(tmp);
		}
	}
	
	ofstream Data("data.csv");

	for(auto &run : runs){
		Data << run.type << ";" << run.m << endl; // write to file
		//cout << run.type << ";" << run.m << endl; // cmd line output
	}

	Data.close();

	c.sendData("BYEBYE");

	return 0;
}

int *getWorldSize(TCPclient *c){
	string rcvData;
	int mX, mY; // map size x & y
	mX = mY = 0;

	int *tmp = new int[2];

	tmp[0] = tmp[1] = 0;

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

	//cout << "x: " << mX << " y: " << mY << endl;

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

		//cout << "client sends:" << sndData << endl;
		c->sendData(sndData);

		moves++;

		rcvData = c->receive(32);
		//cout << "got response:" << rcvData << endl;

		//sleep(1);

	}

	return moves;
}

int heightFirst(TCPclient *c){
	string rcvData;
	string sndData;

	int *worldSize = getWorldSize(c);

	int mX = worldSize[0];
	int mY = worldSize[1];

	int shootX, shootY;	// stores where the next shot is
	shootX = shootY = 1; // map starts at 1

	int moves = 0; // stores the amount of moves it takes to win the game

	while(rcvData != "GAME OVER"){ // send and receive data
		
		if(shootY == mY){
			shootY = 1;
			shootX++;
		} else{
			shootY++;
		}

		sndData = "COORD[" + to_string(shootX) + ", " + to_string(shootY) + "]";

		//cout << "client sends:" << sndData << endl;
		c->sendData(sndData);

		moves++;

		rcvData = c->receive(32);
		//cout << "got response:" << rcvData << endl;

		//sleep(1);

	}

	return moves;
}

int random(TCPclient *c){
	string rcvData;
	string sndData;

	int *worldSize = getWorldSize(c);

	int mX = worldSize[0];
	int mY = worldSize[1];

	int shootX, shootY;	// stores where the next shot is
	shootX = shootY = 1; // map starts at 1

	int moves = 0; // stores the amount of moves it takes to win the game

	

	while(rcvData != "GAME OVER"){ // send and receive data
		
		shootX = rand()%(mX-1 + 1) + 1;
		shootY = rand()%(mY-1 + 1) + 1;

		sndData = "COORD[" + to_string(shootX) + ", " + to_string(shootY) + "]";

		//cout << "client sends:" << sndData << endl;
		c->sendData(sndData);

		moves++;

		rcvData = c->receive(32);
		//cout << "got response:" << rcvData << endl;

		//sleep(1);

	}

	return moves;
}