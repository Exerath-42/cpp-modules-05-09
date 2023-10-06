#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		list.push_back(atoi(argv[i]));
		deque.push_back(atoi(argv[i]));
	}
	std::cout << "list before sort: ";
	printContent(list);
	std::cout << "deque before sort: ";
	printContent(deque);

	clock_t start = clock();
    SortDeque(deque);
    clock_t end = clock();
    double time1 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

	start = clock();
	SortList(list);
    end = clock();
    double time2 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

	std::cout << "list after sort: ";
	printContent(list);
	std::cout << "deque after sort: ";
	printContent(deque);
    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << list.size() << " elements with std::list container: " << time2 << " us" << std::endl;
    if (deque == std::deque<int>(list.begin(), list.end()))
        std::cout << "Sorted elements match" << std::endl;
    else
        std::cout << "Sorted elements do not match" << std::endl;	
}

void PmergeMe::SortDeque(std::deque<int>& arr)
{
    std::deque<int>::iterator it1, it2;
    for (it1 = arr.begin() + 1; it1 != arr.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != arr.begin() && *(it2-1) > temp)
        {
            *it2 = *(it2-1);
            --it2;
        }
        *it2 = temp;
    }
}

void PmergeMe::SortList(std::list<int>& arr)
{
	std::list<int>::iterator it;
	for (it = arr.begin(); it != arr.end(); ++it)
	{
		int key = *it;
		std::list<int>::iterator j = it;
		
		while (j != arr.begin()) {
			std::list<int>::iterator prev = j;
			--prev;
			
			if (*prev > key) {
				*j = *prev;
				--j;
			}
			else {
				break;
			}
		}
		*j = key;
	}
}

PmergeMe::PmergeMe(const PmergeMe &pmergeme)
{
	*this = pmergeme;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	this->list = rhs.list;
	this->deque = rhs.deque;
	return (*this);
}

template <typename T>
void PmergeMe::printContent(const T& cont)
{
    typename T::const_iterator it;
    for (it = cont.begin(); it != cont.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{
}