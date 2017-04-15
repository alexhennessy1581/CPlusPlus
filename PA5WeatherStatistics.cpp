/*************************************************************
Alex Hennessy                                                
CSCI 113 - 01 Programming with C++               
Spring 2017, 04/10/2017                                 
Programming Assignment 5: Weather Statistics
*************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//Declaring variables
const int monthName = 3;
const int amountMonths = 12;

//Structure for the Data
	struct WeatherData
	{
		char month[monthName];
		int high, low;
		double precip;
	};

//Checking and Displaying the Data in File
bool getFileInput (WeatherData*, ifstream*);
void displayData (WeatherData*);
 
int main ()
{
	string fileName = "";
    ifstream file ("");
 
    WeatherData weather[amountMonths];
 
   //Prompts for user input
    while(!file)
    {
		//ask the file name
        cout << "\nPlease enter the filename for the weather data: "
			 << "\nHINT: (don't forget to put .txt)";
		
		//the user's input
        getline(cin, fileName);
   
		//Open's file
        file.open(fileName.c_str());
       
	   //Prints out if there is no file
        if (!file)
		{
            cout << "\n\n\tError! File not found!\n";
		}
		
    }
   
   //Gets data from file
    getline (file, fileName);
   
   //if there is data in file will display
    if(getFileInput(weather, &file))
	{
        displayData(weather);
	}
	
	//if there is no data will print out an error
    else
	{
        cout << "\n\n\tError in the input file!\n";
	}
	
	//closes file
    file.close();
   
    return 0;
}

//---------------------Looking at the Data-------------------------
bool getFileInput (WeatherData *weather, ifstream *file)
{
    for (int data = 0; data < amountMonths; data++)
    {
        if(!(*(file) >> weather[data].month
                     >> weather[data].high
                     >> weather[data].low
                     >> weather[data].precip))
                {
                    // Error return a false
                    return false;
                } 
    } 
	
	//if there is data return true
    return true;
} 

//-----------------For the Display---------------------------------
void displayData (WeatherData *weather)
{
	//Header of the Table
    cout << "\n\n\t-----------------------------------------\n"
         << "\t|" << setw(6) << "Month"
         << " |" << setw(6) << "High"
         << " |" << setw(6) << "Low"
         << " |" << setw(14) << " Precipitation " << "|" 
         << endl;
    cout << "\t-----------------------------------------" << endl;
    
	//Data in the Table
    for (int data = 0; data < amountMonths; data++)
    {
        cout << "\t|" << setw(6) << weather[data].month
             << " |" << setw(6) << weather[data].high 
             << " |" << setw(6) << weather[data].low
             << " | " << setw(13) << weather[data].precip << " |" 
             << endl;
		cout << "\t-----------------------------------------" << endl;
    }
}