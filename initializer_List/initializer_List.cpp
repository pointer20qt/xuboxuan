#include<iostream>
#include<vector>
#include<string>
#include<initializer_list>
using namespace std;
class vec{
	int *obj;
public:
	vec(std::initializer_list<int> arr){	
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
		obj = new int[arr.size()];
		for (int i = 0; i < arr.size(); i++)
		{
			obj[i] = *(arr.begin() + i);
		}
	}
	vec(int a){
		cout << "����������" << endl;
	}
	vec(int a,int b,int c){
		cout << "���������" << endl;
	}
	int & operator[](unsigned int index){
		return obj[index];
	}
};
int main(){
	//int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	vec v({ 1, 2, 3, 4, 5, 6, 7 });
	vec tem{ 1, 2, 3 };
	//vec v={1,2,3,4,5,6,7};
	cout << v.operator[](2) << endl;
	v.operator[](2) = 10;
	cout << v.operator[](2) << endl;
	//vec tem{ 1, 2, 3 };
	//vec tem(1, 2, 3);
}