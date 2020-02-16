#include<iostream>
#include"smart_pointer.h"
#include<memory>
using namespace std;
class tool{
	
public:
	int value = 0;
	tool(){
		cout << "tool构造了" << endl;
	}
	~tool(){
		cout << "tool析构了" << endl;
	}
};

int main(){
	//智能指针，一种对象，能够管理一个对象释放
	/*auto_ptr<tool> ptr(new tool);
	auto_ptr<tool> ptr2(ptr);
	auto_ptr<tool> ptr3;*/
	X_autoPtr<tool> ptr(new tool);
	X_autoPtr<tool> ptr2(ptr);
	X_autoPtr<tool> ptr3;
	ptr3 = ptr2;
	return 0;
}