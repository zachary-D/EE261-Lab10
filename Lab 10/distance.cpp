//*****************************************************
// Program Distance converts either yards or feet to
// a record of type Distance.
//*****************************************************

#include <iostream>
using namespace std;

struct Distance
{
  long  feet;
  long  yards;
  long  miles;
};

Distance ConvertYards(long yards)		//Create a distance struct from a length in yards
{
	Distance val;
	val.yards = yards;
	val.feet = yards * 3;
	val.miles = yards * 3 / 5280;
	return val;
}

Distance ConvertFeet(long feet)			//Create a distance struct from a length in feet
{
	Distance val;
	val.feet = feet;
	val.yards = feet / 3;
	val.miles = feet / 5280;
	return val;
}

void PrintDistance(Distance distance)	//Print the data from a distance struct to the console
{
	cout << "Distance:" << endl;
	cout << "Feet: " << distance.feet << endl;
	cout << "Yards: " << distance.yards << endl;
	cout << "Miles: " << distance.miles << endl;
	cout << endl;
}

int main()
{

}