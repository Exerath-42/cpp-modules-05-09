#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "_________________My tests_________________" << std::endl;

	MutantStack<float> f_mstack;


	std::cout << "f_mstack contains:" << std::endl;
	for (int i=0; i < 35; i ++)
	{
		f_mstack.push(i*3);
		std::cout << "[" << i << "]	" <<f_mstack.top() << std::endl;
	}

	std::cout << std::endl << "Let's use iterators:" << std::endl;
	MutantStack<float>::iterator it_begin = f_mstack.begin();
	MutantStack<float>::iterator it_end = f_mstack.end();

	while (it_begin != it_end)
	{
		std::cout << *it_begin << std::endl;
		++it_begin;
	}

	std::cout << std::endl << "std::stack functionality check:" << std::endl;
	std::cout << "empty(): " << f_mstack.empty() << std::endl;
	std::cout << "size(): " << f_mstack.size() << std::endl << std::endl;

	return 0;
}
