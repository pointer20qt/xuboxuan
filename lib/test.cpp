#include "test.h"
#include<iostream>

test::test()
{
	std::cout << "������test" << std::endl;
}


test::~test()
{
	std::cout << "������test" << std::endl;
}
void test::run()
{
	std::cout << "������run����" << std::endl;
}