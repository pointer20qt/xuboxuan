#include<iostream>
#include<time.h>
using namespace std;
void run(){
	int a = 50, b = 70;
	int p = rand() % a;//rand����[0,a)����
	int p2 = rand() % (b - a) + a;//rand����[a,b)����
	double p3 = ((double)rand()) / RAND_MAX + rand() % (b-a)+a;//����a~b�����С��
	cout << p << endl;
	cout << p2 << endl;
	cout << p3 << endl;
}
bool probaility1(int n){//����0��100���������������жϳɹ�,�ɹ�����true
	int p = rand() % 100;//rand()���(0��RAND_MAX)����ֲ��������
	if (p < n){
		return true;
	}
	else{
		return false;
	}
}
bool probaility2(double n){//����0��1��double���������жϳɹ����ɹ�����ture��
	double p =((double)rand())/RAND_MAX;//����һ��0~1�����С��double
	if (p < n ){
		return true;
	}
	else{
		return false;
	}
}
int main()
{
	srand(time(0));//time(0)��ô�19701��1�յ����ڵ�����
	int t = 0, f = 0;
	for (int i = 0; i < 100;i++){//���ٸ����»ᱩ��
		if (probaility2(0.06)){
			cout << "����" << endl;
			t++;
		}
		else{
			//cout << "û����" << endl;
			f++;
		}
	}
	cout << t << "��" << f << endl;
	run();
	return 0;
}
