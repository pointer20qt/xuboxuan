#include<iostream>
using namespace std;

//��ģ�� ����ģ��
/*template<int d,class T1, class T2,class T3> T1 Xmax(T1 a, T2 b,T3 c){
	cout << "����ģ���Ƶ�����" << endl;
	int arr[d];
	cout << d << endl;
	return a > c ? a : c;
}
template<class T1,class T2> T1 Xmax(T1 a, T2 b){
	cout << "��ģ���Ƶ�����" << endl;
	return a > b ? a : b;
}
template<typename T> T Xmax(T a, T b){//class��typenameһ����Ч��
	cout << "��ģ���Ƶ�����" << endl;
	return a > b ? a : b;
}
int Xmax(int a, int b){
	cout << "int�汾����" << endl;
	return a > b ? a : b;
}
A Xmax(A a, A b){
return a > b ? a : b;
}*/
template<class T> void Xswap(T &a, T &b){
	T tem = a;
	a = b; 
	b = tem;
}
class A{
public:
	int value = 2;
	char *p;
	A(int v){
		p = new char[100];
		value = v;
		cout << "���캯��" << endl;
	}
	A(const A& other){
		p = new char[100];
		value = other.value;
		cout << "��������A" << endl;
	}
	//����ĳһ������ ����������Ϊһ������ ͨ������ֵ
	operator int(){
		cout << "Aת��Ϊint" << endl;
		return value;
	}
	~A(){
		cout << "������" << endl;
		delete p;
	}
	A& operator=(const A &other){
		delete p;
		p = new char[100];
		value = other.value;
		return *this;
	}
};
void Xswap(A &a, A &b){//a����a��p b����b��p
	A tem = a;//tem����tem��p
	a.operator=(b);//���Ƹ�ֵ���� a����b��p
	b.operator=(tem);//b����tem��p
}
int main()
{
	A a(50), b(25);
	Xswap(a, b);
	/*int x1 = 5, x2 = 8;
	double d1 = 2.5, d2 = 9.5;
	//��ʽ�Ƶ�
	cout << Xmax<5, double,int>(x2,x1,d2) << endl;
	cout << Xmax<2>(x1,x2,d2) << endl;
	cout << Xmax<int>(x1, d2) << endl;
	cout << Xmax<int,short>(x1, d2) << endl;
	//��ʽ�Ƶ�
	cout << Xmax(x1, d1) << endl;
	cout << Xmax(d1, d2) << endl;
	cout << Xmax(x1, x2) << endl;
	//��ʽָ���Ƶ� ����ʹ��ģ���Ƶ��ĺ���������ʹ�÷�ģ�庯��
	cout << Xmax<>(x1, x2) << endl;
	cout << Xmax<>(x1, d1) << endl;*/
	int d = a;
	int x1 = 5, x2 = 2;
	double d1 = 2.5, d2 = 3.6;
	Xswap(x1, x2);
	Xswap(d1, d2);
	cout << x1 << "int���ͽ�����" << x2 << endl;
	cout << d1 << "double���ͽ�����" << d2 << endl;
	cout << a << "�Զ������ͽ�����" << b << endl;
	cout << "�������" << endl;
}