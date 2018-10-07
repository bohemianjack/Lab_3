// Chapter 7 - Programming Challenge 5, Population
// This program calculates birth and death rates using
// a Population class.
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cctype>
#include <algorithm>

using namespace std;


bool integerAndDataTypeValid(int, string);
bool validTownName(const string &);

class Pop
{
  private:
	long population;   // Current population
	int   numBirths,   // Annual number of births
	      numDeaths;   // Annual number of deaths
	string townName;   // City name variable
  
  public:
	// Constructors
   Pop();                       
   Pop(long, int, int, string);
   
	// Mutators (i.e. "set" functions)
   void setPopulation(long p);  
   void setBirths(int b);
   void setDeaths(int d);
   void setTownName(string);

  	// Accessors
   long getPopulation()         // getPopulation is not required by specs
      { return population; }    
	double getBirthRate() 
      { return double (numBirths) / population; }
	double getDeathRate() 
      { return double (numDeaths) / population; }
    string getTownName()
      { return townName; }
};

/********************************************************
 *                     Pop::Pop                         *
 * Population class default constructor                 *
 ********************************************************/ 
Pop::Pop()
{
	population = 2;
	numBirths  = 0;
	numDeaths  = 0;

}

/********************************************************
 *                      Pop::Pop                        *
 * Population class constructor with 4 parameters       *
 ********************************************************/ 
Pop::Pop(long p, int b, int d, string s)
{
	setPopulation(p);
	setBirths(b);
	setDeaths(d);
	setTownName(s);
}

/********************************************************
 *                Pop::setPopulation                    *
 * Validates and sets the population.                   *
 ********************************************************/ 
void Pop::setPopulation(long p)
{
	if (p >= 2)
		population = p;
	else
		population = 2;       // Default value
}

/********************************************************
 *                    Pop::setBirths                    *
 * Validates and sets the annual number of births.      *
 ********************************************************/ 
void Pop::setBirths(int b)
{
	if (b >= 0)
		numBirths = b;
	else
		numBirths = 0;        // Default value
}

/********************************************************
 *                    Pop::setDeaths                    *
 * Validates and sets the annual number of deaths.      *
 ********************************************************/ 
void Pop::setDeaths(int d)
{
	if (d >= 0)
		numDeaths = d;
	else
		numDeaths = 0;        // Default value
}

/********************************************************
* 					Pop::setTownName                    *
*	Sets the town name as long as it's passed through   *
*   bool function validTownName                         *
********************************************************/
void Pop::setTownName(string s)
	{ townName = s; }

//*********************** main ****************************
int main()
{
	     Pop myTown;             // instantiate one Pop object
	 long numPeople;
	 int  numBirths,
		  numDeaths;
	string townName;

	//City Name
	do{
		cout << "Enter town name: ";
		getline(cin, townName);
	}while(!validTownName(townName));
	myTown.setTownName(townName);
	
	//Total Population
	do{
		cout << "Enter total population: ";
		cin  >> numPeople;
	}while(!integerAndDataTypeValid(numPeople,"Population"));
	myTown.setPopulation(numPeople);  
	
	//Number of births
	do{
		cout << "Enter annual number of births: ";
		cin  >> numBirths;
	}while(!integerAndDataTypeValid(numBirths, "Birthrate"));
	myTown.setBirths(numBirths);  
  
    //Number of deaths
	do{
		cout << "Enter annual number of deaths: ";
		cin  >> numDeaths;
	}while(!integerAndDataTypeValid(numDeaths, "Deathrate"));
	myTown.setDeaths(numDeaths);  
	
	// Display statistics for myTown
	cout << "\nPopulation Statistics for " << myTown.getTownName() << "\n";         
	cout << fixed << showpoint  << setprecision(4);
	cout << "\n\tPopulation:  " << setw(7) << myTown.getPopulation();
	cout << "\n\tBirth Rate:  " << setw(7) << myTown.getBirthRate();
	cout << "\n\tDeath Rate:  " << setw(7) << myTown.getDeathRate() << endl;

	return 0;
}


bool integerAndDataTypeValid(int number, string dataName)
{
	while (number <= 0 || (cin.fail() || cin.peek() != '\n') ) 
	{	
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
		cout << "\n\t\t***Error***\n"
			 << dataName << " must be greater or equal to zero\n"
			 << "or a whole number. Please re-enter.\n\n";
		return false;
	}
	return true; 		
}

bool validTownName(const string &townName)
{
	for(char character : townName)
	{
		if( (!(isalpha(character) || isspace(character) || character == '.' || character == '\''))) 
		{
			cout << "\n\t\t***Error***\n"
			<< "Improper character in the name \"" << townName << "\". Please re-enter.\n";
			return false;
		}
	}
	return true;
}
