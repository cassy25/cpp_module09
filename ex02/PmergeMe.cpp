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
    return *this;
}


// Tri par fusion-insertion (Ford-Johnson) pour le premier conteneur (vector)
void PmergeMe::mergeSortVector() 
{
    if (sequence.size() <= 1)
    {
        return ;
    }

    mergeSortVectorHelper(0, sequence.size());
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
    for (int num : sequence) 
    {
        std::cout << " " << num;
    }
    std::cout << std::endl;
}

// Affiche la séquence entière positive triée
void PmergeMe::printSortedSequenceVector() const 
{
    std::cout << "Sorted Sequence: ";
    for (int num : sequence) 
    {
        std::cout << " " << num;
    }
    std::cout << std::endl;
}

void PmergeMe::printSortedSequenceList() const 
{
    std::cout << "Sorted Sequence (List):";
    for (int num : sequenceList) 
    {
        std::cout << " " << num;
    }
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

void PmergeMe::mergeSortVectorHelper(int left, int right) 
{
     if (right - left > 1) {
            size_t middle = left + (right - left) / 2;
            mergeSortVectorHelper(left, middle);
            mergeSortVectorHelper(middle, right);

            std::inplace_merge(sequence.begin() + left, sequence.begin() + middle, sequence.begin() + right);
        }
}
