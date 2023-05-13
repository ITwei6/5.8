#pragma once
#include <iostream>
using namespace std;

class Data
{
	//析构也不用写
public:
	Data(int year = 1, int month = 1, int day = 1)//构造函数要写，拷贝构造函数不用写，赋值重载不用写
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	Data(const Data& d)
	{
	
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	bool operator<(const Data& d);
	bool operator==(const Data& d);
	bool operator<=(const Data& d);
	bool operator>(const Data& d);
	bool operator>=(const Data& d);
	bool operator!=(const Data& d);
	Data operator++();//前置++
	Data operator++(int);//后置++
	int GetMonDay(int year, int month);
	Data& operator+=(int day);
	Data operator+(int day);
	Data& operator-=(int day);
	Data operator-(int day);
	int operator-(Data& d);
private:
	int _year;
	int _month;
	int _day;
};
