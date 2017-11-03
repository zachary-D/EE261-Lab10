//*****************************************************
// Program Distance converts either yards or feet to
// a record of type Distance.
//*****************************************************

#include <iostream>
#include <string>
using namespace std;

const int feetPerMile = 5280;
const int yardsPerMile = 1760;
const int feetPerYard = 3;

//Prints the data passed to the arguments in "value unit" form, adding an 's' after the unit to pluralize it, if applicable
void printValue(string unit, int value)
{
	cout << value << " " << unit << (value == 1 ? "" : "s");
}

//Prints the value in feet 'value', using feet or foot based on the value being displayed
void printFeet(int value)
{
	cout << value << " " << (value == 1 ? "foot" : "feet");
}

struct Distance
{
	Distance::Distance() {}	//Constructs an empty struct

	//Constructs a distance struct with the values passed.  Does not do any input validation.
	Distance::Distance(int _miles, int _yards, int _feet)
	{
		miles = _miles;
		yards = _yards;
		feet = _feet;
	}

	int  feet;
	int  yards;
	int  miles;

	//Prints the data
	void print()
	{
		cout << "The distance is ";
		printValue("mile", miles);
		cout << ", ";
		printValue("yard", yards);
		cout << ", and ";
		printFeet(feet);
		cout << endl;
	}

	//Returns the speed in MPH if something were to travel the distance in the struct in 'time' (minutes)
	float getMPH(float time)
	{
		float totalMiles = miles + (yards / yardsPerMile) + (feet / feetPerMile);

		return totalMiles / (time / 60.f);
	}
};

Distance ConvertYards(long yards)		//Create a distance struct from a length in yards
{
	int miles = yards / yardsPerMile;
	return Distance(miles, yards - (miles * yardsPerMile), 0);
}

Distance ConvertFeet(long feet)			//Create a distance struct from a length in feet
{
	int miles = feet / feetPerMile;
	int yards = (feet - (miles * feetPerMile)) / feetPerYard;
	return Distance(miles, yards, feet - (yards * feetPerYard) - (miles * feetPerMile));
}

int main()
{
	//Exercise 2 Checks
	ConvertFeet(6002).print();
	ConvertYards(5230).print();

	//Exercise 3
	cout << "Miles per hour traveled: " << Distance(37, 12000, 15000).getMPH(45) << endl;

	cin.get();
}