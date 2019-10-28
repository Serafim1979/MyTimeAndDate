#include<iostream>

using std::cout;
using std::cin;
using std::endl;
///////////////////////////////////////////////////
struct MyTime
{
	unsigned short hour;
	unsigned short minute;
	unsigned short second;
	MyTime()
	{
		hour = 0;
		minute = 0;
		second = 0;
	}
};
///////////////////////////////////////////////////
struct MyDate
{
	unsigned short day;
	unsigned short month;
	unsigned short year;
	MyDate()
	{
		day = 0;
		month = 0;
		year = 0;
	}
};
///////////////////////////////////////////////////
bool set(MyTime& mt, unsigned short h, unsigned short m, unsigned short s)
{
	if ((h > 23) || (m > 59) || (s > 59))
		return false;
	mt.hour = h;
	mt.minute = m;
	mt.second = s;
	return true;
}
///////////////////////////////////////////////////
bool set(MyDate& md, unsigned short d, unsigned short m, unsigned short y)
{
	if ((d == 0) || (d > 31) || (m == 0) || (m > 12) || (y < 0))
		return false;
	md.day = d;
	md.month = m;
	md.year = y;
	return true;
}
///////////////////////////////////////////////////
void print(MyTime& mt)
{
	cout << mt.hour << ":" << mt.minute << ":" << mt.second << endl;
}
///////////////////////////////////////////////////
void print(MyDate& md)
{
	cout << md.day << "." << md.month << "." << md.year << endl;
}
///////////////////////////////////////////////////
bool readDate(MyTime& mt)
{
	unsigned short hour, minute, second;
	cout << "Input time:\n";
	cout << "Hour: ";
	cin >> hour;
	cout << "Minute: ";
	cin >> minute;
	cout << "Seconds: ";
	cin >> second;

	if (!set(mt, hour, minute, second))
	{
		cout << "\nWrong date\n";
		return false;
	}
	return true;
}
///////////////////////////////////////////////////
bool readDate(MyDate& md)
{
	unsigned short day, month, year;
	cout << "Input date: \n";
	cout << "Day: ";
	cin >> day;
	cout << "Month: ";
	cin >> month;
	cout << "Year: ";
	cin >> year;

	if (!set(md, day, month, year))
	{
		cout << "\nWrong date\n";
		return false;
	}
	return true;
}
///////////////////////////////////////////////////
int main()
{
	MyTime mt;
	readDate(mt);
	print(mt);

	MyDate md;
	readDate(md);
	print(md);

	system("pause");
	return 0;
}
