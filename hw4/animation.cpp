//  Chen Jin
//  PIC10A hw4
//  2018/4/30
//  The program is an animation of sun rise near a house. The sun moves from startpoint to endpoint upon input from user clicks.


//#include "ccc_x11.h"
//#include "ccc_shap.h"
#include "ccc_win.h"
#include <time.h>
#include <cmath>

void pause(int x)
{
	clock_t goal = x + clock();
	while (goal > clock());
}

//the function draws the sun with 8 lines representing emmited light
void draw_sun(Point center, double scale)
{
	double radius = 3 * scale;
	double short_scale;
	double short_radius;
	short_scale = scale / sqrt(2);
	short_radius = radius / sqrt(2);

	Point p11 = center;
	p11.move(0, radius);
	Point p12 = p11;
	p12.move(0, scale);

	Point p31 = center;
	p31.move(radius, 0);
	Point p32 = p31;
	p32.move(scale, 0);

	Point p51 = center;
	p51.move(0, -radius);
	Point p52 = p51;
	p52.move(0, -scale);

	Point p71 = center;
	p71.move(-radius, 0);
	Point p72 = p71;
	p72.move(-scale, 0);


	Point p21 = center;
	p21.move(short_radius, short_radius);
	Point p22 = p21;
	p22.move(short_scale, short_scale);

	Point p41 = center;
	p41.move(short_radius, -short_radius);
	Point p42 = p41;
	p42.move(short_scale, -short_scale);

	Point p61 = center;
	p61.move(-short_radius, -short_radius);
	Point p62 = p61;
	p62.move(-short_scale, -short_scale);

	Point p81 = center;
	p81.move(-short_radius, short_radius);
	Point p82 = p81;
	p82.move(-short_scale, short_scale);


	Circle sun(center, radius);
	Line l1(p11, p12);
	Line l2(p21, p22);
	Line l3(p31, p32);
	Line l4(p41, p42);
	Line l5(p51, p52);
	Line l6(p61, p62);
	Line l7(p71, p72);
	Line l8(p81, p82);

	cwin << sun << l1 << l2 << l3 << l4 << l5 << l6 << l7 << l8;
	return;

}

//the function draws a stationary house and the earth horizon
void draw_house()
{

	//wall&roof
	Point h1(0, 0);
	Point h2(0, 4);
	Point h3(5, 4);
	Point h4(5, 0);
	Point h5(2.5, 6);

	//door
	Point d1(3, 0);
	Point d2(3, 2);
	Point d3(3.8, 2);
	Point d4(3.8, 0);

	//chimney
	Point c1(1, 4.8);
	Point c2(1, 6);
	Point c3(1.5, 6);
	Point c4(1.5, 5.2);

	//earth horizon
	cwin << Line(Point(-10, 0), Point(20, 0));

	cwin << Line(h1, h2) << Line(h2, h3) << Line(h3, h4) << Line(h2, h5) << Line(h3, h5);
	cwin << Line(d1, d2) << Line(d2, d3) << Line(d3, d4);
	cwin << Line(c1, c2) << Line(c2, c3) << Line(c3, c4);
	return;

}

int ccc_win_main()
{
	double scale = 0.2;
	double count = 40;
	double d_scale = 0.01;

	cwin.coord(30, 30, -30, -30);

	draw_house();
	Point P = cwin.get_mouse("Click startpoint (on the earth horizon)");
	Point Q = cwin.get_mouse("Click endpoint \n better to be higher than the startpoint");

	double p_xcoord = P.get_x();
	double p_ycoord = P.get_y();
	double q_xcoord = Q.get_x();
	double q_ycoord = Q.get_y();
	double dx = (q_xcoord - p_xcoord) / count;
	double dy = (q_ycoord - p_ycoord) / count;

	//countinuously draw the sun and erase it to achieve the animation
	for (int i = 0; i < count; i++)
	{
		draw_sun(P, scale);
		draw_house();
		pause(100);
		cwin.clear();
		P.move(dx, dy);
		scale += d_scale;
	}


	return 0;
}

