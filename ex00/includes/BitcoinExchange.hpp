#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <cstdlib>
# include <string>
# include <ctime>
# include <cstring> 

class BitcoinExchange
{
    private:
        std::map<std::string, float> database;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& in);
        
        void readDataCsv();

        void readParse(char *argv);
        bool checkDate(std::string date);
        float checkValue(std::string value);
        void findCalc(std::string date, float value);
};



#endif