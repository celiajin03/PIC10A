
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "phonebook.h"



using namespace std;

int find(const vector<Person> &phone_book, string name);
void swap(Person &p1, Person &p2);


Person::Person()
{
    name="JC";
    phone=1234567;
}

Person::Person(string new_name, int new_phone)
{
    name=new_name;
    phone=new_phone;
}

string Person::get_name() const
{
	return name;
}

int Person::get_phone() const
{
	return phone;
}


bool Person::operator<(Person p) const
{
    if (name<p.get_name())
        return true;
    else return false;
}

void Person::print() const
{
    cout<<name<<"\t"<<phone;
}


void add_people(vector<Person> &phone_book)
{
    string new_name;
    int new_phone;
    bool q=true;
    while (q)
    {
        cout<<"Enter a name or Q to quit:";
        getline(cin,new_name);
        if (new_name=="Q")
            q=false;
        if(q)
        {
            cout<<"Enter the phone number:";
            cin>>new_phone;
            string clear;
            getline(cin, clear);
            phone_book.push_back(Person(new_name, new_phone));
        }
    }
}

int find(const vector<Person> &phone_book, string name)
{
    int i=0;
    while(i<phone_book.size() && phone_book[i].get_name()!=name)
    {
        i++;
    }
    if(i==phone_book.size())
        i=-1;
    return i;
}

void erase(vector<Person> &phone_book, string name)  //-2
{
    int pos=find(phone_book, name);
    if (pos>=0)
    {
        for(int i=pos;i<phone_book.size()-1;i++)
        {
            phone_book[i]=phone_book[i+1];
        }
        phone_book.pop_back();
    }
}

void sort(vector<Person> &phone_book)
{
    sort(phone_book.begin(),phone_book.end());
    print(phone_book);
}

void swap(Person &p1, Person &p2)
{
    Person p=p1;
    p1=p2;
    p2=p;
}

void shuffle(vector<Person> &phone_book)
{
    for(int i=0;i<phone_book.size();i++)
    {
        int slot=rand()%(phone_book.size()-i)+i;
        swap(phone_book[i],phone_book[slot]);
    }
}

void reverse(vector<Person> &phone_book)
{
    vector<Person> pbook1;
    for(int i=phone_book.size()-1;i>=0;i--)
    {
        pbook1.push_back(phone_book[i]);
    }
    phone_book=pbook1;
}

int lookup(const vector<Person> &phone_book, string name)
{
    int pos=find(phone_book, name);
    if(pos>0)
        return phone_book[pos].get_phone();
    else
        return -1;
}

void print(vector<Person> &phone_book)
{
    for(int i=0;i<phone_book.size();i++)
    {
        phone_book[i].print();
        cout<<endl;
    }
}

