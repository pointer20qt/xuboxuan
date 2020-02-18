#include "weak_ptr.h"
#include<iostream>
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
class node{
public:
	//X_sharedPtr<node> pre;
	//X_sharedPtr<node> next;
	X_weakPtr<node> pre;
	X_weakPtr<node> next;
	~node(){
		cout << "节点已析构" << endl;
	}
};
void test(std::string s){//编译器自动优化
	cout << "自动将char*转化为const string" << endl;
}
void run(){
	char* t = "154646";
	test(t);
	X_sharedPtr<node> node1 = { new node };
	X_sharedPtr<node> node2 = (new node);
	cout << node1->next.use_count() << endl;
	//编译器自动优化 找一个可以把shared_ptr类型的转换为weak_ptr类型的构造函数再走移动赋值 节省空间
	node1->next=node2;//(X_weakPtr<node>(node2))临时对象 
	node2->pre.operator=(node1);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
}
int main(){
	run();
	system("pause");
}