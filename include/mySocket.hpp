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

using namespace std;

class myTCPServer: public TCPserver{
	public:
		using TCPserver::TCPserver;

	protected:
		string myResponse(string input);
};


class myTCPClient: public TCPclient{
    public:
        using TCPclient::TCPclient;

    protected:
	    bool sendData(string data);
};

#endif