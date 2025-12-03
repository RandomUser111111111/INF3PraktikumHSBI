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

/**
 *
 *  \class myTCPclient
 *  \brief The Class defining the game Server
 *
 */

class myTCPServer: public TCPserver{
    private:
        int POINTS = 0;
        int MOVES = 0;

        int lX, lY;

        TASK3::World world;

	public:
		using TCPserver::TCPserver;

        void initWorld();    // Initialises the World, if no parameters are given the size will be set to the default
        void initWorld(int maxX, int maxY, int nmbFiver, int nmbFourer, int nmbThreer, int nmbTwoer);    // Initialises the World with the given size parameters
	
        void printWorld();
    
    protected:
        int getPoints();
        void setPoints(int points_);
        
        int getMoves();

		string myResponse(string input);
};

/**
 *
 *  \class myTCPclient
 *  \brief The Class defining the game Client
 *
 */

class myTCPClient: public TCPclient{
    public:
        using TCPclient::TCPclient;

    protected:
	    bool sendData(string data);
};

#endif