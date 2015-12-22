#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
class BST_Node  //node in a BST
{
  public:
    string lastname, firstname, address, phone_number;
    BST_Node  *lchild, *rchild;   //left and right children pointers
};
class Clients_Info_BST //Binary Search Tree
{
   public:
            Clients_Info_BST(){};//store the data in the hash table
           //Clients_Info_BST(const Clients_Info_BST &);//Copy Constructor
            ~Clients_Info_BST(){};//Destructor           
           void Insert(const string & s){cout<<"   Inside Client_Info_BST Insert\n";};
           //  void Remove(const string & s){cout<<"   Inside Client_Info_BST Remove\n";};
           //  void Update(const string & s){cout<<"   Inside Client_Info_BST Update\n";};
           //  void Print( ){cout<<"   Inside Client_Info_BST Print\n";};
           //  BST_Node * Search(const string & s){cout<<"   Inside Client_Info_BST Search\n"; return 0;};
            
//other member functions you may need.
    private:
       BST_Node *root; //---state information
       BST_Node cells[27];
};
class Client_Address_Book
{
    public:
            Client_Address_Book(){};//default constructor will read data from input file "client_address_data.txt".
            Client_Address_Book(const Client_Address_Book &);//Copy Constructor
            ~Client_Address_Book();//Destructor
            void Insert(const string & s);// insert record
            // void Remove(const string & s);//remove record
            // void Update(const string & s);//update record
            // void Print_BST(const string & s);//ornt
            // void Print_Hash_Table(){"Inside Client_Address_Book Print_Hash_Table\n";};
            // void Print_Hash_Table_to_File(const string & filename);///function will print hash table to output file                                                                                                                                                                               
            // BST_Node * Search(const string & s){"Inside Client_Address_Book Search\n"; return 0;};
            // unsigned int Hash_Function(const string & s);
     // Hint:  Remember that the insert, remove and search function for Clients_Address_Book will use //     
    //Client_Info_BSTs insert, remove and search respectively.
    
    private:
        int capacity;  //SET THIS VALUE EQUAL TO 27  YOUR DEFAULT CONSTRUCTOR
        Clients_Info_BST   *hash_table; // USING 1 THROUGH 26 or whatever you like
};

Client_Address_Book::Client_Address_Book(void) {
    ios::sync_with_stdio(false);
    vector<string> lines;
    string line;
    capacity = 27;
    ifstream file ("client_address_data.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
    }
    else {
        cout << "Could not open file" << endl;
    }
    for (int i = 0; i < lines.size(); i++) {
        Insert(lines[i]);
    }
}

void Client_Address_Book::Insert(const string & s) {
    hash_table.Insert(*s);
}

void Clients_Info_BST::Insert(const string & s) {
    vector<string> details;
    split(s, ' ', details);
    
}

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

int main()
{
            Client_Address_Book My_Book;
            //My_Book.Insert("Micheal Jackson 123 peak road 207-2780");
            //My_Book.Remove("Micheal Jackson ");
/*******************************************************************************
Notes for Update Function:
     1.  My_Book_Update(1 James Clark Lofton Bullard 777 Glades Run 527-6623);
            If first character is a 1, this means all three fields will be changed.
      2.   My_Book_Update(2 James Clark Lofton Bullard 777 Glades Run);
            If first character is a 2, this means the Name and Address fields will be changed.
      3.   My_Book_Update(3 James Clark 777 Glades Run 555-6666);
            If first character is a 3, this means the Address and Phone Number fields will be changed.
      4.   My_Book_Update(4 James Clark Lofton Bullard 555-6666);
            If first character is a 4, this means the Name and Phone Number fields will be changed.
      5.   My_Book_Update(5 James Clark Lofton Bullard);
            If first character is a 5, this means the Name field will be changed.
      6.   My_Book_Update(6 James Clark 777 Glades Run);
            If first character is a 6, this means the Address field will be changed.
      7.   My_Book_Update(7 James Clark 555-6666);
            If first character is a 7, this means the Phone Number field will be changed.
********************************************************************************/
            //My_Book.Update("1 Micheal Jackson Comb Harry 555 Palmetto Park Road 555-3444");
            //My_Book.Print_BST("B");
            //My_Book.Print_Hash_Table();
            //Client_Address_Book Your_Book = My_Book; //Invoke the copy constructor
            //Your_Book.Print_Hash_Table_to_File(/* the output filename goes here*/);
            return 0;
} 