//============================================================================
// Name        : INF3_Prak.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <string>
#include <iostream>

#include <cstdio>      /* printf, NULL */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

#include <unistd.h>

#include "../include/SHA256.H"
#include "../include/TASK3.H"
#include "../include/TASK4.H"
#include "../include/TASK5.H"
#include "../include/TASK6.H"

using namespace std;


int main(){
	srand(time(nullptr));
    TASK3::demoTask3();
    return 0;
}





