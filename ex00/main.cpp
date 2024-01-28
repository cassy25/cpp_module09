#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Only one parameter !" << std::endl;
        return 1;
    }
    BitcoinExchange bitcoin;

    //bitcoin.fileCsv("data.csv");
    bitcoin.check(argv[1]);
    return 0;
}