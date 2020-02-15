#include<iostream>
using namespace std;

//模板参数包  递归拆包
//print的功能，传入任意多个参数，全输出到屏幕上
/*void Lprint(int *f){
	cout << f << endl;
	Lprint();
}
void Lprint(const char* f, int* d){
	cout << f << endl;
	Lprint(d);
}
void Lprint(int f,const char* d1,int *d2){
	cout << f << endl;
	Lprint(d1,d2);
}
void  Lprint(double f, int d1, const char* d2,int *d3){
	cout << f << endl;
	Lprint(d1,d2,d3);
}
void Lprint(int f,double d1,int d2,const char* d3,int *d4){
	cout << f << endl;
	Lprint(d1,d2,d3,d4);
}*/
//递归到没有参数的时候 就会调用下面的这个无参函数
void Lprint(){
	cout << "递归拆包终结" << endl;
}
template<class T, class... args> void Lprint(T f, args... d){
	cout << f << endl;
	Lprint(d...);
}
//代码膨胀，模板写代码，根据调用的不同，他会推导出完整版本的普通代码。
int main()
{
	int a = 5;
	Lprint(2,3.0,5,"123",&a);
	cout << "运行结束" << endl;
}