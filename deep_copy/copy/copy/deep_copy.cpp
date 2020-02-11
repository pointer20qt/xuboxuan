#include<iostream>
#include<string>
using namespace std;

class people
{
	int age;
	char *name;
public:
	people(int age,char *name)
	{
		this->age = age;
		this->name = new char[20];
		strcpy(this->name, name);
	}
	people(const people & p)//拷贝构造函数 深拷贝（）  浅拷贝只对对象中的数据成员进行简单的赋值
	{
		cout << "拷贝构造函数" << endl;
		this->age = p.age;
		this->name = new char[20];//深拷贝
		strcpy(this->name, p.name);
	}
	void show()
	{
		cout << this->name << endl;
	}
	~people()
	{
		cout << "析构函数" << endl;
		delete name;
	}
};
int main()
{
	people p(12, "xbx");
	people p1 = p;
	p.show();
	p1.show();
	cout << "结束了" << endl;
	return 0;
}
