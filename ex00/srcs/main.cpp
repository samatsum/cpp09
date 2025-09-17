#include "../includes/BitcoinExchange.hpp"

//今回のex00ではmapコンテナを使うよー。以後の課題でmap禁止！！！！
//2011-01-03 | 3 -> 2021/01/03に、私は３枚のbitcoinを持っていました。そのときの価格は……と、いう意味。
/* ************************************************************************** */
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        BitcoinExchange test;
        test.readDataCsv();
        test.readParse(argv[1]);
    }
    else
        std::cout << "ERROR: argc is not 2" << std::endl;
}
