#pragma once
#include "OilWell.h"
#include "SensorList.h"
#include "Sensor.h"
#include <string>
#include <stdlib.h>
#include <sys/types.h>     // needed for the _ftime() function
#include <sys/timeb.h>     // contains definition of _timeb struct
#include <time.h>          // needed for other time functions and structures

using namespace std;

class OilWellList
{
private:
	bool moreWells;
	char wellID[32];
	char wellOptr[64];
	vector<OilWell*> wellList;
	vector<char*> wellIDList;
	vector<char*> wellNamesList;
	int sensorCount;
	string sensorSelection;
public:
	OilWellList(OilFieldDataParser*);
	void incrementSensorCount();
	void loadWellIDs();
	void loadWellNames();
	bool searchOilWellList(string);
	void displayWellNamesAndIDs();
	bool addWell(OilWell*);
	vector<OilWell*> getList();
	void updateData();
};