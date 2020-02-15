#include<iostream>
#include<vector>
using namespace std;
//栈，先入后出， push,pop,top，size，empty
template<class T> class L_stack{
	std::vector<T> arr;
	public:
	void push(T& obj){//可以接受地址
		arr.push_back(obj);
	}
	void push(T&& obj){//可以接收常量 
		arr.push_back(obj);
	}
	void pop(){
		arr.pop_back();
	}
	T& top(){
		return arr.back();
	}
	size_t size(){
		return arr.size();
	}
	bool empty(){
		return arr.empty();
	}
};
int main(){
	L_stack<int>s;
	s.push(10);
	for (int i = 0; i < 8; i+=2){
		s.push(i);
	}
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << s.size() << endl;
}

