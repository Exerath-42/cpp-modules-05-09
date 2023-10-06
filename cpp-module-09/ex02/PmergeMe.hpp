#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <list>
#include <deque>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <ctime>


class PmergeMe
{

    private:

        std::deque<int>  deque;
        std::list<int>   list;

    public:

        PmergeMe();
        PmergeMe(int argc, char **argv);
        PmergeMe(const PmergeMe &PmergeMe);
        PmergeMe& operator= (const PmergeMe &rhs);
        ~PmergeMe();
        template <typename T>
        void printContent(const T& cont);
        void SortDeque(std::deque<int>& deque);
        void SortList(std::list<int>& list);


};

#endif