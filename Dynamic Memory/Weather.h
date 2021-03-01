/*Weather.h*/
namespace sict {
	class Weather{
		// member variables

		char _date[8];
		double _highTemp;
		double _lowTemp;

	public:
		// member function
		   const char* date() const; // 1st const means whatever you return cant be changed 
			double low() const;
			void set(const char* dateDesc, double high, double low);
			void display() const;

	};
}