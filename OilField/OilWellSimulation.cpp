#define _CRT_SECURE_NO_WARNINGS
#include "OilWellSimulation.h"


OilWellSimulation::OilWellSimulation()
{

    fileName = "OilFieldData.xml";

    parser = new OilFieldDataParser(fileName);

    wellList = new OilWellList(parser);

    wellList->loadWellIDs();
    wellList->loadWellNames();

    display = new Display();

    tStruct = {
        0,
        0,
        0,
        0,
    };

    done = false;  // while loop flag
    hit = 0;     // key hit flag
    ch = ' ';     // character key which was hit
    char response = ' ';

    _ftime(&tStruct);	// Get start time
    thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
    outputTime = thisTime + 5.0; // Set next 5 second interval time

  
	simulationMain();
	
}



void OilWellSimulation::simulationMain()
{

    do
    {
        cout << "Welcome to the oil well sensor monitoring program!" << endl << endl;
        cout << "Press 8 to enter the menu, 4 to add a well manually, and 2 to exit the program" << endl << endl << endl;
        cin >> response;

    } while (response != '8' && response != '4' && response != '2');

    if (response == '8')
        displayMenu();
    else if (response == '4')
    {
        displayAddWellMenu();
        displayMenu();
    }
    else
        exit(1);

    while (!done)     // Start an eternal loop
    {
        _ftime(&tStruct);    // Get the current time
        thisTime = tStruct.time + (((double)(tStruct.millitm)) / 1000.0); // Convert to double
        // Check for 5 second interval to print status to screen
        if (thisTime >= outputTime)
        {
            cout << "Press 8 to enter the menu, 4 to add a well manually, and 2 to exit the program" << endl << endl << endl;
            updateReport(); //call function to update data
            displayReport();     // Call function to print all data
            outputTime += 5.0; // Set time for next 5 second interval
        }
        hit = _kbhit(); //See if a key has been pressed

        if (hit)
        {
            ch = _getch();	// Get the key pressed
            // Now you can check ch to see what key was pressed.
        }

        if (ch == '8')
            displayMenu();

        if (ch == '4')
            displayAddWellMenu();

        if (ch == '2')
            exit(1);

    }


}

void OilWellSimulation::updateReport()
{
    wellList->updateData();
}

void OilWellSimulation::displayAddWellMenu()
{
    cout << endl;
    cout << "Displaying Add Well Screen..." << endl;
    display->addWellMenuDisplay(wellList);
}

void OilWellSimulation::displayMenu()
{
    cout << endl;
    cout << "Displaying Well Menu..." << endl;
    display->wellMenuDisplay(wellList);
}

void OilWellSimulation::displayReport()
{
    cout << endl;
    cout << "Displaying Selected Wells and Sensors... " << endl;
	display->reportDisplay(wellList);
}
