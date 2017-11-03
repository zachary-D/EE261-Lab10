//*****************************************************
// Program Distance converts either yards or feet to
// a record of type Distance.
//*****************************************************

#include <iostream>
#include <string>
using namespace std;

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
};

Distance ConvertYards(long yards)		//Create a distance struct from a length in yards
{
	int miles = yards / 1760;
	return Distance(miles, yards - (miles * 1760), 0);
}

Distance ConvertFeet(long feet)			//Create a distance struct from a length in feet
{
	int miles = feet / 5280;
	int yards = (feet - (miles * 5280)) / 3;
	return Distance(miles, yards, feet - (yards * 3));
}

int main()
{
	ConvertFeet(6002).print();
	ConvertYards(5230).print();
	cin.get();
}