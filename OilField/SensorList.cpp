#include "SensorList.h"



SensorList::SensorList(OilFieldDataParser* sensorParser)
{

	s_moreSensors = true;
	s_min = 0;
	s_max = 0;
	s_sensorCount = 0;


	while (s_moreSensors)
	{

		s_moreSensors = sensorParser->getSensorData(s_wellID, s_type, s_className, s_displayName,
			&s_min, &s_max, s_units, s_unitAbbrev);

		

		if (s_moreSensors)
		{

			sensor = new Sensor(s_wellID, s_type, s_className, s_displayName,
				s_min, s_max, s_units, s_unitAbbrev);

			this->addSensor(sensor);
		}

	}
}


SensorList::SensorList()
{
	sensor = new Sensor();
	s_moreSensors = true;
	s_sensorCount = 0;
	s_min = 0;
	s_max = 0;
	strcpy(s_wellID, NULL);
	strcpy(s_type, NULL);
	strcpy(s_className, NULL);
	strcpy(s_displayName, NULL);
	strcpy(s_units, NULL);
	strcpy(s_unitAbbrev, NULL);
	
}



void SensorList::addSensor(Sensor* sensor)
{
	sensorList.push_back(sensor);
	incrementSensorCount();
}





void SensorList::incrementSensorCount()
{
	s_sensorCount++;
}

int SensorList::getSensorCount()
{
	return sensorList.size();
}

void SensorList::loadSensorTypeList()
{
	for (int i = 0; i < sensorList.size(); i++)
	{
		char* unitType = sensorList.at(i)->getSensorUnitType();
		sensorTypeList.push_back(unitType);
	}
}


void SensorList::displayActivelySelectedSensorData()
{
	for (int i = 0; i < sensorList.size(); i++)
	{
		if (sensorList.at(i)->getDisplayStatus() == true)
		{
			sensorList.at(i)->displayValues();
		}
	}
}

vector<Sensor*> SensorList::getList()
{
	return sensorList;
}

Sensor* SensorList::getSensor(int pos)
{
	return sensorList.at(pos);
}


void SensorList::displaySensorType()
{
	for (int i = 0; i < sensorTypeList.size(); i++)
	{
		cout << "type: " << sensorTypeList.at(i) << endl;
	}
	cout << endl << endl;
}




bool SensorList::searchSensorList(string typeName)
{
	bool found = false; 

	for (int i = 0; i < sensorList.size(); i++)
	{
		char* listTypeName = sensorList.at(i)->getSensorUnitType();

		if (listTypeName == typeName)
		{
			found = true;
			sensorList.at(i)->setDisplayStatus(true);
			break;
		}
	}

	return found;

}



