// 2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream" 
using namespace std;
class CFeet
{
private:
	int feet;
	int inches;
public:
	CFeet();
	CFeet(int f, int i);
	int setFeet(int f, int i);
	void displayFeet();
	void addOneFeet();
	~CFeet();
	int check();
	CFeet addFeet(CFeet &od);
	CFeet operator +(CFeet &otemp);
	CFeet operator +(const int &d);
};
CFeet::CFeet()
{
	feet = 0;
	inches =0;
}
CFeet::~CFeet()
{
	feet = 0;
	inches = 0;
}
CFeet::CFeet(int f, int i)
{
	feet = f;
	inches = i;
	check();
}
int CFeet::setFeet(int f, int i)
{
	feet = f;
	inches = i;
	check();
	return 0;
}
void CFeet::displayFeet()
{
	cout << "feet=" << feet << "inches=" << inches << endl;
}
void CFeet::addOneFeet()
{
	feet = feet + inches / 12;
	inches = inches % 12;
	if (inches >= 12 && inches % 12==0)
	{
		feet++;
	}
	
}
CFeet CFeet:: operator +(CFeet &otemp)
{
	CFeet temp;
	temp.setFeet(feet + otemp.feet, inches + otemp.inches);
	return temp;
	check();
}
CFeet CFeet:: operator +(const int &d)
{
	CFeet temp;
	temp.setFeet(feet, inches + d);
	return temp;
	check();
}
CFeet CFeet::addFeet(CFeet &od)
{
	CFeet temp;
	temp.setFeet(feet + od.feet, inches + od.inches);
	return temp;
	check();
}
int CFeet::check()
{

	if (inches >= 12 && inches % 12 == 0)
	{
		feet++;
	}
	feet = feet + inches / 12;
	inches = inches % 12;
	return 0;
}
int main()
{
    CFeet od1(7, 10), od2(7, 13), od3;
    od3 = od1.addFeet(od2);
	od1.displayFeet();
	od2.displayFeet();
	od3.displayFeet();
	return 0;
}
