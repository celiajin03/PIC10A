//  Chen Jin
//  PIC10A hw2
//  2018/4/17
//  The program reads in and calculates the ratio between two quantities.


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    //Declaring variables
    int fst_number;
    int scd_number;
    string fst_things;
    string scd_things;
    
    string fst_thing;
    string scd_thing;
    
    int col_sepration;
    
    double fst_to_scd_ratio;
    double scd_to_fst_ratio;
    
    cout << "How many in the first category?";
    cin >> fst_number >> fst_things;
    cout << "How many in the second category?";
    cin >> scd_number >> scd_things;
    
    //Calculating seperation space for the first column
    fst_thing = fst_things.substr(0,fst_things.length()-1);
    scd_thing = scd_things.substr(0,scd_things.length()-1);
    col_sepration = (fst_thing+"-to-"+scd_thing+" ratio").length();
    
    
    cout << setw(col_sepration) << fst_things << setw(10) << fst_number << endl;
    cout << setw(col_sepration) << scd_things << setw(10) << scd_number << endl;
    
    //Calculating the ratios to 2 dp.
    cout << fixed;
    cout << setprecision(2);
    fst_to_scd_ratio=(double) fst_number/scd_number;
    scd_to_fst_ratio=(double) scd_number/fst_number;
    
    
    cout << setw(col_sepration) << fst_thing+"-to-"+scd_thing+" ratio" << setw(10) << fst_to_scd_ratio << endl;
    cout << setw(col_sepration) << scd_thing+"-to-"+fst_thing+" ratio" << setw(10) << scd_to_fst_ratio << endl;
    
    
    system("pause");
    return 0;
}
