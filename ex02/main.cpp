#include "PmergeMe.hpp"

int main(int argc, char* argv[]) 
{
    if (argc < 2) 
    {
        std::cerr << "Usage: " << argv[0] << " <integer_sequence>" << std::endl;
        return 1;
    }

    std::vector<int> inputSequence;

    std::cout << "Input Sequence (as interpreted):";
    for (int i = 1; i < argc; ++i) 
    {
        try 
        {
            size_t pos;
            int num = std::stoi(argv[i], &pos);
            if (pos != strlen(argv[i])) 
            {
                throw std::invalid_argument("Invalid argument: " + std::string(argv[i]));
            }
            std::cout << " " << num;
            inputSequence.push_back(num);
        } catch (std::invalid_argument& e) 
        {
            std::cerr << e.what() << std::endl;
            return 1;
        }
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
