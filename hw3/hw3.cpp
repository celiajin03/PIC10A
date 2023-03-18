/*
#include "ccc_x11.h"
#include "ccc_shap.h"
*/

#include "ccc_win.h"

int ccc_win_main()
{
    cwin.coord(-20,-20,20,20);
    
    //Setting up variables for 4-line-grid
    Point A(0,-5);
    Point B(0,10);
    Point C(5,-5);
    Point D(5,10);
    Point E(-5,5);
    Point F(10,5);
    Point G(-5,0);
    Point H(10,0);
    
    Line L1(A,B);
    Line L2(C,D);
    Line L3(E,F);
    Line L4(G,H);
    
    
    int count = 1;
    bool lets_play =true;
    string text;
    double x_coord = 0.0;
    double y_coord = 0.0;
    Point origin;
    
    while (lets_play)
    {
        cwin << L1 << L2 << L3 << L4;
        
        //alternating 9 steps between x and o
        while (count <= 9)
        {
            if (count%2 == 1)
            {
                Point click = cwin.get_mouse("Click somewhere \n It is X's turn");
                x_coord = click.get_x();
                y_coord = click.get_y();
                Point P (x_coord-1,y_coord+1);
                Point Q (x_coord+1,y_coord-1);
                Point R (x_coord-1,y_coord-1);
                Point S (x_coord+1,y_coord+1);
                Line Lx1(P,Q);
                Line Lx2(R,S);
                cwin << Lx1 <<Lx2;
            }
            
            else
            {
                Point click = cwin.get_mouse("Click somewhere \n It is O's turn");
                x_coord = click.get_x();
                y_coord = click.get_y();
                Point center(x_coord,y_coord);
                Circle C1(center, 1);
                cwin << C1;
            }
            
            count++;
        }
        
        //ask user whether they want to continue
        text = cwin.get_string("Game Over! \n Would you like to play again? (y/n)\n");
        if (text == "y")
        {
            lets_play=true;
            count = 1;
            cwin.clear();
        }
        else
        {
            lets_play=false;
            cwin.clear();
            Message M(origin,"Thanks for playing!");
            cwin << M;
            
        }
    }
    
    
    return 0;
}

