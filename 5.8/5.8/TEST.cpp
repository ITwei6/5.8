#include "TEST.h"


bool Data:: operator<(const Data& d)
{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year && _month < d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day < d._day)
		{
			return true;
		}
		return false;
	
}
bool Data::operator==(const Data& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}
bool Data::operator<=(const Data& d)//ֱ�Ӹ��������
{
	return *this < d || *this == d;
}
bool Data::operator>(const Data& d)
{
	return !(*this <= d);
}

bool Data::operator>=(const Data& d)
{
	return !(*this < d);
}
bool Data::operator!=(const Data& d)
{
	return !(*this == d);
}

int Data::GetMonDay(int year, int month)
{
	static int monday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//Ƶ������
	/*if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)&&month==2)*/
	if (month == 2&&(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) )
	{
		return 29;
	}
	else
	return monday[month];
}
//Data& Data::operator+=(int day)//��+����+=-�����ʵ��+= �ٸ���ʵ�� +
//{
//	*this=*this + day;
//	
//	return *this;
//}
Data& Data::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonDay(_year, _month))
	{
		_day -= GetMonDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}
Data Data::operator+(int day)
{
	Data tmp(*this);//����һ�ݣ���tmp���أ�*thisû�иı�
	tmp._day += day;
	while (tmp._day > GetMonDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonDay(tmp._year, tmp._month);
		++tmp._month;
		if (tmp._month == 13)
		{
			++_year;
			tmp._month = 1;
		}
	}
	return tmp;
}
//Data Data::operator+(int day)  //+ ����+=
//{
//	Data tmp(*this);//����һ�ݣ���tmp���أ�*thisû�иı�
//	tmp += day;//����+=���غ��� 
//	return tmp;
//}
Data Data::operator++()//ǰ��++���������
{
	*this += 1;
	return *this;
}
Data Data::operator++(int)//����++���������
{
	Data tmp(*this);
	*this += 1;
	return tmp;
}
Data& Data::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonDay(_year, _month);
	}
	return *this;
}
Data Data::operator-(int day)
{
	Data tmp(*this);
	tmp -= day;
	return tmp;
}
//d1 - d2
int Data::operator-(Data& d)
{
	Data max = *this;
	Data min = d;
	int flag = 1;

	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n*flag;
}