//  Chen Jin
//  PIC10A hw3
//  2018/4/21
//  This program is a Tic-Tac-Toe game. It records the alternating X's and O's from two players in 9 boxes.


#include "ccc_win.h"

int ccc_win_main()
{
    
    Line L1((0,-5),(0,10));
    Line L2((5,-5),(5,10));
    Line L3((-5,5),(10,5));
    Line L4((-5,0),(10,0));
    cwin << L1 << L2 << L3 << L4;
    
    int count = 1;
    bool lets_play =true;
    
    while (lets_play)
    {
        
        while count <= 9
        {
            if count%2 == 1
            {
                Point P = cwin.get_mouse("Click somewhere\n It is X's turn");
                x_coord = click.get_x(P);
                y_coord = click.get_y(P);
                Line Lx1((x_coord-3,y_coord+3),(x_coord+3,y_coord-3));
                Line Lx2((x_coord-3,y_coord-3),(x_coord+3,y_coord+3));
                cwin << Lx1 <<Lx2;
            }
        
            else
            {
                Point P = cwin.get_mouse("Click somewhere\n It is O's turn");
                x_coord = click.get_x(P);
                y_coord = click.get_y(P);
                Circle C1((x_coord,y_coord), 3);
                cwin << C1;
            }
        
        x++;
        }
            
        text = cwin.get_string("Game Over! \n Would you like to play again? (y/n)\n");
        if (text == "y")
        {
            lets_play=true;
        }
        else
        {
            lets_play=false;
        }
    }

    
    return 0;
}
