#include<iostream>
#include"test.h"
#include<vector>
using namespace std;

#pragma comment (lib,"testLib.lib") 
int main()
{
	std::cout << "��ʼ����" << std::endl;
	test t;
	t.run();
}