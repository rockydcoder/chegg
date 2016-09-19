#include <iostream>
#include <string>
using namespace std;
class AppType: public VideoGameType 
{
public:
	AppType(); //default constructor
	AppType(string* pltfrms, int nop, bool in-app); //parameter-based constructor
	//Accessor Methods
	string* getPlatforms();
	int getNumPlatforms();
	bool getInAppPurchases();
	//Mutator Methods
	void setPlatforms(string[] pltfrms, int nop);
	void setInAppPurchases(bool in-app);
private:
	//Private instance variables
	string platforms[];
	int numberOfPlatforms;
	bool inAppPurchases;
}