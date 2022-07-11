#include "OilWell.h"

OilWell::OilWell(char* wellID, char* wellOptr, int sensorCount, OilFieldDataParser* sensorParser)
{
	sensorList = new SensorList(sensorParser);
	displayStatus = false;
	strcpy(m_wellID, wellID);
	strcpy(m_wellOptr, wellOptr);
	m_sensorCount = sensorCount;
}

OilWell::OilWell()
{
	sensorList = new SensorList();
	displayStatus = false;
	strcpy(m_wellID, NULL);
	strcpy(m_wellOptr, NULL);
	m_sensorCount = 0;

}

OilWell::OilWell(char* id, char* optr, int sensorCount)
{
	strcpy(m_wellID, id);
	strcpy(m_wellOptr, optr);
	m_sensorCount = sensorCount;
}

char* OilWell::getWellId()
{
	return m_wellID;
}

void OilWell::setWellId(char* id)
{
	strcpy(m_wellID, id);
}

void OilWell::setDisplayValue(bool status)
{
	displayStatus = status;
}

bool OilWell::getDisplayValue()
{
	return displayStatus;
}

char* OilWell::getOptrName()
{
	return m_wellOptr;
}

SensorList* OilWell::getSensorList()
{
	return sensorList;
}

int OilWell::getSensorCount()
{
	return m_sensorCount;
}






