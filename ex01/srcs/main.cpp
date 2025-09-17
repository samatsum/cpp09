#include "../includes/RPN.hpp"

/* ************************************************************************** */
int main(int argc, char **argv)
{
    if (argc < 2)
        std::cout << "Please enter a RPN expression" << std::endl;
    else if (argc > 2)
        std::cout << "too many arguments" << std::endl;
    else
    {
        RPN exp;
        exp.argvTostring(argv);
    }
}

