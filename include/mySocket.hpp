/**
 *
 * \file mySocket.hpp
 *
 * \brief Contains child classes myTCPServer and myTCPClient
 *
 *
 */


#ifndef MYSOCKET_H_
#define MYSOCKET_H_

#include <string>
#include <iostream>
#include "SIMPLESOCKET.hpp"
#include "TASK3.hpp"
#include <cctype>
#include <sstream>

using namespace std;

class myTCPServer: public TCPserver{
    private:
        int GC_ = 0;

        int lX, lY;

	public:
    TASK3::World world;
		using TCPserver::TCPserver;

        void init();    // Initialises the World, if no parameters are given the size will be set to the default
        void init(int maxX, int maxY, int nmbFiver, int nmbFourer, int nmbThreer, int nmbTwoer);    // Initialises the World with the given size parameters
	protected:
        int getGC();
        void setGC(int GC);

		string myResponse(string input);
};


class myTCPClient: public TCPclient{
    public:
        using TCPclient::TCPclient;

    protected:
	    bool sendData(string data);
};

#endif