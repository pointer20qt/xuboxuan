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
		// BigBox��Box����Ԫ�࣬������ֱ�ӷ���Box����κγ�Ա
		box.setWidth(width);
		cout << "���ӵĿ��: " << box.width << endl;
	}
};
void printWidth(Box box)
{
	cout << "���ӵĿ��: " << box.width << endl;
}
// �����������
int main()
{
	b box;
	BigBox big;
	// ʹ�ó�Ա�������ÿ��
	box.setWidth(10.0);
	// ʹ����Ԫ����������
	printWidth(box);
	// ʹ����Ԫ���еķ������ÿ��
	big.Print(20, box);
	return 0;
}