#include "OilWellList.h"


OilWellList::OilWellList(OilFieldDataParser* parser)
{
    moreWells = true;

    sensorCount = 0;

    while (moreWells)
    {

        moreWells = parser->getWellData(wellID, wellOptr, &sensorCount);
       
        if (moreWells)
        {
            OilWell* well = new OilWell(wellID, wellOptr, sensorCount, parser);
            this->addWell(well);
        }

    }

}


void OilWellList::loadWellIDs()
{
    wellIDList.clear();

    for (int i = 0; i < wellList.size(); i++)
    {
        OilWell* well = wellList.at(i);
        wellIDList.push_back(well->getWellId());
    }
}

void OilWellList::loadWellNames()
{
    wellNamesList.clear();

    for (int i = 0; i < wellList.size(); i++)
    {
        OilWell* well = wellList.at(i);
        wellNamesList.push_back(well->getOptrName());
    }
}

bool OilWellList::searchOilWellList(string id)
{
    bool found = false;

    for (int i = 0; i < wellList.size(); i++)
    {
        OilWell* well = wellList.at(i);

        if (well->getWellId() == id)
        {
            found = true;
            well->setDisplayValue(found);
        }
        else
            well->setDisplayValue(false);
    }

    return found;
}


bool OilWellList::addWell(OilWell* w)
{
    wellList.push_back(w);
    return true;
}


vector<OilWell*> OilWellList::getList()
{
    return wellList;
}

void OilWellList::updateData()
{

    double m_dMinValue = 0;
    double m_dMaxValue = 100;

    srand((unsigned int)(time(NULL)));

    double m_dCurvalue = m_dMinValue + (rand() % (int)(m_dMaxValue - m_dMinValue));


    for (int i = 0; i < wellList.size(); i++)
    {
        OilWell* well = wellList.at(i);

        if (well->getDisplayValue() == true)
        {
            SensorList* sensorList = well->getSensorList();

            for (int i = 0; i < sensorList->getSensorCount(); i++)
            {
                Sensor* sensor = sensorList->getSensor(i);

                if(sensor->getDisplayStatus() == true)
                    sensor->setCurrentValue(m_dCurvalue);
            }

        }
    }
}


void OilWellList::displayWellNamesAndIDs()
{
    for (int i = 0; i < wellIDList.size(); i++)
    {
        cout << "name: " << wellNamesList.at(i) << endl;
        cout << "id: " << wellIDList.at(i) << endl;
        cout << endl;
    }
    cout << endl << endl;

}









