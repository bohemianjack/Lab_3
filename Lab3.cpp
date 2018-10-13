// Author:				Jacob Christian
// Assignment Number:   Lab 1
// File Name:			L3_Chrisitan.cpp 
// Course/Section:      COSC 1337 Section 014
// Date:                October 12, 2018
// Instructor:          Dr. Bernard Ku	

#include <iostream> 
#include <iomanip> 
#include <string> 
#include <limits> 
#include <cctype>    // For cin.peek()
#include <algorithm> // For max() function

  using namespace std;

//Function Prototypes
bool integerAndDataTypeValid(int, string);
bool validTownName(const string & );

//Class definition
class Pop {
  private:
    long population; // Current population
  	  int numBirths, // Annual number of births
 		  numDeaths; // Annual number of deaths
  	string townName; // City name variable

  public:
    //Constructor, default set outline                      
    Pop();

  // Mutators (i.e. "set" functions)
  void setPopulation(long p) 
  { population = max(p, 2L); } //Defaut value = 2 
  void setBirths(int b) 
  { numBirths = max(b, 0); }   //Default value = 0
  void setDeaths(int d) 
  { numDeaths = max(d, 0); }   //Default value = 0
  void setTownName(string s) 
  { townName = s; }

  // Accessors
  long getPopulation() // getPopulation is not required by specs
  { return population; }
  double getBirthRate() 
  { return double(numBirths) / population; }
  double getDeathRate() 
  { return double(numDeaths) / population; }
  string getTownName() 
  { return townName; }
  
};

/********************************************************
 *                      Pop::Pop                        *
 * Population class constructor with 4 parameters       *
 * Default parameters set at initialization.            *
 * This is using a member initializer list construct    * 
 ********************************************************/
Pop::Pop(): population(2), numBirths(0), numDeaths(0), townName("City") {};
//*********************** main ****************************
int main() {
  Pop myTown; // instantiate one Pop object
   long numPeople;
    int numBirths,
        numDeaths;
  string townName;

  //City Name
  do {
    cout << "Enter town name: ";
    getline(cin, townName);
  } while (!validTownName(townName));
  myTown.setTownName(townName);

  //Total Population
  do {
    cout << "Enter total population: ";
    cin >> numPeople;
  } while (!integerAndDataTypeValid(numPeople, "Population"));
  myTown.setPopulation(numPeople);

  //Number of births
  do {
    cout << "Enter annual number of births: ";
    cin >> numBirths;
  } while (!integerAndDataTypeValid(numBirths, "Birthrate"));
  myTown.setBirths(numBirths);

  //Number of deaths
  do {
    cout << "Enter annual number of deaths: ";
    cin >> numDeaths;
  } while (!integerAndDataTypeValid(numDeaths, "Deathrate"));
  myTown.setDeaths(numDeaths);

  // Display statistics for myTown
  cout << "\nPopulation Statistics for " << myTown.getTownName() << "\n";
  cout << fixed << showpoint << setprecision(4);
  cout << "\n\tPopulation:  " << setw(7) << myTown.getPopulation();
  cout << "\n\tBirth Rate:  " << setw(7) << myTown.getBirthRate();
  cout << "\n\tDeath Rate:  " << setw(7) << myTown.getDeathRate() << endl;

  return 0;
}

bool integerAndDataTypeValid(int number, string dataName) {
  while (number < 0 || (cin.fail() || cin.peek() != '\n')) {
    cin.clear();
    cin.ignore(numeric_limits < int > ::max(), '\n');
    cout << "\n\t\t***Error***\n" <<
      dataName << " must be greater or equal to zero\n" <<
      "or a whole number. Please re-enter.\n\n";
    return false;
  }
  return true;
}

bool validTownName(const string & townName) {
  for (char character: townName) {
    if ((!(isalpha(character) || isspace(character) || character == '.' || character == '\''))) {
      cout << "\n\t\t***Error***\n" <<
        "Improper character in the name \"" << townName << "\". Please re-enter.\n";
      return false;
    }
  }
  return true;
}
