#pragma once
#include "OilWellList.h"
#include "OilWell.h"
#include <string>
using namespace std;
class Display
{
private:
	string id;
	string sensorType;
	int num;
	int selection;
	bool over;
	bool doneEnteringSensors;
	string ans;
	
public:
	Display();
	void wellMenuDisplay(OilWellList*);
	void sensorMenuDisplay(OilWellList*);
    void displaySensors(OilWell*);
	void reportDisplay(OilWellList*);
	void addWellMenuDisplay(OilWellList*);
	void displayActivelySelectedWellData(OilWellList*);
	void displayActivelySelectedSensorData(OilWell*);

};