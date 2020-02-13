#include <iostream>
using namespace std;

class Shape{
public:
	virtual void shapeName() = 0;//´¿Ðéº¯Êý
};

class Point :public Shape{
public:

	virtual void shapeName(){
		cout << "Point:";
	}
};

class Circle :public Point
{
public:
	virtual void shapeName(){
		cout << "Circle:";
	}
};
int main()
{
	Shape* pt=new Point; 
	Shape* ci = new Circle;
	Point* p = new Point;
	Point* c = new Circle;
	pt->shapeName();
	cout << endl;
	ci->shapeName();
	cout << endl;
	p->shapeName();
	cout << endl;
	c->shapeName();
	return 0;
}
