#include<iostream>
#include<vector>
#include<string>
#include<initializer_list>
#include<assert.h>
#define static assert(sizeof(int) != 32, "Inappropriate int size");
using namespace std;
class vec{
	//int *obj;
	std::vector<int> arr;
public:
	vec(std::initializer_list<int> arr):arr(arr){	
		arr.size();//�ж��ٸ�Ԫ��
		arr.begin();//ͷָ��
		arr.end();//ĩָ��
		cout << "��ʼ�������б���" << endl;
		/*for(int i=0;i<arr.size();i++){
			cout<<"��"<<i<<"/t"<<*(arr.begin()+i)<<endl;
		}*/
		/*for(auto i=arr.begin();i!=arr.end();i++)
		{
			cout<< *i <<endl;
		}*/
		/*obj = new int[arr.size()];
		for (int i = 0; i < arr.size(); i++)
		{
			obj[i] = *(arr.begin() + i);
		}*/
	}
	vec(int a){
		cout << "����������" << endl;
	}
	vec(int a,int b,int c){
		cout << "���������" << endl;
	}
	int & operator[](unsigned int index){
		//return obj[index];
		assert(index >= 0 && index < arr.size());
		return arr[index];
	}
};
int main(){
	//std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7 };
	vec v{ 1, 2, 3, 4, 5, 6, 7 };
	cout << v[5] << endl;
	cout << v[4] << endl;
	vec tem{ 1, 2, 3 };
	cout << tem.operator[](1)<<endl;
	cout << v.operator[](2) << endl;
	v.operator[](2) = 10;
	cout << v.operator[](2) << endl;
	cout << v[-1] << endl;
	//vec tem{ 1, 2, 3 };
	//vec tem(1, 2, 3);*/
}