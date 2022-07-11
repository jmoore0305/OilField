#pragma once
#include "OilWellList.h"
#include "OilFieldDataParser.h"
#include <sys/types.h>     // needed for the _ftime() function
#include <sys/timeb.h>     // contains definition of _timeb struct
#include <time.h>          // needed for other time functions and structures
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "Display.h"
#include "OilFieldDataParser.h"
#include "OilWellList.h"
#include <stdlib.h>

using namespace std;

class OilWellSimulation
{
private:
	OilWellList* wellList;
	OilFieldDataParser* parser;
	Display* display;
	const char* fileName;
	struct _timeb tStruct;
	double thisTime;
	double outputTime;
	bool done;  // while loop flag
	bool running;
	int hit;     // key hit flag
	char ch;     // character key which was hit
	char response;

public:
	OilWellSimulation();
	~OilWellSimulation();
	void simulationMain();
	void displayAddWellMenu();
	void displayMenu();
	void displayReport();
	void updateReport();

};