#include "Sensor.h"
#include <iostream>

using namespace std;

Sensor::Sensor(char* id, char* type, char* cName, char* dName, double min, double max, char* units, char* unitAbbrev)
{
	m_min = min;
	m_max = max;
	m_curr_val = 0;
	displayStatus = false;
	strcpy(m_wellID, id);
	strcpy(m_type, type);
	strcpy(m_className, cName);
	strcpy(m_displayName, dName);
	strcpy(m_units, units);
	strcpy(m_unitAbbrev, unitAbbrev);
}


Sensor::Sensor()
{
	m_min = 0;
	m_max = 100;
	displayStatus = false;
	strcpy(m_wellID, NULL);
	strcpy(m_type, NULL);
	strcpy(m_className, NULL);
	strcpy(m_displayName, NULL);
	strcpy(m_units, NULL);
	strcpy(m_unitAbbrev, NULL);
}


void Sensor::displayValues()
{
	cout << "type: " << m_type << endl;
	cout << "className: " << m_className << endl;
	cout << "displayName: " << m_displayName << endl;
	cout << "min: " << m_min << endl;
	cout << "max: " << m_max << endl;
	cout << "current val: " << m_curr_val << endl;
	cout << "units: " << m_units << endl;
	cout << "unit abbrev: " << m_unitAbbrev << endl;
	cout << endl;
	cout << endl;
}

void Sensor::setDisplayStatus(bool status)
{
	displayStatus = status;
}

bool Sensor::getDisplayStatus()
{
	return displayStatus;
}


char* Sensor::getSensorUnitType()
{
	return m_type;
}

void Sensor::setCurrentValue(double currentValue)
{
	m_curr_val = currentValue;
}



