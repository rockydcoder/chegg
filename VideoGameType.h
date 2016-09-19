//VideoGameType.h
#ifndef VideoGameType_H
#define VideoGameType_H
#include <string>
using namespace std;
class VideoGame
{
public:
   //Constructors
   VideoGame(); //default constructor
   VideoGame(string nme, string prce, string gnre, string yr); //parameter-based constructor
   //Accessor Methods
   string getName();
   string getPrice();
   string getGenre();
   string getYear();
   //Mutator Methods
   void setName(string newName);
   void setPrice(string newPr(ice);
   void setGenre(string newGenre);
   void setYear(string newYear);
   //Print function
   void print();
private:
   //Private instance variables
   string name;
   string price;
   string genre;
   string year;
};
#endif