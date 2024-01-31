#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <stdlib.h>

class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe const& copy);
        PmergeMe& operator=(PmergeMe const& copy);

        PmergeMe(const std::vector<int>& inputSequence) : sequence(inputSequence.begin(), inputSequence.end()), sequenceList(inputSequence.begin(), inputSequence.end()) {}

        void mergeSortVector();

        void mergeSortList();

        void printUnsortedSequence() const;

        void printSortedSequenceVector() const;

        void printSortedSequenceList() const;

        void printTimeUsedVector(clock_t startTime) const;

        void printTimeUsedList(clock_t startTime) const;
        

    private:
        std::vector<int> sequence;
        std::list<int> sequenceList;

        //template<typename Container>
        //void printSequence(const Container& container) const;

        template <typename Iterator>
        void mergeSortVectorHelper(Iterator begin, Iterator end);
};

#endif