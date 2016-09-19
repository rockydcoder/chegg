#include "AppType.h"
#include <iostream>
#include <fstream>
#include <string>
//Constructors
AppType::AppType() //default constructor
{
	platforms = {"iOS", "Android", "Windows"};
	numberOfPlatforms = 3;
	inAppPurchases = false
}
AppType::AppType(string* pltfrms, int nop, bool in-app, string nme, string prce, string gnre, string yr)
{
	VideoGameType(nme, prce, gnre, yr);
	platforms = new string[nop];
	copy(begin(pltfrms), end(pltfrms), begin(platforms));
	numberOfPlatforms = nop;
	inAppPurchases = in-app;
}
//Accessor function definitions
string* AppType::getPlatforms() 
{
	return platforms;
}
int AppType::getNumPlatforms()
{
	return numberOfPlatforms;
}
bool AppType::getInAppPurchases()
{
	return inAppPurchases;
}
//Mutator function definitions
void AppType::setPlatforms(string[] pltfrms, int nop)
{
	platforms = new string[nop];
	copy(begin(pltfrms), end(pltfrms), begin(platforms));
}
void AppType::setInAppPurchases(bool in-app)
{
	inAppPurchases = in-app;
}
//Print function definition
void AppType::print() 
{
	ifstream infile;
   ofstream outfile;
   infile.open("videoGames.txt");
  
   while (infile && !infile.eof()){ //if not at end of file, continue reading strings
       for (int i = 0; i < 10; i++){
       	string convert;
           infile >> name >> price >> genre >> year >> platforms >> numberOfPlatforms >> inAppPurchases;
           if (inAppPurchases)
           	convert = "Yes";
           else
           	convert = "No";
           cout << "Title: " << name << "\t Price: " << price << "\t Genre: " << genre << "\t Release Date: " << year << 
           "\tPlatforms:" << platforms << "\t Number of Platforms: " << numberOfPlatforms << "\t In-app Purchases: " << convert << endl;
       }
   }

}