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
		cout << name << "��Ϣ��" << endl;
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
		cout << schoolName << "��У��" << endl;
		delete master;
	}
	school(std::string schoolName, std::string schoolType, std::string address)
	{
		cout << "��ͨ���캯��" << endl;
		this->schoolName = schoolName;
		this->schoolType = schoolType;
		this->address = address;
		master = new principal("����ʦ");
	}
	//const ֻ�� �������޸�
	school(const school & p) :schoolName(p.schoolName), schoolType(p.schoolType), address(p.address)
	{
		//schoolName ���޲ι��� ������������� ��ֵ��ȥ�� 
		//schoolName = p.schoolName;
		cout << schoolName << "����������" << endl;
		master = new principal(*(p.master));
	}
	//��Ĭ�ϵ��ƶ����� ��Ĭ�Ͽ�������Ч��һ�� Ĭ�ϵĿ���������ǳ����
	school(school && other) :schoolName(other.schoolName), schoolType(other.schoolType), address(other.address)
	{
		cout << "�ƶ�����" << endl;
		master = other.master;
		other.master = NULL;
	}
	void schoolOpens()
	{
		cout << this->schoolName << "��ѧ��" << endl;
	}
};
school getschool()
{
	school s2("����ʯ�ʹ�ѧ", "��ѧ", "����");//���������� �Զ�����
	//return school(s2);//ʹ�����ص�ʱ���߿�������
	return s2;//���Զ��Ż� �ҵ�һ������ʵķ�ʽ����
}
int main()
{
	//school s1 = getschool();
	school s1(getschool());
	school s2(std::move(s1));
	cout << "��һ�����" << endl;

}