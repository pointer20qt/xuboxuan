#include<iostream>
using namespace std;

//ģ�������  �ݹ���
//print�Ĺ��ܣ�����������������ȫ�������Ļ��
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
//�ݹ鵽û�в�����ʱ�� �ͻ�������������޲κ���
void Lprint(){
	cout << "�ݹ����ս�" << endl;
}
template<class T, class... args> void Lprint(T f, args... d){
	cout << f << endl;
	Lprint(d...);
}
//�������ͣ�ģ��д���룬���ݵ��õĲ�ͬ�������Ƶ��������汾����ͨ���롣
int main()
{
	int a = 5;
	Lprint(2,3.0,5,"123",&a);
	cout << "���н���" << endl;
}