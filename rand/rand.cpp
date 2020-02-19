#include<iostream>
#include<time.h>
using namespace std;
void run(){
	int a = 50, b = 70;
	int p = rand() % a;//rand生成[0,a)的数
	int p2 = rand() % (b - a) + a;//rand生成[a,b)的数
	double p3 = ((double)rand()) / RAND_MAX + rand() % (b-a)+a;//生成a~b的随机小数
	cout << p << endl;
	cout << p2 << endl;
	cout << p3 << endl;
}
bool probaility1(int n){//传入0到100的整数，概率性判断成功,成功返回true
	int p = rand() % 100;//rand()获得(0～RAND_MAX)均与分布的随机数
	if (p < n){
		return true;
	}
	else{
		return false;
	}
}
bool probaility2(double n){//传入0到1的double，概率性判断成功，成功返回ture。
	double p =((double)rand())/RAND_MAX;//生成一个0~1的随机小数double
	if (p < n ){
		return true;
	}
	else{
		return false;
	}
}
int main()
{
	srand(time(0));//time(0)获得从19701月1日到现在的秒数
	int t = 0, f = 0;
	for (int i = 0; i < 100;i++){//多少概率下会暴击
		if (probaility2(0.06)){
			cout << "暴击" << endl;
			t++;
		}
		else{
			//cout << "没暴击" << endl;
			f++;
		}
	}
	cout << t << "和" << f << endl;
	run();
	return 0;
}
