//  Chen Jin
//  PIC10A extra hw
//  2018/6/9
//  The program rotates a n*m matrix by n steps in counterclockwise direction in each loops.

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_ROWS=300;
const int MAX_COLS=300;


void fill_matrix(int a[MAX_ROWS][MAX_COLS], int m, int n)
{
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            a[i][j]=rand()%20;
}



void test_solution(int a[MAX_ROWS][MAX_COLS], int m, int n)
{
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<setw(3)<<a[i][j];
        }
        cout<<endl;
    }
}




//extract each loop to a vector, rotate and put it back to the array
void getloop(int ar[MAX_ROWS][MAX_COLS], int rows, int cols, int rotate_by, int x)
{
    vector<int> v;
    vector<int> m;
    //extract top row
    for(int c=0+x;c<cols-1-x;c++)
    {
        v.push_back(ar[0+x][c]);
    }
    //extract right column
    for(int r=0+x;r<rows-1-x;r++)
    {
        v.push_back(ar[r][cols-1-x]);
    }
    //extract bottom row
    for(int c=cols-1-x;c>(0+x);c--)
    {
        v.push_back(ar[rows-1-x][c]);
    }
    //extract left row
    for(int r=rows-1-x;r>(0+x);r--)
    {
        v.push_back(ar[r][0+x]);
    }
    
    vector<int> v;
    vector<double> m;
    //extract top row
    for (int c=x;c<cols-1-x;c++)
    
    
    //rotate
    for(int i=0;i<v.size();i++)
    {
        int pos=i+rotate_by;
        pos=pos%v.size();
        m.push_back(v[pos]);
    }
    
 
    
    
    //put back left row
    for(int r=1+x;r<rows-x;r++)
    {
        ar[r][0+x]=m[m.size()-1];
        m.pop_back();
    }
    //put back bottom row
    for(int c=1+x;c<cols-x;c++)
    {
        ar[rows-1-x][c]=m[m.size()-1];
        m.pop_back();
    }
    //put back right column
    for(int r=rows-2-x;r>-1+x;r--)
    {
        ar[r][cols-1-x]=m[m.size()-1];
        m.pop_back();
    }
    //put back top row
    for(int c=cols-2-x;c>-1+x;c--)
    {
        ar[0+x][c]=m[m.size()-1];
        m.pop_back();
    }
}

//repeat the getloop function for each loop
void rotate_matrix(int ar[MAX_ROWS][MAX_COLS], int rows, int cols, int rotate_by)
{
    
    if (rows<=cols)
    {
        for (int i=0;i<rows/2;i++)
            getloop(ar, rows, cols, rotate_by,i);
    }
    else
    {
        for (int i=0;i<cols/2;i++)
            getloop(ar, rows, cols, rotate_by,i);
    }
}



int main()
{
    int rows;
    int cols;
    int rotate_by;
    cout << "Please enter the number of rows: ";
    cin >> rows;
    cout << "Please enter the number of cols: ";
    cin >> cols;
    cout << "Please enter the number to rotate by: ";
    cin >> rotate_by;
    int ar[MAX_ROWS][MAX_COLS]; // MAX_ROWS and MAX_COLS are global constants 300 each
    
    fill_matrix(ar, rows, cols);
    test_solution(ar, rows, cols);cout<<endl;
    rotate_matrix(ar, rows, cols, rotate_by); // THIS IS THE FUNCTION YOU WRITE
    test_solution(ar, rows, cols);
    return 0;
}
