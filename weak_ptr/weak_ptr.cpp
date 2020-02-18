#include "weak_ptr.h"
#include<iostream>
#include<memory>
using namespace std;

class tool{
public:
	int value = 0;
	tool(){
		cout << "tool������" << endl;
	}
	~tool(){
		cout << "tool������" << endl;
	}
};
class node{
public:
	//X_sharedPtr<node> pre;
	//X_sharedPtr<node> next;
	X_weakPtr<node> pre;
	X_weakPtr<node> next;
	~node(){
		cout << "�ڵ�������" << endl;
	}
};
void test(std::string s){//�������Զ��Ż�
	cout << "�Զ���char*ת��Ϊconst string" << endl;
}
void run(){
	char* t = "154646";
	test(t);
	X_sharedPtr<node> node1 = { new node };
	X_sharedPtr<node> node2 = (new node);
	cout << node1->next.use_count() << endl;
	//�������Զ��Ż� ��һ�����԰�shared_ptr���͵�ת��Ϊweak_ptr���͵Ĺ��캯�������ƶ���ֵ ��ʡ�ռ�
	node1->next=node2;//(X_weakPtr<node>(node2))��ʱ���� 
	node2->pre.operator=(node1);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
}
int main(){
	run();
	system("pause");
}