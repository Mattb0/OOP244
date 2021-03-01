#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Weather.h"
#include <iomanip>  
using namespace std;
using namespace sict;

namespace sict{

	void Weather::set(const char* dateDesc, double high , double low)
	{
			strcpy(_date, dateDesc);
		    _highTemp = high;
			_lowTemp = low;
	}
	
	void Weather::display() const{

	
		cout << left << setfill('_') << setw(10) << _date;
		


		cout.fill('_');

		cout.precision(1);
		cout << setw(6) << right << fixed << _highTemp;

		 cout.precision(1);
		 cout << setw(6) << right << fixed << _lowTemp << endl;


	}

	double Weather::low() const {
		
		
			return _lowTemp;
	}

	const char* Weather::date() const {



		return _date;
	}
}