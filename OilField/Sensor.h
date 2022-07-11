
#pragma once
#pragma warning(disable : 4996)
#include <string.h>
class Sensor
{
private:
	char m_wellID[70];
	char m_type[70];
	char m_className[70];
	char m_displayName[70];
	double m_min;
	double m_max;
	double m_curr_val;
	char m_units[70];
	char m_unitAbbrev[70];
	bool displayStatus;
public:
	Sensor(char*, char*, char*, char*,
		double, double, char*, char*);
	Sensor();
	void displayValues();
	void setDisplayStatus(bool);
	bool getDisplayStatus();
	char* getSensorUnitType();
	void setCurrentValue(double);
};