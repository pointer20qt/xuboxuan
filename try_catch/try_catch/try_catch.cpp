#include<iostream>
#include<vector>
using namespace std;

int main()
{
	try{
		vector<int> res{ 1, 2, 3, 4, 5 };
		for (int i = 0; i <5; i++)//i<6ʱ��Ჶ��our_of_range�е��쳣
		{
			cout << res.at(i) << endl;
		}
		throw 8;
		cout << "��ӡ���" << endl;
	}
	catch (int test)
	{
		cout << "�����쳣" << " "<<test << endl;
	}
	catch (out_of_range &e){
		cout << "����Խ���쳣" << endl;
	}
	catch (exception &d)
	{
		cout << d.what() << endl;
	}
	catch (...){
		cout << "�����쳣" << endl;
	}
	try{
		while (1)
		{
			system("pause");
			//auto p=malloc(1024 * 1024 * 100*10��;
			auto s = new(nothrow) int[1024 * 1024 * 25 * 10];
			cout << s << endl;
		}
	}
	catch (bad_alloc &b)
	{
		cout << b.what() << endl;
	}
	cout << "�������һ��" << endl;
	return 0;
}