//  Chen Jin
//  PIC10A hw1
//  2018/4/8
//  The program converts the input travel_time in seconds into years, days, hours, minutes, and seconds. And it uses input of speed in miles per hour to calculate distance traveled.


#include <iostream>
using namespace std;
int main()
{
    int travel_time;
    int speed;
    
    int years;
    int days;
    int hours;
    int minutes;
    int seconds;
    int left_over;
    
    // Declaring the unit convertion variables
    const int seconds_per_year = 60*60*24*365;
    const int seconds_per_day = 60*60*24;
    const int seconds_per_hour = 60*60;
    const int seconds_per_minute = 60;
    
    double distance;
    
    // Getting input from the user
    cout << "Please give me the time of travel in seconds. ";
    cin >> travel_time;
    cout << "Please give your speed in miles per hour. ";
    cin >> speed;
    
    // Converting travel time into years, days, hours, minutes, and seconds
    years = travel_time / seconds_per_year;
    left_over = travel_time % seconds_per_year;
    days = left_over / seconds_per_day;
    left_over = left_over % seconds_per_day;
    hours = left_over / seconds_per_hour;
    left_over = left_over % seconds_per_hour;
    minutes = left_over / seconds_per_minute;
    seconds = left_over % seconds_per_minute;
    
    // Calculating distance
    distance = (double) speed * travel_time / seconds_per_hour;
    
    cout << "You have been traveling for: " << years << " years " << days << " days " << hours << " hours " << minutes << " minutes " << seconds << " seconds.\n";
    cout << "Your distance traveled is: " << distance << " miles.\n";
    
    system("pause");
    return 0;
}
