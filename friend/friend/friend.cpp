#include<iostream>
using namespace std;

class Box{
	double width;
public:
	friend void printWidth(Box box);
	friend class BigBox;

	void setWidth(double wid)
	{
		width = wid;
	}
};
using b = Box;
class BigBox{
public:
	void Print(int width, Box &box)
	{
		// BigBox是Box的友元类，它可以直接访问Box类的任何成员
		box.setWidth(width);
		cout << "盒子的宽度: " << box.width << endl;
	}
};
void printWidth(Box box)
{
	cout << "盒子的宽度: " << box.width << endl;
}
// 程序的主函数
int main()
{
	b box;
	BigBox big;
	// 使用成员函数设置宽度
	box.setWidth(10.0);
	// 使用友元函数输出宽度
	printWidth(box);
	// 使用友元类中的方法设置宽度
	big.Print(20, box);
	return 0;
}