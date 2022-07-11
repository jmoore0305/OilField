#pragma once
#pragma warning(disable : 4996)
#include <string.h>
#include <iostream>
#include "SensorList.h"

class OilWell
{
private:
	char m_wellID[70];
	char m_wellOptr[70];
	bool displayStatus;
	int m_sensorCount;
	SensorList* sensorList;
public:
	OilWell(char*, char*, int, OilFieldDataParser*);
	OilWell();
	OilWell(char*, char*, int);
	char* getWellId();
	void setWellId(char*);
	void setDisplayValue(bool);
	bool getDisplayValue();
	char* getOptrName();
	SensorList* getSensorList();
	int getSensorCount();
	
};