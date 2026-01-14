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

int main() {
	srand(time(NULL));
	TCPclient c;
	string host = "localhost";
	string msg;

	string rcvData;
	string sndData;

	int mX, mY; // 

	//connect to host
	c.conn(host , 2022);

	// get board size
	c.sendData("SIZE");
	rcvData = c.receive(32);

	int endInt; // Laenge des Input
    int comma;  // Position des Kommas

    comma = rcvData.find(','); 
    endInt = rcvData.length();

    string strMX = rcvData.substr(0, comma);
    string strMY = rcvData.substr(comma + 1, endInt - (comma + 1));

    mX = stoi(strMX);
    mY = stoi(strMY);

	cout << "x: " << mX << " y: " << mY << endl;

	int i=0;
	bool goOn=1;
	while(goOn){ // send and receive data
		
		sndData = string("client wants this");
		cout << "client sends:" << sndData << endl;
		c.sendData(sndData);

		rcvData = c.receive(32);
		cout << "got response:" << rcvData << endl;
		sleep(1);

	}
}