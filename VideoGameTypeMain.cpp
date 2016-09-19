//VideoGameTypeMain.cpp
//This program will output a list of video games using a class, array, and various functions
#include "VideoGameType.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//All function prototypes
void printGames(VideoGame print());
void highestPrice(VideoGame videoGame[10]);
void lowestPrice(VideoGame videoGame[10]);
void oldestGame(VideoGame videoGame[10]);
void youngestGame(VideoGame videoGame[10]);
int main(){
   VideoGame p;
   VideoGame videoGame[10];
   //int answer;
   /*cout << "Please choose an option below:" << endl;
   cout << "1) Print all listed video games" << endl;
   cout << "2) Output the highest priced game" << endl;
   cout << "3) Output the lowest priced game" << endl;
   cout << "4) Output the oldest game" << endl;
   cout << "5) Output the youngest game" << endl;
   cout << "6) Quit program" << endl;
   cin >> answer;
   do{
       if (answer == 1){
           VideoGame::print();
       }
       else if (answer == 2){
           highestPrice(videoGame);
       }
       else if (answer == 3){
           lowestPrice(videoGame);
       }
       else if (answer == 4){
           oldestGame(videoGame);
       }
       else if (answer == 5){
           youngestGame(videoGame);
       }
       else if (answer == 6){
           cout << "Quitting program..." << endl;
       }
       cout << "Please choose an option below:" << endl;
       cout << "1) Print all listed video games" << endl;
       cout << "2) Output the highest priced game" << endl;
       cout << "3) Output the lowest priced game" << endl;
       cout << "4) Output the oldest game" << endl;
       cout << "5) Output the youngest game" << endl;
       cout << "6) Quit program" << endl;
       cin >> answer;
   } while (answer != 6);*/
   p.print();
  
   system("pause");
   return 0;
}

//Function defintions
void printGames(VideoGame p){
   p.print();
}
void highestPrice(VideoGame gameArray[]){
   string max;
   int maxIndex;
   int i;
   max = gameArray[0].getPrice();
   for (int i = 0; i < 10; i++)
   {
       if (max <= (gameArray[i].getPrice()))
       {
           max = gameArray[i].getPrice();
           maxIndex = i;
       }
   }
   cout << "The game with the highest price is " << gameArray[maxIndex].getGenre() << endl;
}