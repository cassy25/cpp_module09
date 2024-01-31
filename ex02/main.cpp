#include "PmergeMe.hpp"

int main(int argc, char* argv[]) 
{
    if (argc < 2) 
    {
        std::cerr << "Error : minimum one argument"  << std::endl;
        return 1;
    }

    std::vector<int> inputSequence;

    std::cout << "Input Sequence (as interpreted):";
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num == 0 && argv[i][0] != '0') {
            std::cerr << "Invalid argument: " << argv[i] << std::endl;
            return 1;
        }
        std::cout << " " << num;
        inputSequence.push_back(num);
    }
    std::cout << std::endl;

    PmergeMe myPmergeMe(inputSequence);

    myPmergeMe.printUnsortedSequence();

    clock_t startTime = clock();
    myPmergeMe.mergeSortVector();
    myPmergeMe.printSortedSequenceVector();
    myPmergeMe.printTimeUsedVector(startTime);

    startTime = clock();
    myPmergeMe.mergeSortList();
    myPmergeMe.printSortedSequenceList();
    myPmergeMe.printTimeUsedList(startTime);

    return 0;
}
