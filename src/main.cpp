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

#include "../include/SHA256.hpp"
#include "../include/TASK1.hpp"
#include "../include/TASK2.hpp"
#include "../include/TASK3.hpp"
#include "../include/TASK4.hpp"
#include "../include/TASK5.hpp"
#include "../include/TASK6.hpp"

using namespace std;


int main(){
	srand(time(nullptr));
    TASK1::demoTASK1_00();
    return 0;
}





