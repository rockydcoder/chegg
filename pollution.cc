#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
double rearation(double V, double S, double H);
void deOxygen(double Kr, double array[], double time[], int numOfTimeIntervals);
int main() {

    // identify variables
    ifstream infile;
    double Do, Lo, S, H, V, Kd, t;
    double Kr;
    double array[6];

    
    //time

    
    // open the data file
    
    infile.open("PollutionData.txt");
    if (infile.fail()) {
        cerr << "did not open " << endl;
        return -1;
    }
    
    if(infile.is_open())
    {
        
        for(int i = 0; i < 6; ++i)
        {
            infile >> array[i];

        }
        Do = array[0];
        Lo = array[1];
        S = array[2];
        H = array[3];
        V = array[4];
        Kd = array[5];


    }
    Kr = rearation(V, S, H);
    double time[501];
    for (double i = 0,  j = 0; i< 501; i++, j+=0.5) {
        time[(int)i] = j;
    }

    deOxygen(Kr, array, time, 501);
    
}

// functions section
// Rearation
double rearation(double V, double S, double H){
    double Kr;
    Kr = (pow((V * S), 0.5)) / (pow(H, 1.5));
    
    return Kr;
}
// oxy
void deOxygen(double Kr, double array[], double time[], int numOfTimeIntervals){
    double D, t;
    ofstream results ("results.txt");
    for (int i = 0; i < numOfTimeIntervals; i++) {
        t = time[i];
        D = ((array[5] * array[1])/(Kr - array[5])) * ((exp(-(array[5] * t))) - (exp(-(Kr * t)))) + (array[0] * exp(-Kr*t));
        results << t << " " << D << endl;

        if (D == array[0])
            cout << "Time at which oxygen deficit returns to initial deficit level is " << t << endl;

    }
    results.close();
    
    
}