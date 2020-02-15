#include<iostream>
using namespace std;

//类模板 函数模板
/*template<int d,class T1, class T2,class T3> T1 Xmax(T1 a, T2 b,T3 c){
	cout << "常数模板推导函数" << endl;
	int arr[d];
	cout << d << endl;
	return a > c ? a : c;
}
template<class T1,class T2> T1 Xmax(T1 a, T2 b){
	cout << "多模板推导函数" << endl;
	return a > b ? a : b;
}
template<typename T> T Xmax(T a, T b){//class和typename一样的效果
	cout << "单模板推导函数" << endl;
	return a > b ? a : b;
}
int Xmax(int a, int b){
	cout << "int版本函数" << endl;
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
		cout << "构造函数" << endl;
	}
	A(const A& other){
		p = new char[100];
		value = other.value;
		cout << "拷贝构造A" << endl;
	}
	//重载某一个类型 将对象重载为一个类型 通过返回值
	operator int(){
		cout << "A转化为int" << endl;
		return value;
	}
	~A(){
		cout << "析构了" << endl;
		delete p;
	}
	A& operator=(const A &other){
		delete p;
		p = new char[100];
		value = other.value;
		return *this;
	}
};
void Xswap(A &a, A &b){//a里是a的p b里是b的p
	A tem = a;//tem里是tem的p
	a.operator=(b);//复制赋值函数 a里是b的p
	b.operator=(tem);//b里是tem的p
}
int main()
{
	A a(50), b(25);
	Xswap(a, b);
	/*int x1 = 5, x2 = 8;
	double d1 = 2.5, d2 = 9.5;
	//显式推导
	cout << Xmax<5, double,int>(x2,x1,d2) << endl;
	cout << Xmax<2>(x1,x2,d2) << endl;
	cout << Xmax<int>(x1, d2) << endl;
	cout << Xmax<int,short>(x1, d2) << endl;
	//隐式推导
	cout << Xmax(x1, d1) << endl;
	cout << Xmax(d1, d2) << endl;
	cout << Xmax(x1, x2) << endl;
	//显式指定推导 必须使用模板推导的函数，不能使用非模板函数
	cout << Xmax<>(x1, x2) << endl;
	cout << Xmax<>(x1, d1) << endl;*/
	int d = a;
	int x1 = 5, x2 = 2;
	double d1 = 2.5, d2 = 3.6;
	Xswap(x1, x2);
	Xswap(d1, d2);
	cout << x1 << "int类型交换了" << x2 << endl;
	cout << d1 << "double类型交换了" << d2 << endl;
	cout << a << "自定义类型交换了" << b << endl;
	cout << "程序结束" << endl;
}