//VideoGameType.cpp
#include "VideoGameType.h"
#include <iostream>
#include <fstream>
#include <string>
//Constructors
VideoGame::VideoGame() //default constructor
{
   name = "Shadow_the_Hegdehog";
   price = 29.99;
   genre = "Teen";
   year = 2005;
}
VideoGame::VideoGame(string nme, string prce, string gnre, string yr)       //default constructor
{
   name = nme;
   price = prce;
   genre = gnre;
   year = yr;
}
//Accessor function definitions
string VideoGame::getName()
{
   return name;
}
string VideoGame::getPrice()
{
   return price;
}
string VideoGame::getGenre()
{
   return genre;
}
string VideoGame::getYear()
{
   return year;
}
//Mutator function definitions
void VideoGame::setName(string newName)
{
   name = newName;
}
void VideoGame::setPrice(string newPrice)
{
   price = newPrice;
}
void VideoGame::setGenre(string newGenre)
{
   genre = newGenre;
}
void VideoGame::setYear(string newYear)
{
   year = newYear;
}
//Print function definition
void VideoGame::print()
{
   ifstream infile;
   ofstream outfile;
   infile.open("videoGames.txt");
  
   while (infile && !infile.eof()){ //if not at end of file, continue reading strings
       for (int i = 0; i < 10; i++){
           infile >> name >> price >> genre >> year;
           cout << "Title: " << name << "\t Price: " << price << "\t Genre: " << genre << "\t Release Date: " << year << endl;
       }
   }
}