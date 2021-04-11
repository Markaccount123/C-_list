#include"list.h"
#include<iostream>
//using namespace std;

void print_list(const wzy::list<int>& lt)
{
	wzy::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}
void test_list()
{
	wzy::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	wzy::list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	for (auto e : lt)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;


}
int main()
{
	test_list();
	return 0;
}