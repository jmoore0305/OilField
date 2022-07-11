#pragma once
#pragma warning(disable : 4996)
#include <vector>
#include "Sensor.h"
#include <iostream>
#include "OilFieldDataParser.h"

using namespace std;

class SensorList
{
private:
	Sensor* sensor;
	vector<Sensor*> sensorList;
	vector<char*> sensorTypeList;
    int s_sensorCount;
	bool s_moreSensors;
	char s_wellID[70];
	char s_type[70];
	char s_className[70];
	char s_displayName[70];
	double s_min;
	double s_max;
	char s_units[70];
	char s_unitAbbrev[70];
public:
	SensorList(OilFieldDataParser*);
	SensorList();
	void addSensor(Sensor*);
	void incrementSensorCount();
	int getSensorCount();
	void loadSensorTypeList();
	void displaySensorType();
	bool searchSensorList(string);
	void displayActivelySelectedSensorData();
	vector<Sensor*> getList();
	Sensor* getSensor(int);
};