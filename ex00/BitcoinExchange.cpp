#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& copy)
{
    *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& copy)
{
    (void) copy;
    return (*this);
}

void BitcoinExchange::fileCsv(std::string const& nameFile)
{
    //Ouverture fichier
    std::ifstream file(nameFile.c_str());
    std::string line;

    //Skipper la premiere ligne
    std::getline(file, line);

    //Lire chaque ligne et inserer les donnees dans la map
    while (std::getline(file, line))
       parseAndInsert(line);
}

//Recuperer les informations de date et de valeur dans la ligne et l'ajouter dans la map
void BitcoinExchange::parseAndInsert(std::string const& line)
{
    std::string year = line.substr(0, 4);
    std::string month = line.substr(5, 2);
    std::string day = line.substr(8, 2);
    std::string date = year + month + day;
    std::string value = line.substr(11, (line.length() - 1));

    int dateFinal = std::atoi(date.c_str());
    long double valueNum = std::atof(value.c_str());

    data.insert(std::pair<int, float>(dateFinal, valueNum));
}


void BitcoinExchange::check(std::string const& nameInput)
{
    fileCsv("data.csv");
    
    std::ifstream file(nameInput.c_str());
    std::string line;

    std::getline(file, line);

    while(std::getline(file, line))
        processLine(line);
}

void BitcoinExchange::processLine(std::string const& line)
{
    //Recuperation des infos de la date 
    _year = line.substr(0, 4);
    _month = line.substr(5, 2);
    _day = line.substr(8, 2);
    _date = _year + _month + _day;
    
    //Verification si il y a une valeur et qu'elle soit valide
    if (line.length() > 13 && line.length() < 24)
    {
        _value = line.substr(13, (line.length() - 1));
        float valueFloat = std::atof(_value.c_str());
        if (isvalidValue(valueFloat) == 1)
        {
            if (checkValidDate() == 1)
                std::cout << line.substr(0, 10) << std::endl;
            else
                checkAll(line);
        }
    }
    else if (checkValidDate() == 1)
        std::cout << line.substr(0, 10) << std::endl;
    else
        std::cerr << "Error : no value" << std::endl;
}

//Verification de la valeur
int BitcoinExchange::isvalidValue(float value)
{
    if (value < 0)
    {
        std::cerr << "Error : Value doesn't be negative" << std::endl;
        return (-1);
    }
    else if (value > 1000)
    {
        std::cerr << "Error : Value is too high" << std::endl;
        return (-1);
    }
    return (1);
}

//Verification de la date
int BitcoinExchange::checkValidDate()
{
    int year = std::atoi(_year.c_str());
    int month = std::atoi(_month.c_str());
    int day = std::atoi(_day.c_str());

    if (year < 2009) 
    {
        std::cerr << "Error : invalid date (year is too old) => ";
        return 1;
    } else if (year > 2023 || (year == 2023 && (month > 11 || (month == 11 && day > 2)))) 
    {
        std::cerr << "Error : invalid date (date is too recent) => ";
        return 1;
    } else if (month < 1 || month > 12 || day < 1 || day > 31) 
    {
        std::cerr << "Error : invalid date (date doesn't exist) => ";
        return 1;
    }
    return 0;
}

//Verification si on tombe sur la date et resultat
void BitcoinExchange::checkAll(std::string const& line)
{
    int dateText = std::atoi(_date.c_str());
    float valueText = std::atof(_value.c_str());

    std::map<int, float>::iterator it = data.begin();
    std::map<int, float>::iterator ite = data.end();

    while (it != ite) 
    {
        //La date est trouve
        if (dateText == it->first) 
        {
            float value = valueText * it->second;
            std::cout << line.substr(0, 10);
            std::cout << " => " << _value << " = " << std::fixed << std::setprecision(2) << value << std::endl;
            break;
        }
        //On pointe l'iterateur sur la date precedente
        else if (dateText < it->first) 
        {
            --it;
            float value = valueText * it->second;
            std::cout << line.substr(0, 10);
            std::cout << " => " << _value << " = " << std::fixed << std::setprecision(2) << value << std::endl;
            break;
        }
        ++it;
    }
}