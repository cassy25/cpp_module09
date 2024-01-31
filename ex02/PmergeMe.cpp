#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(PmergeMe const& copy)
{
    *this = copy;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& copy)
{
    sequence = copy.sequence;
    sequenceList = copy.sequenceList;

    return *this;
}


// Tri par fusion-insertion (Ford-Johnson) pour le premier conteneur (vector)
void PmergeMe::mergeSortVector() 
{
    if (sequence.size() <= 1)
    {
        return ;
    }

    mergeSortVectorHelper(sequence.begin(), sequence.end());
}

// Tri par fusion-insertion (Ford-Johnson) pour le deuxième conteneur (list)
void PmergeMe::mergeSortList() 
{
    sequenceList.sort();
}

// Affiche la séquence entière positive non triée
void PmergeMe::printUnsortedSequence() const 
{
    std::cout << "Unsorted Sequence: ";
    for (std::vector<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it) 
        std::cout << " " << *it;
    std::cout << std::endl;
}

// Affiche la séquence entière positive triée
void PmergeMe::printSortedSequenceVector() const 
{
    std::cout << "Sorted Sequence: ";
    for (std::vector<int>::const_iterator it = sequence.begin(); it != sequence.end(); ++it) 
        std::cout << " " << *it;
    std::cout << std::endl;
}

void PmergeMe::printSortedSequenceList() const 
{
    std::cout << "Sorted Sequence (List):";
    for (std::list<int>::const_iterator it = sequenceList.begin(); it != sequenceList.end(); ++it) 
        std::cout << " " << *it;
    std::cout << std::endl;
}

// Affiche le temps utilisé par l'algorithme pour le premier conteneur
void PmergeMe::printTimeUsedVector(clock_t startTime) const 
{
    clock_t endTime = clock();
    double elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
    double elapsedTimeMicros = elapsedTime * 1e6;  // Convertir en microsecondes
    std::cout << "Time used for vector: " << std::fixed << std::setprecision(2) << elapsedTimeMicros << " µs." << std::endl;
}

// Affiche le temps utilisé par l'algorithme pour le deuxième conteneur
void PmergeMe::printTimeUsedList(clock_t startTime) const 
{
    clock_t endTime = clock();
    double elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
    double elapsedTimeMicros = elapsedTime * 1e6;  // Convertir en microsecondes
    std::cout << "Time used for list: " << std::fixed << std::setprecision(2) << elapsedTimeMicros << " µs." << std::endl;
}

template <typename Iterator>
void PmergeMe::mergeSortVectorHelper(Iterator begin, Iterator end) 
{
     if (end - begin > 1) {
            Iterator middle = begin + (end - begin) / 2;
            mergeSortVectorHelper(begin, middle);
            mergeSortVectorHelper(middle, end);
            std::inplace_merge(begin, middle, end);
        }
}