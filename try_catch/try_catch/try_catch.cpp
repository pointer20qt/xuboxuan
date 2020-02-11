#include<iostream>
#include<vector>
using namespace std;

int main()
{
	try{
		vector<int> res{ 1, 2, 3, 4, 5 };
		for (int i = 0; i <5; i++)//i<6时候会捕获our_of_range中的异常
		{
			cout << res.at(i) << endl;
		}
		throw 8;
		cout << "打印完成" << endl;
	}
	catch (int test)
	{
		cout << "捕获异常" << " "<<test << endl;
	}
	catch (out_of_range &e){
		cout << "数组越界异常" << endl;
	}
	catch (exception &d)
	{
		cout << d.what() << endl;
	}
	catch (...){
		cout << "捕获异常" << endl;
	}
	try{
		while (1)
		{
			system("pause");
			//auto p=malloc(1024 * 1024 * 100*10）;
			auto s = new(nothrow) int[1024 * 1024 * 25 * 10];
			cout << s << endl;
		}
	}
	catch (bad_alloc &b)
	{
		cout << b.what() << endl;
	}
	cout << "程序最后一句" << endl;
	return 0;
}