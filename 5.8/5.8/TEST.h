#pragma once
#include <iostream>
using namespace std;

class Data
{
	//����Ҳ����д
public:
	Data(int year = 1, int month = 1, int day = 1)//���캯��Ҫд���������캯������д����ֵ���ز���д
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
	Data operator++();//ǰ��++
	Data operator++(int);//����++
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
