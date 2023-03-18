#include "ccc_win.h"
#include <cmath>

class House
{
public:
    House();
    House(int new_housenum, Point new_loc);
    void draw();
    void move(double dx, double dy);
    double get_locx();
    double get_locy();
    double get_num();
private:
    int house_num;
    Point loc;
};

House::House()
{
    house_num=2;
    loc=Point(0,0);
}

House::House(int new_housenum, Point new_loc)
{
    house_num=new_housenum;
    loc=new_loc;
}


void House::draw()
{
    //wall&roof
    Point h1=loc;
    Point h2=loc;
    h2.move(0, 4);
    Point h3=loc;
    h3.move(5, 4);
    Point h4=loc;
    h4.move(5, 0);
    Point h5=loc;
    h5.move(2.5, 6);
    
    //door
    Point d1=loc;
    d1.move(3, 0);
    Point d2=loc;
    d2.move(3, 2);
    Point d3=loc;
    d3.move(3.8, 2);
    Point d4=loc;
    d4.move(3.8, 0);
    
    //chimney
    Point c1=loc;
    c1.move(1, 4.8);
    Point c2=loc;
    c2.move(1, 6);
    Point c3=loc;
    c3.move(1.5, 6);
    Point c4=loc;
    c4.move(1.5, 5.2);
    
    //message
    Point m1=loc;
    m1.move(2, 2);
    cwin<<Message(m1, house_num);
    
    cwin << Line(h1, h2) << Line(h2, h3) << Line(h3, h4) << Line(h1, h4) << Line(h2, h5) << Line(h3, h5);
    cwin << Line(d1, d2) << Line(d2, d3) << Line(d3, d4);
    cwin << Line(c1, c2) << Line(c2, c3) << Line(c3, c4);
}


void House::move(double dx, double dy)
{
    loc.move(dx,dy);
    return;
}


double House::get_locx()
{
    return loc.get_x();
}

double House::get_locy()
{
    return loc.get_y();
}

double House::get_num()
{
    return house_num;
}



class Street
{
public:
    Street(House new_first, House new_last, int num_houses);
    int plot();
private:
    House first;
    House last;
    int num;
};

Street::Street(House new_first, House new_last, int num_houses)
{
    first=new_first;
    last=new_last;
    num=num_houses;
}

int Street::plot()
{
    //double dx=(num_houses);
    return num;
    //double dy=(last.get_locy()-first.get_locy())/(num_houses-1);
    //double dnum=(last.get_num()-first.get_num())/(num_houses-1);
    /*for (int i=0;i<5;i++)
    {
        first.draw();
        first.move(dx,dy);
    }*/
}


int ccc_win_main()
{
    cwin.coord(0, 50, 50, 0);
    Point P = cwin.get_mouse("Click startpoint");
    Point Q = cwin.get_mouse("Click endpoint");
    int fnum = cwin.get_int("Enter number for the first house:");
    int lnum = cwin.get_int("Enter number for the last house:");
    //int num = cwin.get_int("Enter number of houses:");
    House first(fnum,P);
    House last(lnum,Q);
    //first.draw();
    //last.draw();
    Street street(first,last,5);
    cwin<<Message(Point(10,10),street.plot());
    return 0;
}

