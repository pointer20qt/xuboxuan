#include<iostream>
using namespace std;
//��̬ ������д ������ ��������
class A{
protected:
	int k;
public:
	A(){ 
		k = 3;
		cout << "A������" << endl;
	}
	virtual int  getValue(){ return k; }
	void a(int x){
		cout << "A::a" << x << endl;
	}
	virtual ~A(){
		cout << "A������" << endl;
	}
};

class B :public A{
public:
	B(){
		cout << "B������" << endl;
	}
	virtual int getValue(){ return k * 2; }
	void a(int x){
		cout << "B::b" << x <<endl;
	}
	~B(){
		cout << "B������" << endl;
	}
};
void F(A *p){
	cout << p->getValue() << endl;
}
int main(){
	A* a = new B;//�ø���ָ��ָ���������
	cout << endl;
	A* a1 = new A;
	cout << endl;
	B* b1 = new B;
	cout << sizeof(a) << endl;
	cout << sizeof(*a) << endl;
	F(a);	
	F(a1);
	F(b1);
	a->a(1);
	a1->a(1);
	b1->a(1);
	delete a;
	cout << endl;
	delete a1;
	cout << endl;
	delete b1;
	return 0;
}

