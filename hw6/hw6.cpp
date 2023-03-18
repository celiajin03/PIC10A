#include "ccc_win.h"

//HOUSE CLASS with 4 functions
class House
{
public:
    House();
    House(double new_housenum, Point new_loc);
    void draw();
    void move(double dx, double dy, double num);
    double get_locx();
    double get_locy();
    double get_num();
private:
    double house_num;
    Point loc;
};

House::House()
{
    house_num=2;
    loc=Point(0,0);
}

House::House(double new_housenum, Point new_loc)
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
    cwin<<Message(m1, (int)house_num);
    
    cwin << Line(h1, h2) << Line(h2, h3) << Line(h3, h4) << Line(h1, h4) << Line(h2, h5) << Line(h3, h5);
    cwin << Line(d1, d2) << Line(d2, d3) << Line(d3, d4);
    cwin << Line(c1, c2) << Line(c2, c3) << Line(c3, c4);
}


void House::move(double dx, double dy, double num)
{
    loc.move(dx,dy);
    house_num+=num;
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


//STREET CLASS with a plot function
class Street
{
public:
    Street(House new_first, House new_last, int new_numofhouses);
    void plot(double dx,double dy,double dnum);
private:
    House first;
    House last;
    int num_houses;
};

Street::Street(House new_first, House new_last, int new_numofhouses)
{
    first=new_first;
    last=new_last;
    num_houses=new_numofhouses;
}

void Street::plot(double dx, double dy,double dnum)
{
    first.draw();
    last.draw();
    for (int i=1;i<num_houses;i++)
    {
        first.draw();
        first.move(dx,dy,dnum);
    }
    return;
}


int ccc_win_main()
{
    cwin.coord(0,50,50,0);
    bool yn=true;
    while (yn)
    {
        Point P = cwin.get_mouse("Click startpoint");
        cwin<<P;
        Point Q = cwin.get_mouse("Click endpoint");
        cwin<<Q;
        int fnum = cwin.get_int("Enter number for the first house:");
        int lnum = cwin.get_int("Enter number for the last house:");
        int num = cwin.get_int("Enter number of houses:");
        House first(fnum,P);
        House last(lnum,Q);
        Street street(first,last,num);
        
        double dx=(last.get_locx()-first.get_locx())/(num-1);
        double dy=(last.get_locy()-first.get_locy())/(num-1);
        double dnum=(last.get_num()-first.get_num())/(num-1);
        street.plot(dx,dy,dnum);
        
        if (cwin.get_string("Do you want to draw another house?y/n")== "n")
            yn=false;
        cwin.clear();
    }
    
    return 0;
}



