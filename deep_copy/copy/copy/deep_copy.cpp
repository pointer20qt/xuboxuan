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
	people(const people & p)//�������캯�� �������  ǳ����ֻ�Զ����е����ݳ�Ա���м򵥵ĸ�ֵ
	{
		cout << "�������캯��" << endl;
		this->age = p.age;
		this->name = new char[20];//���
		strcpy(this->name, p.name);
	}
	void show()
	{
		cout << this->name << endl;
	}
	~people()
	{
		cout << "��������" << endl;
		delete name;
	}
};
int main()
{
	people p(12, "xbx");
	people p1 = p;
	p.show();
	p1.show();
	cout << "������" << endl;
	return 0;
}
