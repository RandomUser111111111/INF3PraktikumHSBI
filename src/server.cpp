/*
 * server.C
 *
 *  Created on: 11.09.2019
 *      Author: aml
 */
#include <cstdio> // standard input and output library
#include <cstdlib> // this includes functions regarding memory allocation
#include <cstring> // contains string functions
#include <cerrno> //It defines macros for reporting and retrieving error conditions through error codes
#include <ctime> //contains various functions for manipulating date and time

#include <cctype> // for isdigit()

#include <unistd.h> //contains various constants
#include <sys/types.h> //contains a number of basic derived types that should be used whenever appropriate
#include <arpa/inet.h> // defines in_addr structure
#include <sys/socket.h> // for socket creation
#include <netinet/in.h> //contains constants and structures needed for internet domain addresses

#include "../include/SIMPLESOCKET.hpp"
#include "../include/mySocket.hpp"

using namespace std;

int main(int argc, char **argv){
	int port = 1234;

	// Check cmd line parameters and set port accordingly
	if(argc > 1){
		port = atoi(argv[1]);
	} else{
		cerr << "Usage \n./server <port>\n";
		exit(0);
	}


	srand(time(nullptr));
	myTCPServer srv(port,25);
	srv.run();
}
