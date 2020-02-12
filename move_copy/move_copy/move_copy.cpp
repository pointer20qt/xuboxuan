#include<iostream>
#include<vector>
#include<string>

using namespace std;
class principal{
	string name;
public:
	principal(string name)
	{
		this->name = name;
	}
	~principal()
	{
		cout << name << "休息了" << endl;
	}
};
class school
{
public:
	std::string schoolName;
	std::string schoolType;
	std::string address;
	principal *master;
	~school()
	{
		cout << schoolName << "闭校了" << endl;
		delete master;
	}
	school(std::string schoolName, std::string schoolType, std::string address)
	{
		cout << "普通构造函数" << endl;
		this->schoolName = schoolName;
		this->schoolType = schoolType;
		this->address = address;
		master = new principal("杨老师");
	}
	//const 只读 不可以修改
	school(const school & p) :schoolName(p.schoolName), schoolType(p.schoolType), address(p.address)
	{
		//schoolName 先无参构造 再用重载运算符 赋值过去的 
		//schoolName = p.schoolName;
		cout << schoolName << "拷贝建立了" << endl;
		master = new principal(*(p.master));
	}
	//类默认的移动构造 和默认拷贝构造效果一样 默认的拷贝构造是浅拷贝
	school(school && other) :schoolName(other.schoolName), schoolType(other.schoolType), address(other.address)
	{
		cout << "移动构造" << endl;
		master = other.master;
		other.master = NULL;
	}
	void schoolOpens()
	{
		cout << this->schoolName << "开学了" << endl;
	}
};
school getschool()
{
	school s2("东北石油大学", "大学", "大庆");//超出作用域 自动析构
	//return school(s2);//使他返回的时候走拷贝构造
	return s2;//会自动优化 找到一个最合适的方式拷贝
}
int main()
{
	//school s1 = getschool();
	school s1(getschool());
	school s2(std::move(s1));
	cout << "下一句代码" << endl;

}