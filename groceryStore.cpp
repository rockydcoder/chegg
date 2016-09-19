#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
 
void productSort (vector <string>);
 
 
class GrItem
{
    
private:
    
    // Member variables
    ifstream inFile;
 
    string name, y, no, type, line, status1, status2;
    int q, quantity;
    double p, price, regularPrice, salePrice, finalPrice, t, totalCost, r;
    double rawPrice = 0;
    enum tax {ALCOHOL=8,FOOD=5,GENERAL_MERCHANDISE=7,MEDICINE=4};
    tax rate;
    bool sale, fileStatus;
    
public:
    
    //Constructs a new empty grocery list?
    
    GrItem(ifstream iF )
    {
        inFile = iF;
    }
    
    
    // Prompts user for item order details
    
    void inputGrocery ()
    {
        cout << "Enter the grocery item you have purchased: ";
        cin >> name;
        
        cout << "Enter the individual cost of the item: ";
        cin >> price;
        
        cout << "Enter the quantity of the items: ";
        cin >> quantity;
        
        
    }
    
    
    // returns name
    
    string getName ()
    {
        return name;
    }
    
    void onSale (string yogurt, string tequila, string shampoo, string ibuprofen, string soda, string apples)
    {
        if (name == yogurt || name == tequila || name == shampoo || name == ibuprofen || name == soda || name == apples)
        {
            sale = true;
        }
        else
        {
            sale = false;
        }
    }
    
    bool setSale ()
    
    {
        return sale;
    }
    
    string getSale ()
    {
        if (sale == true)
        {
            y = "Yes";
            return y;
        }
        else
        {
            no = "No";
            return no;
        }
    }
    
    
    
    // Return quantity
    
    int getQuantity()
    {
        return quantity;
    }
    
    
    
    //Return individual cost
    
    
    double getIndCost()
    {
        return price;
    }
    
    
    
    //Returns the total cost of this item in its given quantity.
    
    double getRawCost()
    {
        rawPrice = price * quantity;
        return rawPrice;
    }
    
    
    //Adds the given item order to this list.
    size_t pos;
    
    void add()
    {
        while(inFile.good())
        {
            int num;
            pos=line.find(name);  // search
            inFile >> num;
            
            if(pos!=string::npos) // string::npos is returned if string is not found
            {
                vector <string> list;
                list.push_back(name);
                // inputGrocery();
                
            }
            else
            {
                cout << "Item not found in file. Please enter another." << endl;
                // inputGrocery();
            }
        }
    }
    /* getRate
     
     - convert double r to tax object rate
     
     - assign rate to grocery item
     
     */
    
    
    // calculates cost after tax
    
    double getFinalCost ()
    {
        finalPrice = rawPrice + (rawPrice * (r/100));
        return finalPrice;
    }
    
    // calculates total tax for item of one category
    double calcTax ()
    {
        t = finalPrice - rawPrice;
        return t;
    }
    
    
    void productSort (vector <string> list)
    {
        sort(list.begin(), list.end());
    }
    
    
    
    void displayReceipt ()
    {
        cout << "Name of item:      " << getName() << endl;
        cout << "Quantity of item:  " << getQuantity() << endl;
        cout << "Individual price:  $" << getIndCost() << endl;
        cout << "On-sale or not:    " << getSale() << endl;
        cout << "Total before tax:  $" << getRawCost() << endl;
        // cout << "Total tax:         $" << getRate() << endl;
        cout << "Total after tax:   $" << getFinalCost() << endl;
        // cout << "Total spent today: $" << getTotal () << endl;
        
        
    }  
    
};
 
 
void displayReceipt (GrItem obj2);
void productSort (vector <string> list);
 
 
int main()
{
    GrItem item1;
    ifstream inFile;
    string filename;
    
    cout << "Please enter a file name: " << endl;
    
    cin >> filename;
    
    inFile.open(filename);
    
    while (inFile.eof() == false)
    {
  
    item1.inputGrocery();
    item1.add();
    
    }
 
    inFile.close();
    item1.displayReceipt();
  
    
    
 
    
    
    return 0;
}