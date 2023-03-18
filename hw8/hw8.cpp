//  Chen Jin
//  PIC10A hw8
//  2018/5/31
//  The program implements the matrix addition process. It can create random number matrices or read matrices from a file upon user's request. And it output the result either to the console or to a file.

#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<fstream>
using namespace std;

const int nrows=10;
const int ncols=10;


//fill with random number
void fill_r(int matrix[nrows][ncols], int m, int n)
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            matrix[i][j]=rand()%21-10;
}

//fill from a file
void fill_f(int matrix[nrows][ncols], int m, int n, ifstream &fin)
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
                fin>>matrix[i][j];
}

//matrices addition
void add(int matrix1[nrows][ncols], int matrix2[nrows][ncols], int matrix3[nrows][ncols], int m, int n)
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            matrix3[i][j]=matrix1[i][j]+matrix2[i][j];
}

//output to the console
void print_c(int matrix[nrows][ncols], int m, int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<setw(5)<<matrix[i][j];
        }
        cout<<endl;
    }
}

//output to a file
void print_f(int matrix[nrows][ncols], int m, int n, ofstream &fout)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            fout<<setw(5)<<matrix[i][j];
        }
        fout<<endl;
    }
}


int main()
{
    int nr,nc;
    string ans;
    string filename;
    int matrix1[nrows][ncols];
    int matrix2[nrows][ncols];
    int matrix3[nrows][ncols];
    
    srand((int)time(0));
    
    cout<<"Enter the number of rows";
    cin>>nr;
    cout<<"Enter the number of columns";
    cin>>nc;
    while(nr<1|nr>10|nc<1|nc>10)
    {
        cout<<"Number entered is not valid. (must between 1 and 10)\n";
        cout<<"Enter the number of rows";
        cin>>nr;
        cout<<"Enter the number of columns";
        cin>>nc;
    }
    
    //ask for options to create the matrices
    cout<<"Do you like to fill the matrices from a file or fill them with random values? Enter f/r"<<endl;
    cin>>ans;
    if (ans=="r")
        fill_r(matrix1,nr,nc);
        fill_r(matrix2,nr,nc);
    if (ans=="f")
    {
        cout<<"Enter file name:";
        cin>>filename;
        
        ifstream fin;
        fin.open(filename.c_str());
        fill_f(matrix1,nr,nc,fin);
        fill_f(matrix2,nr,nc,fin);
        fin.close();
    }
    
    
    
    add(matrix1, matrix2, matrix3, nr, nc);
    
    
    //ask for options to output the matrices
    cout<<"Do you want to output to a file or to the console? Enter f/c"<<endl;
    cin>>ans;
    if (ans=="c")
    {
        print_c(matrix1,nr,nc); cout<<endl<<endl;
        print_c(matrix2,nr,nc); cout<<endl<<endl;
        print_c(matrix3,nr,nc);
    }
    if (ans=="f")
    {
        cout<<"Enter file name:";
        cin>>filename;
        
        ofstream fout;
        fout.open(filename.c_str());
        print_f(matrix1,nr,nc,fout); fout<<endl<<endl;
        print_f(matrix2,nr,nc,fout); fout<<endl<<endl;
        print_f(matrix3,nr,nc,fout);
        fout.close();
    }

    return 0;
}
