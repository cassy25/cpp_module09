#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const& copy);
        BitcoinExchange& operator=(BitcoinExchange const& copy);
        void fileCsv(std::string const& nameCsv);
        void check(std::string const& nameInput);
        //std::string findNearestDate(std::string const& targetDate);
        int checkValidDate();
        void parseAndInsert(std::string const& line);
        void processLine(std::string const& line);
        int isvalidValue(float value);
        void checkAll();
    private:
        std::map<int, float> data;
        std::string _year;
        std::string _month;
        std::string _day;
        std::string _date;
        std::string _value;


};

#endif