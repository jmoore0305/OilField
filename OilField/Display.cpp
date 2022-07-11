#include "Display.h"


Display::Display()
{
    id = "";
    sensorType = "";
    ans = "";
    num = 0;
    selection = 0;
    over = false;
    doneEnteringSensors = false;
}

void Display::wellMenuDisplay(OilWellList* theWellList)
{
    bool found = false;

    do
    {
        cout << endl;

        theWellList->displayWellNamesAndIDs();

        cout << "Enter the Well ID corresponding to the well you'd like displayed e.g. 12-1234 ... Include the dash." << endl;
        cin >> id;
        cout << endl;

        found = theWellList->searchOilWellList(id);

        if (found)
            cout << "Success! Your well selection has been added to the list... " << endl << endl;
        else
            cout << "Well not found, please try again... " << endl << endl;


        cout << "Are you done selecting well? Press 5 to end and any other key to continue..." << endl;
        cin >> ans;

        if (ans == "5")
            over = true;

    } while (!over);
   
    
    sensorMenuDisplay(theWellList);
}


void Display::sensorMenuDisplay(OilWellList* theWellList)
{

    vector<OilWell*> list = theWellList->getList();

    for (int i = 0; i < list.size(); i++)
    {
        OilWell* well = list.at(i);

        cout << endl << endl;

        if (well->getDisplayValue() == true)
        {
            cout << "name: " << well->getOptrName() << endl;
            cout << "id: " << well->getWellId() << endl;
            cout << "sensor count: " << well->getSensorCount() << endl;
            displaySensors(well);
        }
        cout << endl << endl;
    }
}


void Display::displaySensors(OilWell* well)
{
    bool finished = false;

    bool found = false;

    string reply = " ";

    string sensorSelection = " ";


    SensorList* sensorList = well->getSensorList();

    sensorList->loadSensorTypeList();


    do
    {
        sensorList->displaySensorType();

        cout << "Enter your selection for the sensor types you want." << endl;
        cout << "Please type in the full name with the underscore all capital letters and then hit enter." << endl;

        cin >> sensorSelection;

        found = sensorList->searchSensorList(sensorSelection);

        cout << endl;

        if (found)
            cout << "Success! Your sensor will be added to the list and displayed when finished." << endl;
        else
            cout << "Entry not found, please try again" << endl;

        cout << endl;
        cout << "Would you like to enter another sensor type to be displayed?" << endl;
        cout << "Press 9 to exit and any other key to enter another sensor." << endl;

        cin >> reply;

        if (reply == "9")
            finished = true;

    } while (!finished);


}

void Display::reportDisplay(OilWellList* theWellList)
{
    displayActivelySelectedWellData(theWellList);
}

void Display::addWellMenuDisplay(OilWellList* theWellList)
{
    char* theId = new char[70];
    char* optrName = new char[70];
    int sensorCnt = 0;
    bool happy = false;
    char resp = ' ';

    do
    {
        cout << "Please enter in the well's id in the form nn-nnn with the dash..." << endl;
        cin >> theId;

        cout << "Please enter in the well's operator or company name..." << endl;
        cin >> optrName;

        cout << "Please enter in the well's total number of sensors..." << endl;
        cin >> sensorCnt;


        cout << endl;

        cout << "Please review the data you have entered for the well is displayed below..." << endl;

        cout << endl;

        cout << "The id you entered for the well is... " << theId << endl;

        cout << "The operator or company name you entered for the well is... " << optrName << endl;

        cout << "The total number of sensors you entered for the well is... " << sensorCnt << endl;

        cout << endl;

        cout << "Are you happy with the data entered for your well?" << endl;
        cout << "Enter 1 for yes and any other key for no..." << endl;
        cin >> resp;

        if (resp == '1')
            happy = true;

    } while (!happy);

    cout << endl;

    OilWell* theWell = new OilWell(theId, optrName, sensorCnt);

    bool success = theWellList->addWell(theWell);

    if (success)
    {
        cout << "Adding newly created well to the list..." << endl;
        theWellList->loadWellIDs();
        theWellList->loadWellNames();
    }
    else
        cout << "Failed to add Oil well to list. Please try again..." << endl;

}

void Display::displayActivelySelectedWellData(OilWellList* theWellList)
{
    vector<OilWell*> list = theWellList->getList();

    for (int i = 0; i < list.size(); i++)
    {
        OilWell* well = list.at(i);

        if (well->getDisplayValue() == true)
        {
            cout << "name: " << well->getOptrName() << endl;
            cout << "id: " << well->getWellId() << endl;
            displayActivelySelectedSensorData(well);
        }
        cout << endl << endl;
    }
}

void Display::displayActivelySelectedSensorData(OilWell* theWell)
{
    SensorList* theSensorList = theWell->getSensorList();
    vector<Sensor*> list = theSensorList->getList();

    for (int i = 0; i < list.size(); i++)
    {
        Sensor* sensor = list.at(i);

        if (sensor->getDisplayStatus() == true)
        {
            sensor->displayValues();
        }
    }
}











