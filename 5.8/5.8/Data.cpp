#include "TEST.h"
int main()
{
	Data d1(2023, 4, 26);
	d1 -= -10;
	d1.Print();
	//Data d2 = d1;//注意这里不是赋值重载而是拷贝构造
	//Data d3(2023, 4, 22);
	//cout<< d3 - d1 << endl;
	//cout << d1 - d3 << endl;
	/*d2=d1-10;
	d1 -= -100;
	d1.Print();*/
	//d3 += 100;
	//d3.Print();
	////注意两者的区别
	///*d2 = d1;*///这才是赋值重载
	//d1.Print();
	//d2.Print();
}