// OOP244 Workshop 3: Dynamic Memory
// File	w3_in_lab.cpp
// Version 1.0
// Date	01/02/2016
// Description
// This file is used to demonstrate dynamic memory in 
// C++ and to process an array of objects of compound 
// type where the user specifies the number of 
// elements in the array at run-time.
/////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Weather.h"
using namespace std;
using namespace sict;

double findLow(const char* date, const Weather *data, int dataSize);

int main(){
  int i; //  loop counter
  int n; //the count of days worth of weather
  // initialize the weather pointer here


  Weather* weather;



	// to delete memory  delete[] ptr;
	// ptr = nullptr	
	// to display use  ptr [i].display()

  cout << "Weather Data" << endl
    << "=====================" << endl
    << "Days of Weather: ";
  cin >> n;
  cin.ignore();

  // allocate dynamic memory here

	 weather = new Weather[n];


  for (i = 0; i < n; i++){
    char date_description[7];
    double high;
    double low;

	

    // ... add code to accept the user input
    // for the weather array

		cout << "Enter date: ";
		cin >> date_description;
		cout << "Enter high: ";
		cin >> high;
		cout << "Enter low : ";
		cin >> low;
	weather[i].set(date_description, high, low);

  }


  cout << endl
    << "Weather report:" << endl
    << "Date        high  low" << endl
    << "======================" << endl;


  for (i = 0; i < n; i++){
    weather[i].display();

  }
  
  char query[7];


  cout << endl << "Enter the date you are looking for: ";
  cin >> query[7];
  //accept user input for the date to find
  //(in this example stored in char query[7])
  // and display the found low temprature.


  cin.getline(query, 8, '\n');



  double low = findLow(query, weather, n);
  cout << "Low temperature: " << low << endl;





  // deallocate dynamic memory here

  delete[] weather;
  weather = nullptr;
}



	double findLow(const char* date, const Weather *data, int dataSize) {

		int i = 0;
		bool dataCheck;
		double dataConfirm;

		for (i = 0; i < dataSize; i++) {
			dataCheck = strcmp(date, data[i].date());
			if (dataCheck) {
				dataConfirm = data[i].low();
			}
			}
		return dataConfirm;
}