#include "../includes/BitcoinExchange.hpp"

/* ************************************************************************** */
BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
   this->database = src.database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
    this->database = rhs.database;
    return (*this);    
}

/* ************************************************************************** */
void BitcoinExchange::readDataCsv()
{
    std::ifstream   db("data.csv");
    std::string     data;

    while(std::getline(db, data))
    {
        if (data != "date,exchange_rate")
        { 
            size_t comma_position = data.find(",");
            std::string date_string = data.substr(0, comma_position);
            std::string price_string = data.substr(comma_position + 1);
            float exchange_rate = std::atof(price_string.c_str());
            // ここのdata_stringは別にインデックスとして使っていない。mapの「キー」として使ってる。
            this->database[date_string] = exchange_rate;//database["2011-01-03"]のfloat部分にexchange_rateを入れろ…的な。
        }
    }
}

/* ************************************************************************** */
//文字列として受け取った日付が、「実際」に存在する有効な日付かどうか（42月とか、42日とかはありえないじゃｙろ）
bool BitcoinExchange::checkDate(std::string date)
{
    int year,month,day;
    struct tm t_date;
    memset(&t_date, 0, sizeof(struct tm));
    if (date.length() != 10)//YYYY-MM-DDは必ず10文字
        return (false);
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return (false);
        }
        else
        {
            if (date[i] < '0' || date[i] > '9')
                return (false);
        }
    }

    year = atoi(date.substr(0, 4).c_str());
    month = atoi(date.substr(5,7).c_str());
    day = atoi(date.substr(8).c_str());
    
    t_date.tm_year = year - 1900;//tm_yearは1900年からの経過年数
    t_date.tm_mon = month - 1;//tm_monは0から始まる月番号
    t_date.tm_mday = day;

    time_t cal = mktime(&t_date);//実際に無効な日付を渡すと-1を返す
    if (cal == -1)
        return (false);
    if (t_date.tm_year != year - 1900 || t_date.tm_mon != month - 1 || t_date.tm_mday != day)
        return (false);
    return (true);
}

/* ************************************************************************** */
float BitcoinExchange::checkValue(std::string value)
{
    char* ptr;
    float val;

    val = strtof(value.c_str(), &ptr);

    if (value[0] == '.')
        return (-1.0);
    if (*ptr == '\0')
    {
        if (val < 0.0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            return(-2.0);
        }    
        else if (val > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            return (-2.0);
        }
        else
            return (val);
    }
    else
        return (-1.0);
    
}

/* ************************************************************************** */
// 2011-01-08: 0.5
// 2011-01-15: 0.8
//このとき、lower_bound("2011-01-10")は、「2011-01-15」のエントリを指すイテレータを返す。
//　→ lower_boundの返したイテレータを-1すると、「2011-01-08」になる。
void BitcoinExchange::findCalc(std::string date, float value)
{
    std::map<std::string, float>::iterator exact_match = this->database.find(date);
    
    if (exact_match != this->database.end())//endイテレータが返されてない＝＝ピッタシの日付見つけた！
    {
        std::cout << date << " => " << value << " = " << value * exact_match->second << std::endl;
        return;
    }

    std::map<std::string, float>::iterator it = this->database.lower_bound(date);
    if (it == this->database.begin())//一番古いデータより古いデータが指定された場合（イテレータは最も古いデータを指してる。）
    {
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;//とりあえず一番古いデータで。
    } else
    {
        --it;
        std::cout << date << " => " << value << " = " << value * it->second << std::endl;//指定したデータより一つ若いデータ！
    }
}

/* ************************************************************************** */
void BitcoinExchange::readParse(char *argv)
{
    std::ifstream inputFile(argv);
    std::string input;
    std::string date;
    float value;

    if (!inputFile.is_open())
        std::cout << "Error: could not open inputFile." << std::endl;
    while (std::getline(inputFile, input))
    {
        if (input.empty())
            continue;
        if (input != "date | value")
        {
            size_t pos = input.find("|");
            if (pos == std::string::npos || pos == 0 || pos == input.length() - 1)
            {
                std::cout << "Error: bad input => " << input << std::endl;
                continue;
            }
            date = input.substr(0, pos-1);
            if (!checkDate(date))
            {
                std::cout << "Error: bad input => " << input << std::endl;
                continue;
            }
            value = checkValue(input.substr(pos+2));
            if (value == -2.0)
                continue;
            if (value == -1.0)
            {
                std::cout << "Error: bad input => " << input << std::endl;
                continue; 
            }
            findCalc(date, value);
        }
    }
}
