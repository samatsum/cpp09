#include "../includes/BitcoinExchange.hpp"

/* ************************************************************************** */
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        BitcoinExchange test;
        test.readDb();
        test.readParse(argv[1]);
    }
    else
        std::cout << "ERROR: argc is not 2" << std::endl;
}
